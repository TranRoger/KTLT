#include <iostream>
#include <random>
#include "header.h"

using namespace std;

int main() {
    srand(time(nullptr));

    int size = rand() % 20;
    int *array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }

    cout << "Array: ";
    printArray(array, size, 0);
    cout << endl << endl;
    int a = rand() % 10, b = rand() % 10;
    cout << a << "^" << b << " = " << power(a, b) << endl << endl;
    cout << "Sum of array: " << sum(array, size, 0) << endl;

    return 0;
}