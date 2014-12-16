#ifndef __TERM_H__
#define __TERM_H__
#include <ncurses.h>
#include <string>
struct TermSize {
        int y;
        int x;
};
class Term  {
public:
        Term();
        virtual ~Term();
        void term_init(); 
        void term_end();
        void term_print(std::string word);
        char term_getch();
        TermSize term_get_size();
private:
        WINDOW *term_window;
        TermSize term_size;
};
#endif
