
#include "term.h"

//Term class.

Term::Term() : size(), m_windows(), m_stdscr(nullptr) {
}

void Term::init() {
    m_stdscr = initscr();
    if (m_stdscr == nullptr) {
        fatal("Can't initialize curses!");
    }
    wclear(m_stdscr);
    wrefresh(m_stdscr);
    noecho();
    raw();
    keypad(m_stdscr, true);
    curs_set(0);
    getmaxyx(m_stdscr, size.y, size.x);
}

void Term::end() {
    endwin();
}

char Term::term_getch() {
    return wgetch(m_stdscr);
}
//Consider capturing SIGWINCH for detecting terminal size change

TermSize Term::get_size() {
    return size;
}

int Term::set_delay(int tenths) {
    if (tenths == 0) {
        nodelay(m_stdscr, true);
    } else if (tenths > 0 && tenths < 256) {
        halfdelay(tenths);
    } else
        return -1;
    return 0;
}

Win *Term::new_window(int size_y, int size_x, int beg_y, int beg_x) {
    WINDOW *curse_window = newwin(size_y, size_x, beg_y, beg_x);
    if (curse_window == nullptr)
        fatal("Can't create window with ncurses");
    box(curse_window, 0, 0);
    Win *win = new Win(curse_window, size_y, size_x, beg_y, beg_x);
    m_windows.push_back(win);
    wrefresh(m_stdscr);
    win->refresh();
    return win;
}

WINDOW *Term::get_term() {
    return m_stdscr;
}

Term::~Term() {
    for (auto &win : m_windows) {
        delete win;
    }
    if (!isendwin())
        endwin();
    m_stdscr = nullptr;
}
