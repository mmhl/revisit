#include "object.h"
#include "err.h"

Object::Object(Win *draw_win, int init_y, int init_x, char glyph)
: m_window(draw_win), m_pos_y(init_y), m_pos_x(init_x), m_glyph(glyph) {

}
Object::~Object() {
        m_window = nullptr;
}
//default implementation
void Object::draw() {
        if(m_window == nullptr) 
                fatal("Null ptr in object window");
        m_window->print_at(m_glyph, m_pos_y, m_pos_x);
}
void Object::set_win(Win *win) {
        m_window = win;
}
void Object::set_pos(int pos_y, int pos_x) {
        m_pos_y = pos_y;
        m_pos_x = pos_x;
}
void Object::set_glyph(char glyph) {
        m_glyph = glyph;
}
