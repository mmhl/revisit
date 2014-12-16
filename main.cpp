#include <iostream>
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include "term.h"

int main() {
        Term term;
        term.term_init();
        term.term_print("Hello world");
        char ch;
        while((ch = term.term_getch()) != 'q') {
                term.term_print("Hello world\n");
        }
        return 0;
}

