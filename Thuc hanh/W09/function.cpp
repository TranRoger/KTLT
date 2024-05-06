#include "header.h"

void printArray(int *array, const int &size, const int &index) {
    if (index == size) return;

    cout << array[index] << " ";
    printArray(array, size, index + 1);
}

int power(const int &a, const int &b) {
    if (0 == b) return 1;
    return a * power(a, b - 1);
}

int sum(int *array, const int &size, const int &index) {
    if (index == size - 1) return array[index];
    return array[index] + sum(array, size, index + 1);
}