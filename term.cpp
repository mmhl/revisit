#include "term.h"

Term::Term() : term_window(nullptr), term_size() {
}
void Term::term_init() {
        term_window = initscr();
        if(term_window)
                wclear(term_window);
        wrefresh(term_window);
        noecho();
        raw();
        keypad(term_window, true);
        getmaxyx(term_window, term_size.y, term_size.x);
}

void Term::term_end() {
        endwin();
}
void Term::term_print(std::string word) {
        printw(word.c_str());
        wrefresh(term_window);
}
char Term::term_getch() {
        return wgetch(term_window);
}
//Consider capturing SIGWINCH for detecting terminal size change
TermSize Term::term_get_size() {
        return term_size;
}

Term::~Term() {
        if(!isendwin()) 
                endwin();
        term_window = nullptr;
}
