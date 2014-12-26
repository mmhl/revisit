#include <locale.h>
#include <iostream>
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include <sstream>
#include "term.h"
#include "game.h"

int main() {
        setlocale(LC_ALL, "");
        /*
         * Not sure if this is ok to create term context here, instead in game.
         * This will relieve Game class to cleanup after Term.
         */
        Game new_game;
        new_game.init();
        new_game.loop();
        return 0;
}

