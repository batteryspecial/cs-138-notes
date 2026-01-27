#include <iostream>

void swap3 (int& x, int& y) {
    const int temp = x;
    x = y;
    y = temp;
    std::cout << x << " " << y << std::endl;
}