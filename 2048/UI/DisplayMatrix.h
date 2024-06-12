#pragma once

#include <iostream>
#include <Windows.h>
#include <string>
#include "../Object/Matrix.h"
#include "../Helper/string.h"

using std::cout, std::endl, std::string;

class DisplayMatrix {
public:
    static void display(const Matrix &);
    static void hline(const int &);
};