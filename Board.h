#ifndef SS26_BOARD_H
#define SS26_BOARD_H

#include "Tile.h"
#include "Coordinate.h"

class Board {
public:
    Board();

    void print() const;

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void select();

    int getWinner() const;
    bool isFull() const;
    bool isComplete() const;

private:
    Tile boardData[3][3];
    Coordinate cursorPosition;
    bool isPlayerOneTurn;

    void printTile(const Tile tile) const;
};

#endif //SS26_BOARD_H
