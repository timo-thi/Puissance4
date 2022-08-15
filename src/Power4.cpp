#include "include/Power4.hpp"

void Power4::show_game() {
    std::cout << "  a ° b ° c ° d ° e ° f ° g \n";
    for (int i = 5; i > -1; i--) {
        std::cout << "| ";
        for (int j = 0; j < 7; j++) {
            std::cout << grid[j][i] << " | ";
        }
        std::cout << "\n";
    }
    std::cout << "show_game_end\n";

    return;
}

int Power4::ask_for_entry(int player_num) {
    char choice;
    int choice_index = -1;
    do {
        std::cout << "Joueur " << player_num << ", quel colonne : ";
        std::cin >> choice;
        for (int i = 0; i < 7; i++) {
            if (choices[i] == choice) {
                if (get_line(i) != -1) {
                    choice_index = i;
                }
            }
        }
    } while (choice_index == -1);
    std::cout << "Tu as choisi" << choice << ", (i:" << choice_index << ")\n(position : " << get_line(choice_index) << ")\n";

    return choice_index;
}

int Power4::get_line(int column_index) {
    for (int i = 0; i < 6; i++) {
        if (grid[column_index][i] == ' ') {
            return i;
        }
    }
    return -1;
}

void Power4::update_column(int choice_index, int player_num) {
    if (player_num == 1) {
        grid[choice_index][get_line(choice_index)] = player1;
    } else if (player_num == 2) {
        grid[choice_index][get_line(choice_index)] = player2;
    } else {
        printf("update_column error, player is not 1 or 2.");
    }
}

bool Power4::win_check_handler(int col, int row) {
    std::cout << "win_check_handler in";
    std::vector<char> line = get_row(row);
    std::vector<char> column = get_column(col);
    std::vector<char> diag_up = get_diag_up(col, row);
    std::vector<char> diag_do = get_diag_do(col, row);

    return row_win_check(line) || row_win_check(column) || row_win_check(diag_up) || row_win_check(diag_do);
}

bool Power4::row_win_check(std::vector<char> row) {
    if (row.size() >= 4) {
        for (int i = 0; i < (int)row.size() - 3; i++) {
            if (row[i] != ' ' && row[i] == row[i+1] && row[i] == row[i+2] && row[i] == row[i+3]) {
                return true;
            }
        }
        return false;
    } else {
        return false;
    }
}

std::vector<char> Power4::get_diag_up(int col, int row) {
    int lini;
    int coli;
    int nb_v;
    if (col < row) {
        lini = 0;
        coli = row - col;
        nb_v = 6 - coli;
    } else if (col > row) {
        coli = 0;
        lini = col - row;
        nb_v = 7 - lini;
    } else {
        coli = 0;
        coli = 0;
        nb_v = 6;
    }

    std::vector<char> diag_up;
    for (int i = 0; i < nb_v; i++) {
        diag_up.push_back(grid[lini+i][coli+i]);
    }

    return diag_up;
}

std::vector<char> Power4::get_diag_do(int col, int row) {
    int lini;
    int coli;
    int nb_v;

    if (col + row <= 5) {
        lini = 0;
        coli = col - row;
        nb_v = coli + 1;
    } else {
        coli = 5;
        lini = col - (coli - row);
        nb_v = 7 - lini;
    }

    std::vector<char> diag_do;
    for (int i = 0; i < nb_v; i++) {
        diag_do.push_back(grid[lini+i][coli-i]);
    }

    return diag_do;
}

std::vector<char> Power4::get_column(int col) {
    std::vector<char> column;
    for (int i = 0; i < 6; i++) {
        column.push_back(grid[col][i]);
    }

    return column;
}

std::vector<char> Power4::get_row(int row) {
    std::vector<char> line;
    for (int i = 0; i < 6; i++) {
        line.push_back(grid[i][row]);
    }
    std::cout << "ok";
    return line;
}
