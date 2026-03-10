# Tic-Tac-Toe with Minimax AI

A console-based Tic-Tac-Toe game featuring an AI opponent that plays optimally using the Minimax algorithm.

## Features

- Play against an unbeatable AI
- Clean console interface with visual board
- Input validation and error handling
- Can play multiple games in one session
- AI uses Minimax algorithm for optimal play

## The Minimax Algorithm

This project implements the Minimax algorithm, a decision-making algorithm commonly used in two-player games.

**How it works:**
- Recursively explores all possible game states
- Evaluates end states (win/loss/draw)
- Assumes both players play optimally
- Chooses moves that maximize AI's chances while minimizing opponent's

**Performance:**
- Time Complexity: O(b^d) where b = branching factor, d = depth
- Space Complexity: O(d) for recursion stack
- For Tic-Tac-Toe: Explores up to 362,880 game states

## Quick Start

**Compile:**
```bash
g++ -std=c++11 main.cpp -o tictactoe
```

**Run:**
```bash
./tictactoe
```

**Or using Make:**
```bash
make
./tictactoe
```

## How to Play

Enter numbers 1-9 to place your mark (X):

```
 1 | 2 | 3
-----------
 4 | 5 | 6
-----------
 7 | 8 | 9
```

The AI plays as O and will respond to your moves.

**Note:** With perfect play from both sides, Tic-Tac-Toe always results in a draw. The AI plays perfectly, so the best you can achieve is a tie!

## Project Structure

```
TicTacToe Class
├── Game Board Management
│   ├── initializeBoard()
│   ├── displayBoard()
│   └── isBoardFull()
├── Game Logic
│   ├── checkWin()
│   ├── makeMove()
│   └── getPlayerMove()
└── AI Logic
    ├── minimax() - Recursive decision algorithm
    ├── findBestMove() - Selects optimal move
    └── getAvailableMoves() - Returns valid positions
```

## Technologies

- C++11
- Standard Template Library (STL)
- Object-Oriented Programming

## What I Learned

**C++ Concepts:**
- Classes and object-oriented design
- Recursion and backtracking
- Vectors for dynamic data
- 2D array manipulation
- Input validation with error handling

**Algorithm Concepts:**
- Game tree search
- Recursive decision-making
- Win condition detection
- Optimal move calculation

## Possible Improvements

- Implement Alpha-Beta pruning for better performance
- Add difficulty levels (easy/medium/hard)
- Track game statistics
- Create a GUI version
- Support different board sizes (4x4, 5x5)

## License

MIT License - feel free to use and modify
