/*
 * Window.h
 *
 *  Created on: 8 lut 2015
 *      Author: mhl
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <vector>
#include <string>
#include "TermWin.h"

struct WinSize {
	int lines;
	int columns;
};
struct WinCurPos {
	int y;
	int x;
};
/*
 * Abstract window class, TermWin essentialy.
 */
class Window {
public:
	Window(int beg_y, int beg_x, int lines, int columns);
	virtual WinSize get_window_size() const;
	virtual int print(std::string msg); //Simple string message. TODO: Create function that accepts varargs
	virtual void redraw();
	virtual void cursor_move(int y, int x);
	virtual ~Window();
protected:
	WinSize m_win_size;
	WinCurPos m_cursor_pos;

private:
	Window(TermWin term_win, int beg_x, int beg_y, int lines, int columns);
	void cursor_pos_update();
	TermWin m_term_win;
};

#endif /* WINDOW_H_ */
