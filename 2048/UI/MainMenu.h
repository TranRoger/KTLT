#pragma once

#include <Windows.h>
#include "../KeyboardHandler/HandleInput.h"
#include "Color.h"

using std::cout, std::endl;

class MainMenu {
public:
    static void printMenu();
    static int modeChooser();
};