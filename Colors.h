#ifndef SS26_COLORS_H
#define SS26_COLORS_H

#define RESET "\033[0m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

#include <string>

enum Color {
    Red,
    Blue,
    Green,
    Yellow
};

std::string getColorCode(Color color);
Color charToColor(char character);

#endif //SS26_COLORS_H
