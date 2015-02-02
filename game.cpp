#include "game.h"
#include "object.h"
#include <unistd.h>

Game::Game()
: m_terminal(), m_status_bar(nullptr), m_world_screen(nullptr), m_state(GameState::RUNNING), m_test_player(nullptr, 0,0,'x'), m_controller(m_terminal) {
}

Game::~Game() {
}

void Game::init() {
        m_terminal.init();
        struct TermSize term_size = m_terminal.get_size();
        m_status_bar = m_terminal.new_window(3,term_size.x-1,term_size.y-3, 0);
        m_world_screen = m_terminal.new_window(term_size.y-3,term_size.x-1,0,0);
        m_controller.set_delay(0);
        m_test_player.set_win(m_world_screen);
        m_test_player.set_pos(5,5);
        m_test_player.set_glyph('@');
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
                m_test_player.draw();
                redraw();
        }
}
