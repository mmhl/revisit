#ifndef __OBJECT_H__
#define __OBJECT_H__
#include "term.h"
#include "Win.h"
#include "draw.h"

class Object : public IDrawable {
public:
        Object(Win *on_window, int init_y, int init_x, char glyph);
        virtual ~Object();
        virtual void draw();
        void set_win(Win *win);
        void set_pos(int pos_y, int pos_x);
        void set_glyph(char glyph);
protected:
        int m_pos_y, m_pos_x;
        bool m_live; // Can this object do living things?
        char m_glyph; // TODO: char for now
        Win *m_window;
};
#endif
