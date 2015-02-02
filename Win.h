/* 
 * File:   Win.h
 * Author: mhl
 *
 * Created on January 31, 2015, 6:00 PM
 */

#ifndef WIN_H
#define	WIN_H
#include <map>
#include <string>
#include <iostream>
#include <ncursesw/ncurses.h>
using namespace std;

typedef int NC_ATTRIBUTE;
typedef cchar_t glyph;

enum class CHAR_ATTR {
    BOLD,
};
/*
 * TODO: Consider BordederWin that inherits from Win
 */

/*
 * Win - window in which we can draw something
 */
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
        int win_attr_on(CHAR_ATTR attr);
        int win_attr_off();
        virtual ~Win();
protected:
        int m_sizey, m_sizex, m_posy, m_posx;
private:
        WINDOW *m_bordered_win;
        WINDOW *m_drawable_win; // drawing area of bordered window
        int m_cury, m_curx;
};

#endif	/* WIN_H */

