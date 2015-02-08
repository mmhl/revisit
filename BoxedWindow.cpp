/*
 * BoxedWindow.cpp
 *
 *  Created on: 8 lut 2015
 *      Author: mhl
 */

#include "BoxedWindow.h"
#include "Window.h"
BoxedWindow::BoxedWindow(int beg_y, int beg_x, int lines, int columns) :
Window(beg_y, beg_x, lines, columns),
m_inner_win(beg_y+1,beg_x+1,lines-2,columns-2) {
	Window::box(); // Create boxed window
}

int BoxedWindow::print(std::string msg) {
	return m_inner_win.print(msg);
}

void BoxedWindow::redraw() {
	Window::redraw(); // Redraw box window
	m_inner_win.redraw(); // redraw content window
}

BoxedWindow::~BoxedWindow() {
}

