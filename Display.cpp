/*
 * Display.cpp
 *
 *  Created on: 5 lut 2015
 *      Author: mhl
 */

#include "Display.h"

Display::Display(Term *term) : m_term(term) {
	m_disp_size.sizex = term->m_size.y;
	m_disp_size.sizey = term->m_size.x;
}

Display::~Display() {
	m_term = nullptr;
}

