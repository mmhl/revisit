/*
 * TermWin.h
 *
 *  Created on: 5 lut 2015
 *      Author: mhl
 */

#ifndef TERMWIN_H_
#define TERMWIN_H_
#include <ncursesw/ncurses.h>
#include <vector>
//Thin wrapper for representing concrete WINDOW created by ncurses

//TODO: Add cursor position information
class TermWin {
public:
	TermWin(int beg_y, int beg_x, int lines, int columns);
	TermWin(const TermWin &other);
	TermWin &operator=(const TermWin &other);
	void refresh();
	int cur_move(int y, int x);
	int del_win();
	int put_wchar_at(const cchar_t &ch, int y, int x);
	int put_char_at(const char &ch, int y, int x);
	int put_cstr_at(const char *ch, int y, int x);
	//Create standard box
	int create_box();
	// @rel - position new subwindow relatively to parent?
	TermWin create_children_win(int beg_y, int beg_x, int lines, int columns, bool rel = false);
	virtual ~TermWin();
private:
	TermWin(WINDOW *nc_win, int beg_y, int beg_x, int lines, int columns);
	WINDOW *m_nc_win;
	int m_attrs; // Window attributes
	int m_beg_y, m_beg_x, m_lines, m_columns;
	std::vector<TermWin *> m_children; // This should probably be in higher level class
};

#endif /* TERMWIN_H_ */
