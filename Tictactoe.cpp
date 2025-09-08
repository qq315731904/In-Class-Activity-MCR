#include <iostream>

const int BOARD_SIZE = 3;

// Display the game board
void displayBoard(char game[BOARD_SIZE][BOARD_SIZE]) {
    std::cout << "\nCurrent board:\n";
    std::cout << "  1 2 3\n";
    for (int i = 0; i < BOARD_SIZE; i++) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < BOARD_SIZE; j++) {
            std::cout << game[i][j];
            if (j < BOARD_SIZE - 1) std::cout << "|";
        }
        std::cout << std::endl;
        if (i < BOARD_SIZE - 1) std::cout << "  -+-+-\n";
    }
    std::cout << std::endl;
}



// Check if a player has won
bool isWin(char game[BOARD_SIZE][BOARD_SIZE], char player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (game[i][0] == player && game[i][1] == player && game[i][2] == player)
            return true;
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (game[0][j] == player && game[1][j] == player && game[2][j] == player)
            return true;
    }

    // Check diagonals
    if (game[0][0] == player && game[1][1] == player && game[2][2] == player)
        return true;

    if (game[0][2] == player && game[1][1] == player && game[2][0] == player)
        return true;

    return false;
}

// Check if the game is a tie
bool isTie(char game[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game[i][j] == ' ')
                return false; // There are still empty cells
        }
    }
    return true; // No empty cells, it's a tie
}

int main() {
    char game[BOARD_SIZE][BOARD_SIZE];

    // Initialize the game board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            game[i][j] = ' ';
        }
    }

    char player1 = 'X';
    char player2 = 'O';
    bool turn = false; // false for player 1's turn, true for player 2's turn

    std::cout << "Tic-Tac-Toe Game\n";
    std::cout << "X = Player 1\n";
    std::cout << "O = Player 2\n";

    displayBoard(game);

    while (true) {
        int i, j;
        char currentPlayer = turn ? player2 : player1;

        std::cout << "Player " << (turn ? "2" : "1") << " (" << currentPlayer << "): ";
        std::cout << "Enter position to mark (row[1..3] column[1..3]): ";

        // Get input
        std::cin >> i >> j;

        // Validate input
        if (std::cin.fail() || i < 1 || i > 3 || j < 1 || j > 3) {
            std::cin.clear(); // Clear error flags
            std::cin.ignore(10000, '\n'); // Ignore invalid input
            std::cout << "Invalid input! Please enter numbers between 1 and 3.\n";
            continue;
        }



       // Convert to 0-based index
        int row = i - 1;
        int col = j - 1;

        // Check if the position is already occupied
        if (game[row][col] != ' ') {
            std::cout << "This position is already occupied! Please choose another position.\n";
            continue;
        }

        // Place the mark
        game[row][col] = currentPlayer;
        displayBoard(game);

        // Check for win
        if (isWin(game, currentPlayer)) {
            std::cout << "Player " << (turn ? "2" : "1") << " wins!\n";
            break;
        }

        // Check for tie
        if (isTie(game)) {
            std::cout << "It's a tie!\n";
            break;
        }

        // Switch turns
        turn = !turn;
    }

    return 0;

}
