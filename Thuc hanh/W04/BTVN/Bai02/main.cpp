#include <iostream>
#include "header.h"

using namespace std;

int main() {
    cout << "Point A: ";
    Point A = scanner();
    cout << "Point B: ";
    Point B = scanner();
    cout << "Point C: ";
    Point C = scanner();

    cout << "Distance from A to B: " << A.distance(B) << endl;
    if (A.onStraightLine(B, C)) {
        cout << "A, B and C is on a straight line." << endl;
    }
    else {
        cout << "A, B and C is not on a straight line." << endl;
    }
    Point mid = A.midPoint(B);
    cout << "Mid point between A and B: (" << mid._x << ";" << mid._y << ")" << endl;

    return 0;
}