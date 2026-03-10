# Tic-Tac-Toe with AI (Minimax Algorithm)

A console-based Tic-Tac-Toe game featuring an unbeatable AI opponent powered by the Minimax algorithm.

**Created by Mohammed Abbas** as a beginner C++ project to demonstrate understanding of algorithms and game theory for Chaos Camp 2026 application.

## 🎯 Purpose

This project was created to demonstrate:
- C++ programming fundamentals
- Understanding of recursive algorithms
- Game tree search implementation (Minimax)
- Clean code organization
- Problem-solving approach

## 🎮 Features

- **Human vs AI gameplay**
- **Unbeatable AI** using Minimax algorithm
- **Input validation** and error handling
- **Clear console interface** with visual board
- **Position guide** for easy gameplay
- **Play multiple games** without restarting

## 🧠 The Minimax Algorithm

The AI uses the **Minimax algorithm**, a classic decision-making algorithm for two-player games:

### How it works:

1. **Recursively explores** all possible game states
2. **Assumes** both players play optimally
3. **Evaluates** terminal states (win/loss/draw)
4. **Maximizes** AI's score while minimizing opponent's score
5. **Backtracks** to find the best move

### Pseudocode:
```
function minimax(is_maximizing):
    if game_over:
        return score
    
    if is_maximizing:
        best_score = -infinity
        for each available move:
            make move
            score = minimax(false)
            undo move
            best_score = max(best_score, score)
        return best_score
    else:
        best_score = +infinity
        for each available move:
            make move
            score = minimax(true)
            undo move
            best_score = min(best_score, score)
        return best_score
```

### Complexity:
- **Time Complexity:** O(b^d) where b = branching factor, d = depth
- **Space Complexity:** O(d) for recursion stack
- For Tic-Tac-Toe: Maximum 9! = 362,880 states to explore

## 🚀 How to Run

### Prerequisites
- C++ compiler (g++, clang++)
- Terminal/Command prompt

### Compilation & Execution

**Using Make:**
```bash
make
./tictactoe
```

**Manual compilation:**
```bash
g++ -std=c++11 main.cpp -o tictactoe
./tictactoe
```

**On Windows:**
```bash
g++ main.cpp -o tictactoe.exe
tictactoe.exe
```

## 📖 How to Play

1. Run the program
2. You play as **'X'**, AI plays as **'O'**
3. Enter a number **1-9** to place your mark:
   ```
   Position Guide:
    1 | 2 | 3
   -----------
    4 | 5 | 6
   -----------
    7 | 8 | 9
   ```
4. Try to get three in a row (horizontal, vertical, or diagonal)
5. The AI will play optimally - good luck winning! 😉

## 💡 Learning Outcomes

Building this project taught me:

### C++ Skills:
- **Classes and Objects** - OOP design
- **2D Arrays** - Board representation
- **Recursion** - Minimax implementation
- **Vectors** - Dynamic move storage
- **Input Validation** - Error handling
- **STL Usage** - `<limits>`, `<vector>`, `<iostream>`

### Algorithm Skills:
- **Game Tree Search** - Exploring all possibilities
- **Recursion & Backtracking** - Core to Minimax
- **Optimization** - Pruning unnecessary searches
- **Win Detection** - Pattern matching logic

### Problem-Solving:
- Breaking down complex problems
- Thinking recursively
- Designing clean interfaces
- Testing edge cases

## 🎓 Code Structure

```
main.cpp
├── TicTacToe Class
│   ├── Private Methods
│   │   ├── initializeBoard()      - Setup empty board
│   │   ├── displayBoard()         - Show current state
│   │   ├── checkWin()             - Detect winner
│   │   ├── minimax()              - AI decision algorithm
│   │   ├── findBestMove()         - Get optimal move
│   │   ├── makeMove()             - Execute move
│   │   └── getPlayerMove()        - Input validation
│   └── Public Methods
│       └── play()                 - Main game loop
└── main()                         - Entry point
```

## 🔄 Possible Improvements

Future enhancements I could add:
- **Alpha-Beta Pruning** - Optimize Minimax performance
- **Difficulty Levels** - Random moves for "easy" mode
- **Score Tracking** - Win/loss/draw statistics
- **Graphical Interface** - Using SFML or SDL
- **Different Board Sizes** - 4x4 or 5x5 variants
- **Network Play** - Multiplayer over TCP/IP

## 📚 Resources Used

I learned to implement Minimax from:
- "Artificial Intelligence: A Modern Approach" (Russell & Norvig)
- University algorithms course materials
- Online tutorials on game tree algorithms

## 👨‍💻 About This Project

**Why Tic-Tac-Toe?**

This is a beginner-level project that demonstrates solid understanding of:
- C++ fundamentals
- Recursive algorithms
- Game theory basics

It's **honest about my skill level** - I'm not claiming to be an expert, but showing I can:
1. Understand and implement classic algorithms
2. Write clean, organized C++ code
3. Solve problems methodically
4. Learn independently

**Created for:** Chaos Camp 2026 Application  
**Purpose:** Demonstrate C++ proficiency and algorithm knowledge  
**Level:** Beginner (learning computer graphics programming)

## 📝 License

This project is open source and available under the MIT License.

---

## 🔗 Connect

**Mohammed Abbas**
- Portfolio: [abbas-portfolio-zeta.vercel.app](https://abbas-portfolio-zeta.vercel.app/)
- GitHub: [@ABBAS-PROJECT](https://github.com/ABBAS-PROJECT)
- LinkedIn: [mohmmad-abbas](https://www.linkedin.com/in/mohmmad-abbas/)

---

**Note:** This is a learning project created as part of my application to Chaos Camp 2026. While I'm a beginner in C++ and computer graphics, I'm eager to learn and committed to mastering these skills through intensive training.
