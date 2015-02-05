
#include "term.h"
//Term class.

Term::Term() : m_size(), m_stdscr(nullptr) {
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
    getmaxyx(m_stdscr, m_size.y, m_size.x);
}

void Term::end() {
    endwin();
}

char Term::term_getch() {
    return wgetch(m_stdscr);
}
//Consider capturing SIGWINCH for detecting terminal size change

TermSize Term::get_size() {
    return m_size;
}

int Term::set_keyboard_delay(int tenths) {
    if (tenths == 0) {
        nodelay(m_stdscr, true);
    } else if (tenths > 0 && tenths < 256) {
        halfdelay(tenths);
    } else
        return -1;
    return 0;
}
//

Term::~Term() {
    endwin();
    m_stdscr = nullptr;
}
