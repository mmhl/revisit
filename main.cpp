#include <iostream>
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include "term.h"

int main() {
        Term term;
        term.term_init();
        Win *print_win = term.new_window(20,30,20,20);
        print_win->print("Hello Worlds");
        char ch;
        while((ch = term.term_getch()) != 'q') {
        }
        return 0;
}

