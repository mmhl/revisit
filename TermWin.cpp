/*
 * TermWin.cpp
 *
 *  Created on: 5 lut 2015
 *      Author: mhl
 */

#include "TermWin.h"
#include "err.h"

TermWin::TermWin(int beg_y, int beg_x, int lines, int columns) {
	m_nc_win = newwin(lines, columns, beg_y, beg_x);
	if(m_nc_win == nullptr) {
		fatal("Can't create window!");
	}
	m_beg_y = beg_y;
	m_beg_x = beg_x;
	m_lines = lines;
	m_columns = columns;
	m_attrs = 0;
}
TermWin::TermWin(WINDOW *nc_win, int beg_y, int beg_x, int lines, int columns) {
	m_nc_win = nc_win;
	m_beg_y = beg_y;
	m_beg_x = beg_x;
	m_lines = lines;
	m_columns = columns;
	m_attrs = 0;
}
TermWin::TermWin(const TermWin &other) {
	m_nc_win = other.m_nc_win;
	m_beg_y = other.m_beg_y;
	m_beg_x = other.m_beg_x;
	m_lines = other.m_lines;
	m_columns = other.m_columns;
	m_attrs = other.m_attrs;
}
TermWin &TermWin::operator =(const TermWin &other) {
	m_nc_win = other.m_nc_win;
	m_beg_y = other.m_beg_y;
	m_beg_x = other.m_beg_x;
	m_lines = other.m_lines;
	m_columns = other.m_columns;
	m_attrs = other.m_attrs;
	return *this;
}

TermWin::~TermWin() {
	del_win();
}

void TermWin::refresh() {
	wrefresh(m_nc_win);
}

int TermWin::cur_move(int y, int x) {
	return wmove(m_nc_win, y, x) == OK ? 0 : -1;
}

int TermWin::del_win() {
	int ret = 0;
	if(m_nc_win) {
		wclear(m_nc_win);
		ret = delwin(m_nc_win);
		m_nc_win = nullptr;
	}
	return ret;

}
int TermWin::put_wchar_at(const cchar_t &ch, int y, int x) {
	return mvwadd_wch(m_nc_win, y, x, &ch) == OK ? 0 : -1;
}
int TermWin::put_char_at(const char &ch, int y, int x) {
	return mvwaddch(m_nc_win, y, x, ch) == OK ? 0 : -1;
}
int TermWin::put_cstr_at(const char *ch, int y, int x) {
	return mvwprintw(m_nc_win, y, x, "%s", ch) == OK ? 0 : -1;
}
TermWin TermWin::create_children_win(int beg_y, int beg_x, int lines, int columns, bool rel) {
	WINDOW *nc_win;
	if(rel == true) {
		nc_win = derwin(m_nc_win, lines, columns, beg_y, beg_x);
	}
	else {
		nc_win = subwin(m_nc_win, lines, columns, beg_y, beg_x);
	}
	if(nc_win == nullptr) {
		fatal("Can't create subwindow!");
	}
	TermWin new_termwin = TermWin(nc_win, beg_y, beg_x, lines, columns);
	return new_termwin;
}
