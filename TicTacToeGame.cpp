/*
TASK - 3
--------------TIC-TAC-TOE GAME-----------------
Build a simple console-based Tic-Tac-Toe game that
allows two players to play against each other

1.) Game Board: Create a 3x3 grid as the game board.
2.) Players: Assign "X" and "O" to two players.
3.) Display Board: Show the current state of the board.
4.) Player Input: Prompt the current player to enter their move.
5.) Update Board: Update the game board with the player's move.
6.) Check for Win: Check if the current player has won.
7.) Check for Draw: Determine if the game is a draw.
8.) Switch Players: Alternate turns between "X" and "O" players.
9.) Display Result: Show the result of the game (win, draw, or ongoing).
10.) Play Again: Ask if the players want to play another game.

*/


#include <iostream>
using namespace std;

void displayBoard(char board[3][3]) {
    cout << "-------------\n";
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char currentPlayer = 'X';

    do {
        displayBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (checkDraw(board)) {
            displayBoard(board);
            cout << "The game is a draw.\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

    } while (true);

    return 0;
}
