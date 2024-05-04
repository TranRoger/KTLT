#include <iostream>
#include "header.h"
using namespace std;

int main() {
    cout << "Fraction a: ";
    Fraction a = scanner();
    cout << "Fraction b: ";
    Fraction b = scanner();
    Fraction add = (a + b);
    Fraction sub = (a - b);
    Fraction mul = (a * b);
    Fraction div = (a / b);
    cout << a._num << "/" << a._den << " + " << b._num << "/" << b._den << " = " << add._num << "/" << add._den << endl;
    cout << a._num << "/" << a._den << " - " << b._num << "/" << b._den << " = " << sub._num << "/" << sub._den << endl;
    cout << a._num << "/" << a._den << " * " << b._num << "/" << b._den << " = " << mul._num << "/" << mul._den << endl;
    cout << a._num << "/" << a._den << " / " << b._num << "/" << b._den << " = " << div._num << "/" << div._den << endl;
    Fraction sA = a.simplify();
    cout << endl << "Simplified a = " << sA._num << "/" << sA._den << endl;
    if (b == b.simplify()) {
        cout << "b is simplified." << endl;
    }
    else {
        cout << "b is not simplified." << endl;
    }

    if (a > b) {
        cout << a._num << "/" << a._den << " > " << b._num << "/" << b._den << endl;
    }
    else {
        cout << b._num << "/" << b._den << " > " << a._num << "/" << a._den << endl;
    }

    return 0;
}