/*
 * Window.cpp
 *
 *  Created on: 8 lut 2015
 *      Author: mhl
 */

#include "Window.h"
Window::Window(int beg_y, int beg_x, int lines, int columns) :
m_term_win(TermWin(beg_y, beg_x, lines, columns)) {
	m_win_size.columns = columns;
	m_win_size.lines = lines;
	m_cursor_pos = {0, 0};
}

Window::Window(TermWin term_win, int lines, int columns) :
m_term_win(term_win) {
	m_win_size.columns = columns;
	m_win_size.lines = lines;
	m_cursor_pos = {0, 0};
}

Window::~Window() {

}


int Window::print(std::string msg) {
	return m_term_win.put_cstr_at(msg.c_str(), m_cursor_pos.y, m_cursor_pos.x);
}

void Window::cursor_move(int y, int x) {
	m_cursor_pos.y = y;
	m_cursor_pos.x = x;
	cursor_pos_update();
}

WinSize Window::get_window_size() const {
	return m_win_size;
}

void Window::redraw() {
	m_term_win.refresh();
}

Window Window::create_child_window(int beg_y, int beg_x, int lines, int columns, bool rel) {
	TermWin child_termwin = m_term_win.create_children_win(beg_y, beg_x,lines,columns,rel);
	Window new_win = Window(child_termwin, lines, columns);
	return new_win;
}

void Window::cursor_pos_update() {
	m_term_win.cur_move(m_cursor_pos.y, m_cursor_pos.x);
}

int Window::box() {
	return m_term_win.create_box();
}


