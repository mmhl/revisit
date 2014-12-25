#ifndef __WORLD_H__
#define __WORLD_H__
#include "term.h"
#include <vector>
class WorldDisplay {
public:
        WorldDisplay(Win *window);
        void redraw(bool all = false);
private:
        //vector<Drawable *> objects; Drawable objects
        Win *window;
};
#endif
