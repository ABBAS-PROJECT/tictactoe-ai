# Makefile for Tic-Tac-Toe with AI
# Author: Mohammed Abbas

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = tictactoe
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
	@echo "Build successful! Run with: ./$(TARGET)"

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
	@echo "Cleaned build artifacts"

rebuild: clean all

.PHONY: all run clean rebuild
