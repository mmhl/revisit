#include "keyboard.h"
#include "term.h"

Keyboard::Keyboard(Term &term, bool blocking)
: m_last_char(-1), m_terminal(term), m_key_queue(), m_running(false) {
}
Keyboard::~Keyboard() {
        stop();
}

void Keyboard::set_delay(int tenths) {
        if(m_terminal.set_delay(tenths) == -1) {
                fatal("Bad delay value for keyboard");
        }
}
int Keyboard::get() {
        m_last_char = getch();
        return m_last_char == ERR ? 0 : m_last_char;
}
void Keyboard::start() {
        m_running = true;
        m_thread = std::thread(&Keyboard::thread_loop, this);
}
void Keyboard::stop() {
        m_running = false;
        if(m_thread.joinable())
                m_thread.join();
}
void Keyboard::thread_loop() {
        while(m_running== true) {
                int q = get(); 
                if(q)
                        m_key_queue.push(q);
        }
}

int Keyboard::poll_key(int &val) {
        if(!m_key_queue.empty()) {
                val = m_key_queue.front();
                m_key_queue.pop();
                return 1;
        }
        return 0;
}
