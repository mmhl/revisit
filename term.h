#ifndef __TERM_H__
#define __TERM_H__
#include <ncursesw/curses.h>
#include <string>
#include <vector>

#include "err.h"
#include "Win.h"
#include <memory>
using namespace std;

struct TermSize {
    int y;
    int x;
};

class Term {
public:
    Term();
    virtual ~Term();
    void init();
    void end();
    char term_getch();
    int set_keyboard_delay(int tenths);
    unique_ptr<Win> new_window(int, int, int, int);
    TermSize get_size();
protected:
    TermSize m_size;
private:
    WINDOW *m_stdscr; // Main term window; stdscr
};


#endif
