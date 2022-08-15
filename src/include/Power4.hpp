#include <iostream>
#include <vector>
//#include <fstream>

class Power4 {
    private:
    protected:
        char player1 = 'X';
        char player2 = 'O';
        char grid[7][6] = {{' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '}};
        char choices[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
        std::string winner = "";
    
    public:
    Power4() {
    }
    ~Power4() {
    }

    void show_game();
    int ask_for_entry(int player_num);
    int get_line(int column_index);
    void update_column(int choice_index, int player_num);
    bool win_check_handler(int col, int row);
    bool row_win_check(std::vector<char> row);
    std::vector<char> get_diag_up(int col, int row);
    std::vector<char> get_diag_do(int col, int row);
    std::vector<char> get_column(int col);
    std::vector<char> get_row(int row);
};
