#pragma once 

#include <iostream>
#include <conio.h>

using std::cout, std::endl;

enum Keys : int {
    Arrow = 224,
    Up = 72,
    Down = 80,
    Left = 75,
    Right = 77,
    Enter = 13
};

int next();