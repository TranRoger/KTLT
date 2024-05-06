#pragma once

#include <iostream>
#include <iomanip>
#include <random>

using std::cin, std::cout, std::endl, std::setw, std::setfill;

struct Matrix {
    int _rows;
    int _columns;
    int **_matrix;

    // constructor
    Matrix(const int &n, const int &m) : _rows(n), _columns(m) {
        _matrix = new int*[_rows];
        for (int i = 0; i < _rows; i++) {
            _matrix[i] = new int[_columns];
            for (int j = 0; j < _columns; j++) {
                _matrix[i][j] = -1;
            }
        }
    }

    // operation
    int score();
    void addRandom();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    bool stuck();
    bool full();
};