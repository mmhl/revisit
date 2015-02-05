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
}

void TermWin::refresh() {
	wrefresh(m_nc_win);
}

TermWin::~TermWin() {
	delwin(m_nc_win);
}

