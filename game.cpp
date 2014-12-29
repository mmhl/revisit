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
        m_test_player.set_win(m_world_screen);
        m_test_player.set_pos(2,3);
        m_test_player.set_glyph('@');
        m_controller.set_delay(1);
        m_controller.start();
}
void Game::cleanup() {
        m_status_bar->print("Waiting for keyboard controller to finish");
        redraw();
        m_controller.stop();
        m_status_bar->print("Keyboard controller stopped");
        redraw();
        m_terminal.end();
}
void Game::redraw() {
        m_world_screen->refresh();
        m_status_bar->refresh();
}

void Game::loop() {
        while(m_state == GameState::RUNNING) {
                int key;
                if(m_controller.poll_key(key))  {
                        m_status_bar->print((char)key);
                        if(key == 'q') 
                                m_state = GameState::EXITING;
                }
                redraw();
        }
        m_status_bar->print("Exiting");
        redraw();
}
