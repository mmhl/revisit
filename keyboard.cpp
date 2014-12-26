#include "keyboard.h"
#include "term.h"

Keyboard::Keyboard(bool blocking)
: m_last_char(-1), m_key_queue() {
        nodelay(stdscr, blocking);
}
Keyboard::~Keyboard() {
}

int Keyboard::get() {
        m_last_char = wgetch(stdscr);
        return m_last_char == ERR ? -1 : m_last_char;
}
