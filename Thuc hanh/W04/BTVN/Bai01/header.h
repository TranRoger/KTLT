#pragma once

#include <iostream>

using namespace std;

struct Fraction {
    int _num;
    int _den;

    // constructor
    Fraction() {
        _num = 0;
        _den = 1;
    }

    Fraction(int num, int den) {
        _num = num;
        _den = den;
    }

    // operation
    Fraction operator+ (const Fraction&);
    Fraction operator- (const Fraction&);
    Fraction operator* (const Fraction&);
    Fraction operator/ (const Fraction&);
    Fraction& operator= (const Fraction&);
    bool operator> (const Fraction&);
    bool operator==(const Fraction&);

    Fraction simplify();
};

Fraction scanner();
int gcd(const int &, const int &);