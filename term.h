#ifndef __TERM_H__
#define __TERM_H__
#include <ncursesw/curses.h>
#include <string>
#include <vector>
using namespace std;
typedef cchar_t glyph;

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
    int set_delay(int tenths);
    Win *new_window(int, int, int, int);
    WINDOW *get_term();
    TermSize get_size();
protected:
    TermSize size;
private:
    vector<Win *> m_windows;
    WINDOW *m_stdscr; // Main term window; stdscr
};


#endif
