#include "game.h"
#include "TermWin.h"
#include <unistd.h>
#include <sstream>

Game::Game() :
m_terminal(), m_status_bar(nullptr),
m_world_screen(nullptr), m_state(GameState::RUNNING),
m_controller(m_terminal) {
}

Game::~Game() {
}

//Create class that contains all objects, and can draw them on Win ???
void Game::init() {
	m_terminal.init();
	struct TermSize term_size = m_terminal.get_size();
	m_world_screen = unique_ptr<Window>(new Window(0, 0, 5, 5));
	m_status_bar = unique_ptr<Window>(new Window(7, 8, 5, 5));
	m_controller.set_delay(0);
}
void Game::cleanup() {
	m_terminal.end();
}
void Game::redraw() {
	m_world_screen->redraw();
	m_status_bar->redraw();
}

void Game::loop() {
	stringstream ss;
	while (m_state == GameState::RUNNING) {
		int key = m_controller.get();
		if (key == 'q')
			m_state = GameState::EXITING;
		else if (key != -1) {
			ss << key;
			m_status_bar->print(ss.str());
			m_world_screen->print(ss.str());
		}
		redraw();
	}
}
