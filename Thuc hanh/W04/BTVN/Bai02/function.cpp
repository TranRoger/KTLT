#include <iostream>
#include <math.h>
#include <string>
#include <regex>
#include "header.h"
using namespace std;

double Point::distance(const Point &another) const {
    return sqrt((another._x - _x) * (another._x - _x) + (another._y - _y) * (another._y - _y));
}

bool Point::onStraightLine(const Point &B, const Point &C) const {
    if ((_x == B._x && _x == C._x) || (_y == B._y && _y == C._y)) return true;
    return false;
}

Point Point::midPoint(const Point &another) const {
    Point mid((_x + another._x) / 2, (_y + another._y) / 2);
    return mid;
}

Point scanner() {
    Point result;
    regex pattern("\\d+");
    string buffer;
    do {
        cout << "x = ";
        getline(cin, buffer);
        if (buffer.size() == 0) {
            cout << "Cannot leave blank." << endl;
            continue;
        }
        bool match = regex_match(buffer, pattern);
        if (match) break;
        cout << "Invalid input." << endl;
    } while (true);
    result._x = stoi(buffer);
    buffer.erase();
    do {
        cout << "y = ";
        getline(cin, buffer);
        if (buffer.size() == 0) {
            cout << "Cannot leave blank." << endl;
            continue;
        }
        bool match = regex_match(buffer, pattern);
        if (match) break;
        cout << "Invalid input." << endl;
    } while (true);
    result._y = stoi(buffer);
    return result;
}