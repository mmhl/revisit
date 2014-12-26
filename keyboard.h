#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__
#include <queue>
#include "term.h"
/*
 * 1. TODO: Make Keyboard class a keyboard thread
 * 2. When keypad is on wgetch can retun values larger than 8bit.
 * for now we use int to fit
 * Creation of mapping between this int and Key is desired
 * 3. Keyboard uses stdscr global variable defined when ncurses start
 */

class Keyboard {
public:
        /*
         * Enqueues the key
         */
        Keyboard(bool blocking=false);
        int get(); // Get key or -1 on no key
        ~Keyboard();

private:
        int m_last_char;
        std::queue<int> m_key_queue;
};
#endif
