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
#include "UINpcTalk.h"

#include "../../Net/Packets/NpcInteractionPackets.h"
#include "../Components/MapleButton.h"
#include "nlnx/node.hpp"
#include "nlnx/nx.hpp"

namespace jrc
{
UINpcTalk::UINpcTalk()
{
    nl::node src = nl::nx::ui["UIWindow2.img"]["UtilDlgEx"];

    top = src["t"];
    fill = src["c"];
    bottom = src["s"];
    nametag = src["bar"];

    buttons[OK] = std::make_unique<MapleButton>(src["BtOK"]);
    buttons[NEXT] = std::make_unique<MapleButton>(src["BtNext"]);
    buttons[PREV] = std::make_unique<MapleButton>(src["BtPrev"]);
    buttons[END] = std::make_unique<MapleButton>(src["BtClose"]);
    buttons[YES] = std::make_unique<MapleButton>(src["BtYes"]);
    buttons[NO] = std::make_unique<MapleButton>(src["BtNo"]);

    active = false;
}

void UINpcTalk::draw(float inter) const
{
    Point<std::int16_t> drawpos = position;
    top.draw(drawpos);
    drawpos.shift_y(top.height());
    fill.draw({drawpos, Point<std::int16_t>(0, vtile) * fill.height()});
    drawpos.shift_y(vtile * fill.height());
    bottom.draw(drawpos);

    UIElement::draw(inter);

    speaker.draw({position + Point<std::int16_t>(80, 100), true});
    nametag.draw(position + Point<std::int16_t>(25, 100));
    name.draw(position + Point<std::int16_t>(80, 99));
    text.draw(position
              + Point<std::int16_t>(
                  156, 16 + ((vtile * fill.height() - text.height()) / 2)));
}

Button::State UINpcTalk::button_pressed(std::uint16_t buttonid)
{
    switch (buttonid) {
    case END:
        NpcTalkMorePacket(type, 0).dispatch();
        active = false;
        break;
    }
    return Button::PRESSED;
}

void UINpcTalk::change_text(std::int32_t npc_id,
                            std::int8_t msg_type,
                            std::int16_t,
                            std::int8_t speaker_byte,
                            std::string&& tx)
{
    text = {Text::A12M, Text::LEFT, Text::DARKGREY, std::move(tx), 320};

    if (speaker_byte == 0) {
        std::string str_id = std::to_string(npc_id);
        name = {Text::A11M,
                Text::CENTER,
                Text::WHITE,
                tiny_utf8::utf8_string{
                    nl::nx::string["Npc.img"][str_id]["name"].get_string()}};

        str_id.insert(0, 7 - str_id.length(), '0');
        str_id += ".img";
        speaker = nl::nx::npc[str_id]["stand"]["0"];
    } else {
        speaker = {};
        name.change_text(u8"");
    }

    vtile = 8;
    height = vtile * fill.height();

    for (auto& button : buttons) {
        button.second->set_active(false);
        button.second->set_state(Button::NORMAL);
    }
    buttons[END]->set_position({20, height + 48});
    buttons[END]->set_active(true);
    switch (msg_type) {
    case 0:
        buttons[OK]->set_position({220, height + 48});
        buttons[OK]->set_active(true);
        break;
    }
    type = msg_type;

    position = {400 - top.width() / 2, 240 - height / 2};
    dimension = {top.width(), height + 120};
}
} // namespace jrc
