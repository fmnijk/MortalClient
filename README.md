# MortalClient: a continuation of a continuation of JourneyClient

[![GNU AGPL v3+](https://img.shields.io/badge/license-AGPL%20v3%2B-brightgreen.svg)](https://www.gnu.org/licenses/agpl-3.0.html)
[![C++17 standard](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B17)
[![clang++ version](https://img.shields.io/badge/clang%2B%2B-8.0.1+-dd66aa.svg)](http://clang.llvm.org/)
[![Global Maplestory version 83](https://img.shields.io/badge/Maplestory-GMS_v83-orange.svg)](https://en.wikipedia.org/wiki/MapleStory)

## JourneyClient

JourneyClient is a custom, made-from-scratch game client for
[Maplestory](https://en.wikipedia.org/wiki/MapleStory).
JourneyClient is written in [C++](https://en.wikipedia.org/wiki/C%2B%2B) and
was created by Daniel Allendorf in 2015.

The LibreMaple project aimed to make a version of Maplestory that is
[100% free and open](https://www.fsf.org/about/what-is-free-software) on both
the server and client sides, to preserve the freedom of its users and enable
creativity and collaboration around the game. As such, the LibreMaple project
took the JourneyClient as a starting point.

LibreMaple aimed also to make the client
[cross-platform](https://en.wikipedia.org/wiki/Cross-platform)
([GNU+Linux](https://en.wikipedia.org/wiki/Linux)/[macOS](https://en.wikipedia.org/wiki/MacOS)/[Windows NT](https://en.wikipedia.org/wiki/Windows_NT)/[FreeBSD](https://en.wikipedia.org/wiki/FreeBSD)/etc.)
as well, so decisions were and are made with a cross-platform mindset as well
as a free software one.

MortalClient continues the work of LibreMaple, taking it in a further direction
of rectifying the game's flaws for our future selves and future generations.

## Supported versions

The client is intended to be quasi-conformant with GMS version 83. For the UI
file (UI.nx), one from GMS version 154+ should be used.

[The corresponding server code is called MortalMS.](https://github.com/HypatiaOfAlexandria/MortalMS)

## How to compile/install

### [Unix-like systems](https://en.wikipedia.org/wiki/Unix-like) excluding macOS (GNU+Linux, FreeBSD, etc.) (may also work for Unix-like Windows subsystems like [Cygwin](https://en.wikipedia.org/wiki/Cygwin), [MinGW](https://en.wikipedia.org/wiki/MinGW), or [WSL](https://en.wikipedia.org/wiki/Windows_Subsystem_for_Linux))

#### Dependencies

* [clang](http://clang.llvm.org/) (version 8+)
* [lld](https://lld.llvm.org/) (version 8+)
* [llvm](https://llvm.org/) (version 8+, including any "tools" or "runtime")
* [cmake](https://cmake.org/) (version 3.10+)
* [make](https://www.gnu.org/software/make/) (GNU Make version 4+)
* [git](https://git-scm.com/)
* [wget](https://www.gnu.org/software/wget/)
* [tar](https://www.gnu.org/software/tar/)
* unzip
* [autoconf](https://www.gnu.org/software/autoconf/autoconf.html)
* [libtool](https://www.gnu.org/software/libtool/)
* [sh or bash](https://en.wikipedia.org/wiki/Bourne_shell)
* [SDL2](https://www.libsdl.org/) / sdl2 / sdl2-dev / libsdl2 / libsdl2-dev
* [SDL2\_mixer](https://www.libsdl.org/projects/SDL_mixer/) / sdl2\_mixer /
  libsdl2-mixer / libsdl2-mixer-dev
* [glut](http://freeglut.sourceforge.net/) / freeglut / freeglut3,
  freeglut3-dev (an implementation of GLUT, including development files,
  version 3)
* libXmu / libxmu (including the "development" version, if that's separate)
* libXi / libxi (including the "development" version)
* libgl-dev / libgl1-mesa-dev / libgl / mesa / libGL-devel (implementation of
  OpenGL with development files)
* libosmesa-dev / libosmesa / osmesa (skip this if your package manager doesn't
  have it)
* xorg / xorg-dev / xorg-server-devel (Xorg development libraries)
* build-essential (for users of Debian-based distibutions only)
* [ninja](https://ninja-build.org/) (technically optional, you can simply *not*
  pass `-GNinja` to cmake to use Make instead)
* [ccache](https://ccache.samba.org/) (optional, for faster build times)

(**Note for [Solus](https://solus-project.com/) users:**
`sudo eopkg it -c system.devel`)

Most of these dependencies should be available from your package manager
(`pacman`, `apt`, `dnf`, `zypper`, `pkg`, `xbps-install`, `eopkg`, `yum`,
etc.), but for all dependencies listed with a version number, **make sure
to check that the version your package manager gives you is high enough**.
If your package manager doesn't have something or doesn't have a high enough
version, you may have to install it using instructions from the relevant
website and/or use auxilliary package management (`yaourt`, PPAs, `copr`,
etc.).

#### Instructions

```bash
$ git clone https://github.com/HypatiaOfAlexandria/MortalClient.git
$ git clone https://github.com/HypatiaOfAlexandria/NoLifeNx.git nlnx

# The next command is probably best replaced by navigating to
# https://sourceforge.net/projects/asio/files/latest/download
# and downloading from there to get the latest stable version of ASIO.
$ wget https://downloads.sourceforge.net/project/asio/asio/1.14.0%20%28Stable%29/asio-1.14.0.tar.bz2
$ mkdir asio
$ tar xf asio-* --strip-components=1 -C asio/
$ rm asio-*

$ git clone https://github.com/glfw/glfw.git

# Again, the following command can be replaced by just going to
# https://sourceforge.net/projects/glew/files/glew
# and downloading the latest version of GLEW.
$ wget https://downloads.sourceforge.net/project/glew/glew/2.1.0/glew-2.1.0.tgz
$ mkdir glew
$ tar xf glew-* --strip-components=1 -C glew/
$ rm glew-*

$ git clone git://git.sv.nongnu.org/freetype/freetype2.git freetype

$ git clone https://github.com/lz4/lz4.git

# Again, the following command can be replaced by just going to
# https://www.boost.org/users/download/
# and downloading the latest version of Boost.
$ wget https://dl.bintray.com/boostorg/release/1.71.0/source/boost_1_71_0.tar.bz2
$ tar xf boost*
$ rm boost*.tar.bz2
$ mv boost*/ boost/

$ git clone https://github.com/skystrife/cpptoml.git

$ git clone https://github.com/imneme/pcg-cpp.git

$ git clone https://github.com/DuffsDevice/tinyutf8.git

$ export CC='/usr/bin/clang'
$ export CXX='/usr/bin/clang++'

$ cd freetype
$ sh autogen.sh
$ ./configure
$ make -j
$ cd ..

$ cd glew
$ make -j
$ cd ..

$ cd glfw
$ mkdir build
$ cd build
$ cmake -GNinja ..
$ ninja
$ cd ../..

$ cd lz4
$ make -j
$ cd ..

$ cd MortalClient
$ mkdir build
$ cd build
# Build type may also be `Release`, `RelWithDebInfo`, or `MinSizeRel`.
# Additionally, pass in the argument `-DNATIVE_BUILD=1` if you desire a native-
# only build (`-march=native`).
#
# Specify `-DCMAKE_CXX_COMPILER_LAUNCHER=ccache` if you are using ccache.
$ cmake -DCMAKE_BUILD_TYPE=Debug -GNinja ..
# Or `ninja -jN` with N being the number of CPU cores you wish to utilize.
$ ninja
# For `Release` and `MinSizeRel` builds only:
$ strip JourneyClient
```

If all this is successful, you should have the executable in your current
directory (`MortalClient/build`).

### macOS

#### Dependencies

* macOS Command Line Tools (can be installed using `xcode-select --install`,
  includes clang, git, make, and some things needed for basic clang
  functionality)
* [Homebrew](https://brew.sh/)
* [llvm](https://llvm.org/) (`brew install llvm`)
* [cmake](https://cmake.org/) (`brew install cmake`)
* [wget](https://www.gnu.org/software/wget/) (`brew install wget`)
* [autoconf](https://www.gnu.org/software/autoconf/autoconf.html)
  (`brew install autoconf`)
* [libtool](https://www.gnu.org/software/libtool/) (`brew install libtool`; the
  macOS CL tools come with a libtool, but this installs the GNU version with
  'g' prefix e.g. `glibtoolize`)
* [SDL2](https://www.libsdl.org/) (`brew install sdl2`)
* [SDL2\_mixer](https://www.libsdl.org/projects/SDL_mixer/)
  (`brew install sdl2_mixer`)
* [freeglut](http://freeglut.sourceforge.net/) (`brew install freeglut`; may
  require you to separately install XQuartz, one way to do this is
  `brew cask install xquartz`)
* [freetype](https://www.freetype.org/) (`brew install freetype`)
* [ninja](https://ninja-build.org/) (`brew install ninja`; technically
  optional, you can simply *not* pass `-GNinja` to cmake to use Make instead)
* [ccache](https://ccache.samba.org/) (optional, for faster build times;
  `brew install ccache`)

#### Instructions

```bash
$ git clone https://github.com/HypatiaOfAlexandria/MortalClient.git
$ git clone https://github.com/HypatiaOfAlexandria/NoLifeNx.git nlnx

# The next command is probably best replaced by navigating to
# https://sourceforge.net/projects/asio/files/latest/download
# and downloading from there to get the latest stable version of ASIO.
$ wget https://downloads.sourceforge.net/project/asio/asio/1.14.0%20%28Stable%29/asio-1.14.0.tar.bz2
$ mkdir asio
$ tar xf asio-* --strip-components=1 -C asio/
$ rm asio-*

$ git clone https://github.com/glfw/glfw.git

# Again, the following command can be replaced by just going to
# https://sourceforge.net/projects/glew/files/glew
# and downloading the latest version of GLEW.
$ wget https://downloads.sourceforge.net/project/glew/glew/2.1.0/glew-2.1.0.tgz
$ mkdir glew
$ tar xf glew-* --strip-components=1 -C glew/
$ rm glew-*

$ git clone https://github.com/lz4/lz4.git

# Again, the following command can be replaced by just going to
# https://www.boost.org/users/download/
# and downloading the latest version of Boost.
$ wget https://dl.bintray.com/boostorg/release/1.71.0/source/boost_1_71_0.tar.bz2
$ tar xf boost*
$ rm boost*.tar.bz2
$ mv boost*/ boost/

$ git clone https://github.com/skystrife/cpptoml.git

$ git clone https://github.com/imneme/pcg-cpp.git

$ git clone https://github.com/DuffsDevice/tinyutf8.git

$ export CC='clang'
$ export CXX='clang++'

$ cd glew
$ make
$ cd ..

$ cd glfw
$ mkdir build
$ cd build
$ cmake ..
$ make
$ cd ../..

$ cd lz4
$ make
$ cd ..

$ cd MortalClient
$ mkdir build
$ cd build
# Build type may also be `Release`, `RelWithDebInfo`, or `MinSizeRel`.
# Additionally, pass in the argument `-DNATIVE_BUILD=1` if you desire a native-
# only build (`-march=native`).
#
# Specify `-DCMAKE_CXX_COMPILER_LAUNCHER=ccache` if you are using ccache.
$ cmake -DCMAKE_BUILD_TYPE=Debug -GNinja ..
# Or `ninja -jN` with N being the number of CPU cores you wish to utilize.
$ ninja
# For `Release` and `MinSizeRel` builds only:
$ strip JourneyClient
```

If all this is successful, you should have the executable in your current
directory (`MortalClient/build`). However, it probably will not run right
away, since the paths that the executable looks for dylibs on will be wrong.

In order to fix this, gather up the following files, copying them to wherever
you find most appropriate if desired (you may want to put them all into the
same directory as the executable for ease of use). All paths shown here are
relative to the base directory where you cloned all of the repos and extracted
the tarballs:

* `libGLEW.dylib` (found as `glew/lib/libGLEW.dylib`, this should be a symlink
  to `libGLEW.2.1.0.dylib` or something like that, so be aware)
* `liblz4.dylib` (found as `lz4/lib/liblz4.dylib`, this should be a symlink to
  `liblz4.1.9.2.dylib` or something like that, so be aware)

Now that you have the locations of these dylibs, you can change the executable
to point to them. Like this, for example:

```bash
$ install_name_tool -change /usr/local/lib/libGLEW.2.1.0.dylib ./libGLEW.2.1.0.dylib JourneyClient
$ install_name_tool -change /usr/local/lib/liblz4.1.dylib ./liblz4.1.9.2.dylib JourneyClient
```

### Windows NT (Windows 7, 8, 10+) (64-bit only, i.e. amd64/x86\_64)

#### Dependencies

* [Visual Studio 2017](https://www.visualstudio.com/downloads/) (the Community Edition works just fine, make sure to enable Visual C++ development when installing)
* [.NET Framework 4](https://www.microsoft.com/en-us/download/details.aspx?id=17718) (hopefully already installed, but just in case)
* [Visual C++ Redistributable for Visual Studio 2017](https://go.microsoft.com/fwlink/?LinkId=746572) (probably already installed, but again, just in case)
* [clang for windows](https://releases.llvm.org/download.html) (version 8+; download and install **Pre-Built Binaries:** -> Clang for Windows (64-bit))
* [llvm-utils](https://github.com/zufuliu/llvm-utils/releases) (download and install LLVM_VS2017.zip)
* [cmake](https://cmake.org/download/) (latest version, 3.11.X as of this writing)
* [git](https://git-scm.com/download/win)
* [7-Zip](https://www.7-zip.org/)

#### Instructions

In the below instructions, you can replace the link with the latest version of the dependencies to download them. But if any of them has a major change, you have to edit this project to support it. Most of the time only need to change the `lib` and `include` paths of it in `CMakeLists.txt`. Sometimes need to change the whole project, everywhere the project including or calling it. Thanks to multiline editing and multifile editing in mordern editor, it won't take much times. May happen when try to support newer version of `tinyutf8`.

```bat
git clone https://github.com/fmnijk/MortalClient.git
git clone https://github.com/HypatiaOfAlexandria/NoLifeNx.git nlnx
git clone https://github.com/skystrife/cpptoml.git
git clone https://github.com/imneme/pcg-cpp.git
git clone https://github.com/DuffsDevice/tinyutf8.git --branch v4.4.3

curl -LJO https://github.com/libsdl-org/SDL/releases/download/release-2.26.2/SDL2-devel-2.26.2-VC.zip
7z x SDL2*.zip
del SDL2*.zip
move SDL2* SDL2

curl -LJO https://github.com/libsdl-org/SDL_mixer/releases/download/release-2.6.2/SDL2_mixer-devel-2.6.2-VC.zip
7z x SDL2_mixer*.zip
del SDL2_mixer*.zip
move SDL2_mixer* SDL2_mixer

curl -LJO https://nchc.dl.sourceforge.net/project/asio/asio/1.24.0%20%28Stable%29/asio-1.24.0.zip
7z x asio*.zip
del asio*.zip
move asio* asio

curl -LJO https://github.com/glfw/glfw/releases/download/3.3.8/glfw-3.3.8.bin.WIN64.zip
7z x glfw*.zip
del glfw*.zip
move glfw* glfw

curl -LJO https://nchc.dl.sourceforge.net/project/glew/glew/2.1.0/glew-2.1.0-win32.zip
7z x glew*.zip
del glew*.zip
move glew* glew

curl -LJO https://boostorg.jfrog.io/artifactory/main/release/1.81.0/source/boost_1_81_0.zip
7z x boost*.zip
del boost*.zip
move boost* boost
```

There are two dependencies we need to build them ourselves. `freetype` and `lz4`. The reason is showing below.
`freetype`: No `.pdb` file in official release.
`lz4`: Official release is builded by `MinGW` and it's not compatilbe to `MSVC`.
```
curl -LJO https://nchc.dl.sourceforge.net/project/freetype/freetype2/2.12.1/ft2121.zip
7z x ft2121.zip
del ft2121.zip
move freetype* freetype_src
cd freetype_src
cmake -B build -D BUILD_SHARED_LIBS=true -D CMAKE_BUILD_TYPE=Debug
cmake --build build
cd ..
md freetype\demos\win64 freetype\include "freetype\release dll\win64" "freetype\release static\vs2015-2022\win64"
move freetype_src\ChangeLog freetype\ChangeLog.txt
move freetype_src\docs\FTL.TXT freetype
move freetype_src\docs\GPLv2.TXT freetype
move freetype_src\LICENSE.TXT freetype
move freetype_src\README freetype\README.md
move freetype_src\include "freetype\include"
copy freetype_src\build\Debug\freetyped.dll "freetype\demos\win64"
move freetype_src\build\Debug\freetyped.dll "freetype\release dll\win64"
copy freetype_src\build\Debug\freetyped.lib "freetype\release dll\win64"
move freetype_src\build\Debug\freetyped.exp "freetype\release static\vs2015-2022\win64"
move freetype_src\build\Debug\freetyped.lib "freetype\release static\vs2015-2022\win64"
move freetype_src\build\Debug\freetyped.pdb "freetype\release static\vs2015-2022\win64"
rmdir /Q /S freetype_src

git clone https://github.com/lz4/lz4.git lz4_src
cd lz4_src\build\cmake
md build
cd build
cmake -G "Visual Studio 16 2019" -A x64 -T "LLVM_v142" -D CMAKE_C_COMPILER="C:/Program Files/LLVM/bin/clang.exe" ..
cmake --build . -- /v:d /property:Configuration=Debug /property:Platform=x64
cd ..\..\..\..
md lz4\dll lz4\example lz4\include lz4\static
move lz4_src\NEWS lz4
move lz4_src\README.md lz4
move lz4_src\build\cmake\build\Debug\lz4.exe lz4
move lz4_src\build\cmake\build\Debug\lz4.dll lz4\dll
move lz4_src\lib\dll\example\*.* lz4\example
move lz4_src\lib\xxhash.c lz4\example
move lz4_src\lib\xxhash.h lz4\example
move lz4_src\lib\lz4.h lz4\include
move lz4_src\lib\lz4frame.h lz4\include
move lz4_src\lib\lz4hc.h lz4\include
move lz4_src\build\cmake\build\Debug\lz4.exp lz4\static
move lz4_src\build\cmake\build\Debug\lz4.lib lz4\static
move lz4_src\build\cmake\build\Debug\lz4.pdb lz4\static
rmdir /Q /S lz4_src
```

Notice here that we assume the installation directory of LLVM is the default
one. If you don't use the default installation directory, you will have to
tweak `CMakeLists.txt` yourself:

```bat
SET CC="C:\Program Files\LLVM\bin\clang.exe"
SET CXX="C:\Program Files\LLVM\bin\clang++.exe"

cd MortalClient
md build
cd build
```

Use the following two commands if `CMAKE_BUILD_TYPE` is to be `Debug` (you may
wish to add an additional `/mN` flag, with `N` being the number of CPU cores
you wish to utilize for compilation):

```bat
del * /S /Q > nul
cmake -G "Visual Studio 16 2019" -A x64 -T "LLVM_v142" -D CMAKE_C_COMPILER="C:/Program Files/LLVM/bin/clang.exe" -D CMAKE_CXX_COMPILER="C:/Program Files/LLVM/bin/clang++.exe" -D CMAKE_BUILD_TYPE=Debug ..
cmake --build . -- /v:d /property:Configuration=Debug /property:Platform=x64 > ..\..\out.txt
```

`CMAKE_BUILD_TYPE` here may also be `Release`, `RelWithDebInfo`, or
`MinSizeRel`. If you want to use one of these build types, use these commands
instead, setting `CMAKE_BUILD_TYPE` to the desired value (we use `Release`
here as an example):

```bat
$ cmake -G "Visual Studio 15 2017 Win64" -T "LLVM-vs2017" -D CMAKE_C_COMPILER="C:/Program Files/LLVM/bin/clang.exe" -D CMAKE_CXX_COMPILER="C:/Program Files/LLVM/bin/clang++.exe" -D CMAKE_BUILD_TYPE=Release ..
$ cmake --build . -- /v:d /property:Configuration=Release /property:Platform=x64
```

If all this is successful, you should have the executable (`JourneyClient.exe`)
in `MortalClient\build\Debug` for debug builds, or
`MortalClient\build\Release` for release build types. However, it
probably will not run right away, since the paths that the executable looks
for DLLs on will be wrong.

In order to fix this, gather up the following files, copying them to be right
next to the executable. All paths shown here are relative to the base directory
where you cloned all of the repos and extracted the ZIP files:

* `freetype.dll` (found as `freetype\win64\freetype.dll`)
* `glew32.dll` (found as `glew\bin\Release\x64\glew32.dll`)
* `liblz4.dll` (found as `lz4\dll\liblz4.so.1.9.2.dll`, the version number may
  be different and you will have to rename your copied version to `liblz4.dll`)

## Compiler

MortalClient is built against the latest stable version of
[Clang](http://clang.llvm.org/) (nominally 8.0.1 as of this writing), again for
cross-platform considerations and efficiency. [The GCC](https://gcc.gnu.org/)
(version 9.1.0 as of this writing) is another excellent choice, especially for
those on GNU+Linux operating systems (or other OSs which default to GCC), but
GCC is **not** officially supported by MortalClient.

That being said, don't be shy to file issues involving GCC or to make PRs to
improve ease of use/compatibility with it.

## C++ details

JourneyClient was originally developed under
[the C++14 standard](https://en.wikipedia.org/wiki/C%2B%2B14). However,
**MortalClient strictly uses**
**[the C++17 standard](https://en.wikipedia.org/wiki/C%2B%2B17) and makes use**
**of C++17 features**.

In addition, this project (sort of) follows
[the ISO C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines).
[A complete copy of the guidelines is available here](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md).

More specific guidelines can be found in "code-guidelines.md".

## Configuration

The build can be configured by editing the Journey.h file.
The following options are available:

* `JOURNEY_USE_CRYPTO` : Use cryptography when communicating for the server.
* `JOURNEY_USE_XXHASH` : Use xxhash for file check (additional dependency)
* `JOURNEY_USE_ASIO`   : Use Asio for networking (additional dependency)

MortalClient uses crypto (`JOURNEY_USE_CRYPTO`), and also uses ASIO
(`JOURNEY_USE_ASIO`) to maintain cross-platform compatibility.

## Dependencies

| **Category**      | **Dependency**                                             | **License**         | **Depends on** | **Header only?** | **Optional?** |
|-------------------|------------------------------------------------------------|---------------------|----------------|------------------|---------------|
| (De)compression   | [LZ4](https://github.com/lz4/lz4)                          | BSD 2-Clause        | -              | No               | No            |
| Error checking    | [xxHash](https://github.com/Cyan4973/xxHash)               | BSD 2-Clause        | -              | No               | Yes           |
| NX library        | [NoLifeNX](https://github.com/NoLifeDev/NoLifeNx)          | AGPL v3+            | LZ4            | No               | No            |
| Graphics          | [GLFW3](http://www.glfw.org/download.html)                 | zlib/libpng         | OpenGL support | No               | No            |
| Graphics          | [GLEW](http://glew.sourceforge.net/)                       | Modified BSD/MIT    | OpenGL support | No               | No            |
| Graphics          | [FreeType](http://www.freetype.org/)                       | FreeType            | -              | No               | No            |
| Audio             | [SDL2\_mixer](https://www.libsdl.org/projects/SDL_mixer/)  | zlib/libpng         | SDL2           | No               | No            |
| Networking        | [Asio](http://think-async.com/) (standalone; no Boost)     | Boost               | -              | Yes              | No            |
| PRNG              | [PCG](http://www.pcg-random.org/) (C++ implementation)     | Apache 2.0/MIT      | -              | Yes              | No            |
| Config            | [cpptoml](https://github.com/skystrife/cpptoml)            | MIT                 | -              | Yes              | No            |
| General           | [Boost](https://www.boost.org/) (Bimap, Container)         | Boost               | -              | Yes              | No            |
| Strings           | [tinyutf8](https://github.com/DuffsDevice/tinyutf8/)       | BSD 3-Clause        | -              | No               | No            |

## Licensing

[![GNU AGPL v3+](https://www.gnu.org/graphics/agplv3-155x51.png)](https://www.gnu.org/licenses/agpl-3.0.en.html)

All MortalClient/LibreMaple/JourneyClient code is © 2015-2016 Daniel Allendorf,
2018-2019 LibreMaple Team, licensed under the
[GNU Affero General Public License version 3 or higher](https://www.gnu.org/licenses/agpl-3.0.en.html)
(GNU AGPL). See "LICENSE" for the full text.

That implies a few things. For one, that makes this work a work of **free**
**software**, including both the source code *and any binaries created from*
*it*. According to the Free Software Foundation:

> A program is free software if the program's users have the four essential
> freedoms:
>
> * The freedom to run the program as you wish, for any purpose (freedom 0).
> * The freedom to study how the program works, and change it so it does your
>   computing as you wish (freedom 1). Access to the source code is a
>   precondition for this.
> * The freedom to redistribute copies so you can help others (freedom 2).
> * The freedom to distribute copies of your modified versions to others
>   (freedom 3). By doing this you can give the whole community a chance to
>   benefit from your changes. Access to the source code is a precondition for
>   this.

As the above text implies, *derived/modified works are encouraged*, and due to
the nature of the GNU AGPL, all such works are free software as well (also
licensed under the GNU AGPL).
