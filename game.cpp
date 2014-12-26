#include "game.h"
#include <unistd.h>

Game::Game(Term *gameTerminal)
: m_terminal(gameTerminal), m_status_bar(nullptr), m_world_screen(nullptr), m_state(GameState::RUNNING) {

}

Game::~Game() {
}

void Game::init() {
        struct TermSize term_size = m_terminal->get_size();
        m_status_bar = m_terminal->new_window(3,term_size.x-1,term_size.y-3, 0);
        m_world_screen = m_terminal->new_window(term_size.y-3,term_size.x-1,0,0);
}
void Game::cleanup() {
}
void Game::redraw() {
        m_world_screen->refresh();
        m_status_bar->refresh();
}

void Game::loop() {
        while(m_state == GameState::RUNNING) {
                redraw();
        }
}
