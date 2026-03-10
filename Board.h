#ifndef SS26_BOARD_H
#define SS26_BOARD_H

#include "Tile.h"
#include "Coordinate.h"

class Board {
public:
    Board();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void accept();
    int getWinner() const;
    bool isFull() const;
    bool isComplete() const;

    void print() const;

private:
    Tile boardData[3][3];
    Coordinate cursorPosition;
    bool isFirstPlayerTurn;

    void printTile(Tile tile) const;
};


#endif //SS26_BOARD_H
