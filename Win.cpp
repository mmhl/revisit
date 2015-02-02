/* 
 * File:   Win.cpp
 * Author: mhl
 * 
 * Created on January 31, 2015, 6:00 PM
 */

#include "Win.h"

#include "err.h"
#include "term.h"

#include <stdexcept>

static const map<CHAR_ATTR, NC_ATTRIBUTE> attr_map
{
    {
        CHAR_ATTR::BOLD, A_BOLD
    }
};

Win::Win(WINDOW *win, int size_y, int size_x, int beg_y, int beg_x)
: size_y(size_y), pos_y(beg_y), pos_x(beg_x),
m_bordered_win(win), m_drawable_win(nullptr), m_cury(0), m_curx(0) {
    m_drawable_win = derwin(win, size_y - 2, size_x - 2, 1, 1);
};

Win::~Win() {
    win_attr_off();
    delwin(m_bordered_win);
    delwin(m_drawable_win);
};

void Win::print(string str) {
    wprintw(m_drawable_win, "%s", str.c_str());
}

void Win::print(char ch) {
    wprintw(m_drawable_win, "%c", ch);
}

void Win::print(glyph ch) {
    wadd_wch(m_drawable_win, &ch);
}

void Win::print_at(string str, int y, int x) {
    mvwprintw(m_drawable_win, y, x, "%s", str.c_str());
}

void Win::print_at(char g, int y, int x) {
    mvwaddch(m_drawable_win, y, x, g);
}

void Win::refresh() {
    wrefresh(m_bordered_win);
    wrefresh(m_drawable_win);
}

void Win::erase() {
    werase(m_drawable_win);
    refresh();
}

int Win::win_attr_on(CHAR_ATTR attribute) {
    int err = 0;
    try {
        auto attr = attr_map.at(attribute);
        wattrset(m_drawable_win, attr);
	refresh();
    } catch (out_of_range &oor) {
        //No such attribute, don't set anything
        //In future, log this.
	err = -1;
    }
    return err;
}

int Win::win_attr_off() {
    wattrset(m_drawable_win, A_NORMAL);
    return 0;
}

