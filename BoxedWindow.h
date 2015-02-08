/*
 * BoxedWindow.h
 *
 *  Created on: 8 lut 2015
 *      Author: mhl
 */

#ifndef BOXEDWINDOW_H_
#define BOXEDWINDOW_H_

#include "Window.h"

//BoxedWindow creates two windows. One window is for holding box.
//The other window is for content
class BoxedWindow: public Window {
public:
	BoxedWindow(int beg_y, int beg_x, int lines, int columns);
	virtual int print(std::string msg) override;
	virtual void redraw() override;
	virtual ~BoxedWindow();
private:
	Window m_inner_win;

};

#endif /* BOXEDWINDOW_H_ */
