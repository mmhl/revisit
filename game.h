#ifndef __GAME_H__
#define __GAME_H__
#include "term.h"
#include "Win.h"
#include "keyboard.h"
#include <memory>
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
        unique_ptr<Win> m_status_bar;
        unique_ptr<Win> m_world_screen;
        GameState m_state;
        Keyboard m_controller;
};
#endif
