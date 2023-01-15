#include <iostream>

void display(char board[3][3]) {
    std::cout << "Tic Tac Toe" << "\n";
    std::cout << "-----------" << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << " " << board[i][j] << " ";
            if (j < 2) {
                std::cout << "|";
            }
        }
        std::cout << "\n";
        if (i < 2) {
            std::cout << "---|---|---" << "\n";
        }
    }
}

void play(int x, int y, char player, char board[3][3]) {
    if (x >= 0 && x < 3 && y >= 0 && y < 3 && board[x][y] == ' ') {
        board[x][y] = player;   
    }
}

bool checkWin(char board[3][3]) {
    // check for horizontal wins
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return true;
        }
    }

    // check for vertical wins
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return true;
        }
    }

    // check for diagonal wins
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return true;
    }
    return false;
}

int main() {

    char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
    };

    display(board);
    
    int x, y;
    char player = 'X';
    
    while (true) {
        std::cout << "Player " << player << ", enter your move (x y) with a space between x and y value: ";
        std::cin >> x >> y;
        play(x, y, player, board);
        display(board);
        if (checkWin(board)) {
            std::cout << "Player " << player << " wins!" << "\n";
            break;
        }
        
        if (player == 'X') {
            player = 'O';
        } else {
            player = 'X';
        }
        
    }
}

