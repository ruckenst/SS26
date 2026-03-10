#include "Board.h"
#include <iostream>

Board::Board() {
    cursorPosition = {0, 0};
    isPlayerOneTurn = true;

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            boardData[x][y] = Empty;
        }
    }
}

void Board::print() const {
    std::cout << "===========" << std::endl;
    for (int y = 0; y < 3; y++) {
        std::cout << "|";
        for (int x = 0; x < 3; x++) {
            bool isCursorField = cursorPosition.x == x &&
                    cursorPosition.y == y;

            std::cout << (isCursorField ? "[" : " ");
            printTile(boardData[x][y]);
            std::cout << (isCursorField ? "]" : " ");
        }

        std::cout << "|" << std::endl;
    }
    std::cout << "===========" << std::endl;
}

void Board::printTile(const Tile tile) const {
    switch (tile) {
        case Circle:
            std::cout << "\033[34m" << "O" << "\033[0m";
            break;
        case Cross:
            std::cout << "\033[31m" << "X" << "\033[0m";
            break;
        default:
            std::cout << " ";
    }
}

void Board::moveUp() {
    if (cursorPosition.y <= 0) {
        return;
    }

    cursorPosition.y--;
}

void Board::moveDown() {
    if (cursorPosition.y >= 2) {
        return;
    }

    cursorPosition.y++;
}

void Board::moveLeft() {
    if (cursorPosition.x <= 0) {
        return;
    }

    cursorPosition.x--;
}

void Board::moveRight() {
    if (cursorPosition.x >= 2) {
        return;
    }

    cursorPosition.x++;
}

void Board::select() {
    if(boardData[cursorPosition.x][cursorPosition.y] != Empty) {
        std::cout << "Hey, this field is already occupied!" << std::endl;
        return;
    }

    boardData[cursorPosition.x][cursorPosition.y] = isPlayerOneTurn ? Circle : Cross;
    isPlayerOneTurn = !isPlayerOneTurn;
}

int Board::getWinner() const {
    for(int i = 0; i < 3; i++) {
        if(boardData[0][i] != Empty &&
            boardData[0][i] == boardData[1][i] &&
            boardData[1][i] == boardData[2][i]) {
            return boardData[0][i];
        }

        if(boardData[i][0] != Empty &&
           boardData[i][0] == boardData[i][1] &&
           boardData[i][1] == boardData[i][2]) {
            return boardData[0][i];
        }
    }

    if(boardData[1][1] != Empty &&
            ((boardData[0][0] == boardData[1][1]
              && boardData[1][1] == boardData[2][2]) ||
             (boardData[2][0] == boardData[1][1] &&
              boardData[1][1] == boardData[0][2]))) {
        return boardData[1][1];
    }

    return 0;
}

bool Board::isFull() const {
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if(boardData[x][y] == Empty) {
                return false;
            }
        }
    }

    return true;
}

bool Board::isComplete() const {
    return isFull() || getWinner() != 0;
}
