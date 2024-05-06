#pragma once

#include <iostream>
#include <Windows.h>
#include "HandleInput.h"

using std::cout, std::endl;

enum Color {
    Black = 0,
    LightBlue = 3,
    White = 15
};

void printMenu();
void modeChooser(int &, int &);