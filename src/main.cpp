#include "include/Power4.hpp"

int main() {
    Power4 Game;    int max_turns = 42;

    for (int i = 0; i < max_turns; i++) {
        int currentPlayer = i % 2 + 1;
        int col = Game.ask_for_entry(currentPlayer);
        int row = Game.update_column(col, currentPlayer);
        Game.show_game();
        if (Game.win_check_handler(col, row)) {
            std::cout << "Player " << i % 2 + 1 << " wins!" << std::endl;
            return 0;
        }
    }

    return 0;
}
