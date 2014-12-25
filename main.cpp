#include <locale.h>
#include <iostream>
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include <sstream>
#include "term.h"
#include "world.h"

int main() {
        setlocale(LC_ALL, "");
        Term term;
        term.init();
        TermSize tsize = term.get_size();
        Win *game_window = term.new_window(tsize.y-3,tsize.x-1,0,0);
        Win *status_window = term.new_window(3,tsize.x-1,tsize.y-3, 0);
        game_window->refresh();
        WorldDisplay wd(game_window);
        status_window->refresh();
        status_window->print("Created world display");
        status_window->refresh();
        char ch;
        while((ch = term.term_getch()) != 'q') {
                stringstream ss;
                ss << "You pressed: " << ch; // Idea: Let class StatusBar be a stream.
                status_window->erase();
                status_window->print("You pressed: ");
                status_window->print("\xE2\x98\xA0 ");
                status_window->refresh();
        }
        return 0;
}

