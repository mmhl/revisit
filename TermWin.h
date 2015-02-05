/*
 * TermWin.h
 *
 *  Created on: 5 lut 2015
 *      Author: mhl
 */

#ifndef TERMWIN_H_
#define TERMWIN_H_
#include <ncursesw/ncurses.h>
//Thin wrapper for representing concrete WINDOW created by ncurses
struct WinSize {
	int sizex;
	int sizey;
};
class TermWin {
public:
	TermWin(int beg_y, int beg_x, int lines, int columns);
	void refresh();
	virtual ~TermWin();
private:
	WINDOW *m_nc_win;
	//TODO: Do vector of pointers to derived WINDOWs
	int m_beg_y, m_beg_x, m_lines, m_columns;
};

#endif /* TERMWIN_H_ */
