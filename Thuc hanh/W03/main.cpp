#include <iostream>
using namespace std;

#include "header.h"

int main() {
    // ex1
    int row, col;
    cout << "Number of rows: ";
    cin >> row;
    cout << "Number of columns: ";
    cin >> col;
    int** array = twoDimArray(row, col);
    printTwoDimArray(array, row, col);
    // ex2
    checkAscending(array, row, col);
    // ex3
    int** trans = transpose(array, row, col);
    cout << "Transpose matrix:" << endl;
    printTwoDimArray(trans, col, row);
    // ex4
    cout << "Sum: " << endl;
    int** result = doubleUp(array, row, col);
    printTwoDimArray(result, row, col);
    // ex5
    if (isSymmetric(array, row, col)) {
        cout << "Array is symmetric." << endl;
    }
    else {
        cout << "Array is not symmetric." << endl;
    }
    // ex6
    array = deleteColumn(array, row, col);
    cout << "Array after delete:" << endl;
    printTwoDimArray(array, row, col);
    // free memory
    trashCollector(array, row);
    trashCollector(trans, col);
    trashCollector(result, row);

    return 0;
}