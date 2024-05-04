#include <iostream>
#include "header.h"
#include <string>
#include <regex>

using namespace std;

// utilities
int gcd(const int &a, const int &b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

Fraction scanner() {
    string buffer; // handle user input
    regex fractionPattern("\\d+/\\d+"); // fraction pattern
    string num, den;
    do { // create an infinite loop to handle input
        getline(cin, buffer);
        if (buffer.size() == 0) { // if user enter nothing, require entering again
            cout << "Cannot leave blank!" << endl;
            continue;
        }
        bool match = regex_match(buffer, fractionPattern); // check if user input is in right pattern
        if (!match) {
            cout << "Invalid input! Your input: " << buffer << endl;
            cout << "Valid input pattern: a/b" << endl;
            continue;
        }

        int seperator = buffer.find('/'); // find '/' in buffer to seperate numerator and denominator
        num = buffer.substr(0, seperator);
        den = buffer.substr(seperator + 1, buffer.size() - seperator - 1);
        if (stoi(den) == 0) {
            cout << "Denominator cannot be zero." << endl;
            continue;
        }
        else break;
    } while (true);

    Fraction fraction(stoi(num), stoi(den));
    return fraction;
}

// operation
Fraction Fraction::operator+(const Fraction &another) {
    Fraction result;
    result._num = _num * another._den + another._num * _den;
    result._den = _den * another._den;
    result = result.simplify();
    return result;
}

Fraction Fraction::operator-(const Fraction &another) {
    Fraction result;
    result._num = _num * another._den - another._num * _den;
    result._den = _den * another._den;
    result = result.simplify();
    return result;
 }

Fraction Fraction::operator*(const Fraction &another) {
    Fraction result;
    result._num = _num * another._num;
    result._den = _den * another._den;
    result = result.simplify();
    return result;
}

Fraction Fraction::operator/(const Fraction &another) {
    Fraction result;
    result._num = _num * another._den;
    result._den = _den * another._num;
    result = result.simplify();
    return result;
}

Fraction &Fraction::operator=(const Fraction &another) {
    _num = another._num;
    _den = another._den;
    return *this;
}

bool Fraction::operator>(const Fraction &another) {
    return (_num * another._den > another._num * _den);
}

bool Fraction::operator==(const Fraction &another) {
    return (_num == another._num && _den == another._den);
}

Fraction Fraction::simplify() {
    Fraction result;
    int common = gcd(_num, _den);
    result._num = _num / common;
    result._den = _den / common;
    return result;
}