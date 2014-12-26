#include "err.h"
#include "term.h"

Win::Win(WINDOW *win, int size_y, int size_x, int beg_y, int beg_x) 
: size_y(size_y), pos_y(beg_y), pos_x(beg_x), win(win), dwin(nullptr), cur_y(0), cur_x(0) {
       dwin = derwin(win, size_y-2, size_x-2, 1, 1);
};
Win::~Win() {
        delwin(win);
        delwin(dwin);
};
void Win::print(string str) {
        wprintw(dwin, "%s", str.c_str());
}
void Win::print(char ch) {
        wprintw(dwin, "%c", ch);
}
void Win::print(glyph ch) {
        wadd_wch(dwin, &ch);
}
void Win::print_at(string str, int y, int x) {
        mvwprintw(dwin, y, x, "%s", str.c_str());
}
void Win::print_at(char g, int y, int x) {
        mvwaddch(dwin, y, x, g);
}
//Refresh both main window and drawing window
void Win::refresh() {
        wrefresh(win);
        wrefresh(dwin);
}
void Win::erase() {
        werase(dwin); 
        refresh();
}
int Win::win_attr_on(NC_ATTR attr) {
        int attributes = 0;
        switch(attr) {
                case NC_ATTR::ATTR_BOLD:
                        attributes |= A_BOLD;
                        break;
                default:
                        return -1;
        }
        wattrset(dwin, attributes);
        refresh();
        return 0;
}
int Win::win_attr_off() {
        wattrset(dwin, A_NORMAL);
        return 0;
}


//Term class.
Term::Term() : size(), windows(), term_window(nullptr){
}
void Term::init() {
        term_window = initscr();
        if(term_window == nullptr) {
                fatal("Can't initialize curses!");
        }
        wclear(term_window);
        wrefresh(term_window);
        noecho();
        raw();
        keypad(term_window, true);
        curs_set(0);
        getmaxyx(term_window, size.y, size.x);
}

void Term::end() {
        endwin();
}

char Term::term_getch() {
        return wgetch(term_window);
}
//Consider capturing SIGWINCH for detecting terminal size change
TermSize Term::get_size() {
        return size;
}
int Term::set_delay(int tenths) {
        if(tenths == 0) {
                nodelay(term_window, true);
        }
        else if(tenths > 0 && tenths < 256) {
                halfdelay(tenths);
        }
        else 
                return -1;
        return 0;
}
Win *Term::new_window(int size_y, int size_x, int beg_y, int beg_x) {
        WINDOW *curse_window = newwin(size_y, size_x, beg_y, beg_x);  
        if(curse_window == nullptr)
                fatal("Can't create winndow with ncurses");
        box(curse_window, 0, 0);
}

Term::~Term() {
        for(auto &win : windows) {
                delete win;
        }
        if(!isendwin()) 
                endwin();
        term_window = nullptr;
}
