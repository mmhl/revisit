#include "keyboard.h"
#include "term.h"

Keyboard::Keyboard(Term &term, bool blocking)
: m_last_char(-1), m_terminal(term), m_key_queue() {
}
Keyboard::~Keyboard() {
}

void Keyboard::set_delay(int tenths) {
        if(m_terminal.set_delay(tenths) == -1) {
                fatal("Bad delay value for keyboard");
        }
}
int Keyboard::get() {
        m_last_char = getch();
        return m_last_char == ERR ? -1 : m_last_char;
}
