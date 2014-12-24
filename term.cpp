#include "term.h"

Win::Win(WINDOW *win, int size_y, int size_x, int beg_y, int beg_x) 
: size_y(size_y), pos_y(beg_y), pos_x(beg_x), win(win) {

};
Win::~Win() {
        delwin(win);
};
void Win::print(string str) {
      wprintw(win, "%s", str.c_str());
      wrefresh(win);
}


Term::Term() : term_size(), windows(), term_window(nullptr){
}
void Term::term_init() {
        term_window = initscr();
        wclear(term_window);
        wrefresh(term_window);
        noecho();
        raw();
        keypad(term_window, true);
        curs_set(0);
        getmaxyx(term_window, term_size.y, term_size.x);
}

void Term::term_end() {
        endwin();
}

char Term::term_getch() {
        return wgetch(term_window);
}
//Consider capturing SIGWINCH for detecting terminal size change
TermSize Term::term_get_size() {
        return term_size;
}
Win *Term::new_window(int size_y, int size_x, int beg_y, int beg_x) {
        WINDOW *curse_window = newwin(size_y, size_x, beg_y, beg_x);  
        box(curse_window, 0, 0);
        Win *win = new Win(curse_window, size_y,size_x,beg_y,beg_x);
        windows.push_back(win);
        return win;
}

Term::~Term() {
        for(auto &win : windows) {
                delete win;
        }
        if(!isendwin()) 
                endwin();
        term_window = nullptr;
}
