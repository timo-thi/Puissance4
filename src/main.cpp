#include "include/Power4.hpp"

int main() {
    Power4 Game;
    Game.show_game();
    Game.update_column(Game.ask_for_entry(1), 1);
    Game.show_game();

    std::cout << "ok\n";

    std::cout << Game.win_check_handler(1, 1);
    // printf("size : %ld", sizeof(test));

    return 0;
}
