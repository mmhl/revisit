#ifndef __TERM_H__
#define __TERM_H__
#include <ncurses.h>
#include <string>
#include <vector>
using namespace std;
struct TermSize {
        int y;
        int x;
};

class Win {
public:
        Win(WINDOW *win, int y, int x, int beg_y, int beg_x);
        void print(string str);
        virtual ~Win();
protected:
        int size_y, size_x, pos_y, pos_x;
private:
        WINDOW *win;
};

class Term  {
public:
        Term();
        virtual ~Term();
        void term_init(); 
        void term_end();
        char term_getch();
        Win *new_window(int,int,int,int);
        TermSize term_get_size();
protected:
        TermSize term_size;
private:
        vector<Win *> windows;
        WINDOW *term_window; // Main term window; stdscr
};


#endif
