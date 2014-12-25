#include "world.h"
#include "entity.h"

WorldDisplay::WorldDisplay(Win *win)
: window(win) {
}
WorldDisplay::~WorldDisplay() {
        window = nullptr;
}
int WorldDisplay::add_entity(Entity *ent) {
       objects.push_back(ent);
       return 0;
}
int WorldDisplay::redraw(bool all) {
        int i = 0;
        if(all)
                window->erase();
        for(Entity *ent : objects) {
                auto pos = ent->get_position();
                auto symbol = ent->get_glyph();
                window->print_at(symbol, pos.y,pos.x);
                i++;
        }
        window->refresh();
        return i;
}
