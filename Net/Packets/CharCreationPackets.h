//////////////////////////////////////////////////////////////////////////////
// This file is part of the LibreMaple MMORPG client                        //
// Copyright © 2015-2016 Daniel Allendorf, 2018-2019 LibreMaple Team        //
//                                                                          //
// This program is free software: you can redistribute it and/or modify     //
// it under the terms of the GNU Affero General Public License as           //
// published by the Free Software Foundation, either version 3 of the       //
// License, or (at your option) any later version.                          //
//                                                                          //
// This program is distributed in the hope that it will be useful,          //
// but WITHOUT ANY WARRANTY; without even the implied warranty of           //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            //
// GNU Affero General Public License for more details.                      //
//                                                                          //
// You should have received a copy of the GNU Affero General Public License //
// along with this program.  If not, see <https://www.gnu.org/licenses/>.   //
//////////////////////////////////////////////////////////////////////////////
#pragma once
#include "../OutPacket.h"
#include <tinyutf8/tinyutf8.h>

#include <string_view>

namespace jrc
{
//! Reserve a name for the character to be created.
//! Opcode: NAME_CHAR(21)
class NameCharPacket : public OutPacket
{
public:
    NameCharPacket(std::string_view name) : OutPacket{NAME_CHAR}
    {
        write_string(name);
    }
};

//! Requests creation of a character with the specified stats.
//! Opcode: CREATE_CHAR(22)
class CreateCharPacket : public OutPacket
{
public:
    CreateCharPacket(std::string_view name,
                     std::uint16_t job,
                     std::int32_t face,
                     std::int32_t hair,
                     std::uint8_t hairc,
                     std::uint8_t skin,
                     std::int32_t top,
                     std::int32_t bot,
                     std::int32_t shoes,
                     std::int32_t weapon,
                     bool female)
        : OutPacket{CREATE_CHAR}
    {
        write_string(name);
        write_int(job);
        write_int(face);
        write_int(hair);
        write_int(hairc);
        write_int(skin);
        write_int(top);
        write_int(bot);
        write_int(shoes);
        write_int(weapon);
        write_byte(female);
    }
};
} // namespace jrc
