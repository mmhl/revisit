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
enum class NC_ATTR {
        ATTR_BOLD,
};

class Win {
public:
        Win(WINDOW *win, int y, int x, int beg_y, int beg_x);
        void print(string str);
        void print(char ch);
        void print(glyph ch);
        void print_at(string str, int y, int x);
        void print_at(char g, int y, int x);
        void refresh();
        void erase();
        int win_attr_on(NC_ATTR attr);
        int win_attr_off();
        virtual ~Win();
protected:
        int size_y, size_x, pos_y, pos_x;
private:
        WINDOW *win;
        WINDOW *dwin; // drawing area of bordered window
        int cur_y, cur_x;
};

class Term  {
public:
        Term();
        virtual ~Term();
        void init(); 
        void end();
        char term_getch();
        int set_delay(int tenths);
        Win *new_window(int,int,int,int);
        WINDOW *get_term();
        TermSize get_size();
protected:
        TermSize size;
private:
        vector<Win *> windows;
        WINDOW *term_window; // Main term window; stdscr
};


#endif
