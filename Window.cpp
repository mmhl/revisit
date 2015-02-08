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

void Window::cursor_pos_update() {
	m_term_win.cur_move(m_cursor_pos.y, m_cursor_pos.x);
}

