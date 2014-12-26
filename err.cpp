#include <cstdlib>
#include <iostream>
#include <ncursesw/curses.h>
#include "err.h"

void fatal(std::string str) {
        endwin();
        std::cout << "Fatal error, can't continue" << std::endl;
        std::cout << str << std::endl;
        exit(-1);
}
