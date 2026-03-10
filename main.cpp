/*
 * Tic-Tac-Toe with AI (Minimax Algorithm)
 * Author: Mohammed Abbas
 * 
 * A console-based Tic-Tac-Toe game featuring:
 * - Human vs AI gameplay
 * - Minimax algorithm for optimal AI moves
 * - Clean object-oriented design
 * - Input validation and error handling
 * 
 * This project demonstrates understanding of:
 * - C++ fundamentals (classes, functions, arrays)
 * - Game tree algorithms (Minimax)
 * - Recursion and backtracking
 * - Problem-solving and logic
 */

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char humanPlayer;
    char aiPlayer;
    
    // Initialize empty board
    void initializeBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
    }
    
    // Display the current board state
    void displayBoard() {
        cout << "\n";
        cout << "     |     |     \n";
        cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "\n";
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "\n";
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "\n";
        cout << "     |     |     \n\n";
    }
    
    // Display board with position numbers for user reference
    void displayGuide() {
        cout << "\nPosition Guide:\n";
        cout << "     |     |     \n";
        cout << "  1  |  2  |  3  \n";
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  4  |  5  |  6  \n";
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  7  |  8  |  9  \n";
        cout << "     |     |     \n\n";
    }
    
    // Check if a player has won
    bool checkWin(char player) {
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
                return true;
        }
        
        // Check columns
        for (int j = 0; j < 3; j++) {
            if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
                return true;
        }
        
        // Check diagonals
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
            return true;
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
            return true;
        
        return false;
    }
    
    // Check if board is full (draw)
    bool isBoardFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ')
                    return false;
            }
        }
        return true;
    }
    
    // Get all available moves
    vector<pair<int, int>> getAvailableMoves() {
        vector<pair<int, int>> moves;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    moves.push_back({i, j});
                }
            }
        }
        return moves;
    }
    
    // Minimax algorithm for optimal AI moves
    // Returns the best score for the current player
    int minimax(bool isMaximizing) {
        // Base cases: check for terminal states
        if (checkWin(aiPlayer)) return 10;
        if (checkWin(humanPlayer)) return -10;
        if (isBoardFull()) return 0;
        
        if (isMaximizing) {
            // AI's turn - maximize score
            int bestScore = -1000;
            vector<pair<int, int>> moves = getAvailableMoves();
            
            for (auto move : moves) {
                board[move.first][move.second] = aiPlayer;
                int score = minimax(false);
                board[move.first][move.second] = ' ';
                bestScore = max(score, bestScore);
            }
            return bestScore;
        } else {
            // Human's turn - minimize score
            int bestScore = 1000;
            vector<pair<int, int>> moves = getAvailableMoves();
            
            for (auto move : moves) {
                board[move.first][move.second] = humanPlayer;
                int score = minimax(true);
                board[move.first][move.second] = ' ';
                bestScore = min(score, bestScore);
            }
            return bestScore;
        }
    }
    
    // Find the best move for AI using Minimax
    pair<int, int> findBestMove() {
        int bestScore = -1000;
        pair<int, int> bestMove = {-1, -1};
        
        vector<pair<int, int>> moves = getAvailableMoves();
        
        for (auto move : moves) {
            board[move.first][move.second] = aiPlayer;
            int score = minimax(false);
            board[move.first][move.second] = ' ';
            
            if (score > bestScore) {
                bestScore = score;
                bestMove = move;
            }
        }
        
        return bestMove;
    }
    
    // Make a move on the board
    bool makeMove(int position, char player) {
        int row = (position - 1) / 3;
        int col = (position - 1) % 3;
        
        if (position < 1 || position > 9 || board[row][col] != ' ') {
            return false;
        }
        
        board[row][col] = player;
        return true;
    }
    
    // Get valid input from user
    int getPlayerMove() {
        int position;
        while (true) {
            cout << "Enter your move (1-9): ";
            
            if (cin >> position) {
                if (position >= 1 && position <= 9) {
                    int row = (position - 1) / 3;
                    int col = (position - 1) % 3;
                    
                    if (board[row][col] == ' ') {
                        return position;
                    } else {
                        cout << "That position is already taken! Try again.\n";
                    }
                } else {
                    cout << "Invalid input! Enter a number between 1 and 9.\n";
                }
            } else {
                cout << "Invalid input! Enter a number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
    
public:
    TicTacToe(char human, char ai) : humanPlayer(human), aiPlayer(ai) {
        initializeBoard();
    }
    
    // Main game loop
    void play() {
        cout << "\n========================================\n";
        cout << "  TIC-TAC-TOE WITH AI (Minimax)\n";
        cout << "  By Mohammed Abbas\n";
        cout << "========================================\n";
        
        cout << "\nYou are '" << humanPlayer << "'\n";
        cout << "AI is '" << aiPlayer << "'\n";
        
        displayGuide();
        
        bool gameOver = false;
        bool humanTurn = true;
        
        while (!gameOver) {
            displayBoard();
            
            if (humanTurn) {
                cout << "Your turn!\n";
                int move = getPlayerMove();
                makeMove(move, humanPlayer);
            } else {
                cout << "AI is thinking...\n";
                pair<int, int> bestMove = findBestMove();
                board[bestMove.first][bestMove.second] = aiPlayer;
                cout << "AI placed at position " << (bestMove.first * 3 + bestMove.second + 1) << "\n";
            }
            
            // Check for win
            if (checkWin(humanPlayer)) {
                displayBoard();
                cout << "🎉 Congratulations! You won!\n";
                gameOver = true;
            } else if (checkWin(aiPlayer)) {
                displayBoard();
                cout << "😔 AI wins! Better luck next time.\n";
                gameOver = true;
            } else if (isBoardFull()) {
                displayBoard();
                cout << "🤝 It's a draw!\n";
                gameOver = true;
            }
            
            humanTurn = !humanTurn;
        }
        
        cout << "\n========================================\n";
        cout << "Thanks for playing!\n";
        cout << "========================================\n\n";
    }
};

int main() {
    char playAgain;
    
    do {
        TicTacToe game('X', 'O');
        game.play();
        
        cout << "Play again? (y/n): ";
        cin >> playAgain;
        
    } while (playAgain == 'y' || playAgain == 'Y');
    
    cout << "Goodbye!\n";
    
    return 0;
}
