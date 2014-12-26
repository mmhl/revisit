#ifndef __GAME_H__
#define __GAME_H__
#include "term.h"
#include "object.h"
#include "keyboard.h"

enum class GameState {
        RUNNING,
        PAUSED,
        EXITING
};
class Game {
public:
        Game();
        ~Game();
        void init();
        void cleanup();
        void redraw();
        void loop();
private:
        Term m_terminal; // Some kind of context
        Win *m_status_bar;
        Win *m_world_screen;
        GameState m_state;
        Object m_test_player; // TEMP
        Keyboard m_controller;
};
#endif
