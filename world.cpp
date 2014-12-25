#include "world.h"

WorldDisplay::WorldDisplay(Win *window)
: window(window) {
        
}
void WorldDisplay::redraw(bool all) {
        if(all)
                window->erase();
        window->refresh();
}
