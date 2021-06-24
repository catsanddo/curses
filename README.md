# Curses I guess
## Some experementation in curses
It took a while, but I finally have pdcurses up and running.
I don't have a specific end goal with this project.
To start with I will make some simple games to get a feel for the library.

## Building
### Linux
Should compile with a simple `make` command.
Compiling requires SDL 2 development libraries.
### Windows
This can only be built on windows with mingw32's gcc.
You will need to edit `LIB_PATH` and `INCLUDE_PATH` to search for SDL 2
development libraries.
Alternatively, the environment variables `C_INCLUDE_PATH` and `LIBRARY_PATH`
can be set to point to SDL 2 libraries instead.

## Libraries
- [pdcurses](https://pdcurses.org)
- [SDL 2](https://libsdl.org)
