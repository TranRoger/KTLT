#pragma once

#include <iostream>
using namespace std;

struct Point {
    int _x;
    int _y;

    // constructor
    Point() : _x(0), _y(0) {}
    Point(const int &x, const int &y) : _x(x), _y(y) {}

    // operation
    double distance(const Point &) const;
    bool onStraightLine(const Point &, const Point &) const;
    Point midPoint(const Point &) const;
};

Point scanner();