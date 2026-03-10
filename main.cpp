#include <iostream>
#include "Board.h"

int main() {
    Board myBoard;

    while(!myBoard.isComplete()) {
        // system("CLS"); <- Windows
        system("CLEAR"); // <- Linux

        myBoard.print();

        char input;
        std::cout << "Input: ";
        std::cin >> input;

        switch(input){
            case 'W':
            case 'w':
                myBoard.moveUp();
                break;
            case 'A':
            case 'a':
                myBoard.moveLeft();
                break;
            case 'S':
            case 's':
                myBoard.moveDown();
                break;
            case 'D':
            case 'd':
                myBoard.moveRight();
                break;
            case 'F':
            case 'f':
                myBoard.select();
                break;
            default:
                std::cout << "Invalid Input!" << std::endl;
        }
    }

    // system("CLS"); <- Windows
    system("CLEAR"); // <- Linux
    myBoard.print();

    int winner = myBoard.getWinner();
    if(winner == 0) {
        std::cout << "No winner could be determined" << std::endl;
    } else {
        std::cout << "Player " << winner << " has won!" << std::endl;
    }

    return 0;
}