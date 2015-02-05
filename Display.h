/*
 * Display.h
 *
 *  Created on: 5 lut 2015
 *      Author: mhl
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "term.h"
#include <memory>
struct DisplaySize {
	int sizex;
	int sizey;
};
//Abstract out Terminal device from user
class Display {
public:
	Display(Term *term);
	virtual ~Display();
private:
	Term *m_term;
	DisplaySize m_disp_size;
};

#endif /* DISPLAY_H_ */
