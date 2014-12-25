#ifndef __WORLD_H__
#define __WORLD_H__
#include "term.h"
#include "entity.h"
#include <vector>

class WorldDisplay {
public:
        WorldDisplay(Win *win);
        virtual ~WorldDisplay();
        int add_entity(Entity *entity);
        int redraw(bool all = false);
private:
        std::vector<Entity *> objects; 
        Win *window;
};
#endif
