#include <locale.h>
#include <iostream>
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include <sstream>
//TESTING
#include "term.h"
#include "TermWin.h"
//TESTING
#include "game.h"

int main() {
        setlocale(LC_ALL, "");
        /*
         * Not sure if this is ok to create term context here, instead in game.
         * This will relieve Game class to cleanup after Term.
         */
        //Game new_game;
        //new_game.init();
        //new_game.loop();
        //new_game.cleanup();
        Term term;
        term.init();
        TermWin win1(0, 0, 10, 10);
        auto win2 = win1.create_children_win(1, 1, 3, 5, true);
        win1.refresh();
        win2.refresh();
        win1.put_char_at('1', 0, 0);
        win2.put_char_at('2', 0, 0);
        win1.refresh();
        win2.refresh();
        sleep(1);
        win2.del_win();
        win1.refresh();
        sleep(1);
        return 0;
}

