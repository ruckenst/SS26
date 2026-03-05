#include "Colors.h"

std::string getColorCode(Color color) {
    switch(color) {
        case Red:
            return RED;
        case Blue:
            return BLUE;
        case Green:
            return GREEN;
        default:
            return YELLOW;
    }
}

Color charToColor(char character){
    switch(character) {
        case 'r':
            return Red;
        case 'b':
            return Blue;
        case 'g':
            return Green;
        default:
            return Yellow;
    }
}
