#include "game.h"
#include "TermWin.h"
#include <unistd.h>

Game::Game()
: m_terminal(), m_status_bar(nullptr), m_world_screen(nullptr), m_state(GameState::RUNNING), m_controller(m_terminal) {
}

Game::~Game() {
}


//Create class that contains all objects, and can draw them on Win ???
void Game::init() {
        m_terminal.init();
        struct TermSize term_size = m_terminal.get_size();
        m_controller.set_delay(0);
}
void Game::cleanup() {
        m_terminal.end();
}
void Game::redraw() {
        m_world_screen->refresh();
        m_status_bar->refresh();
}

void Game::loop() {
        while(m_state == GameState::RUNNING) {
                int key = m_controller.get();
                if(key == 'q')
                        m_state= GameState::EXITING;
                if(key != -1)
                        m_status_bar->print(key);
                redraw();
        }
}
