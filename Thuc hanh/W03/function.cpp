#include <iostream>
using namespace std;

#include "header.h"

// ex 1
int** twoDimArray(const int& rowNumber, const int& colNumber) {
    // initialize the dynamic array
    int** array = new int*[rowNumber];
    for (int i = 0; i < rowNumber; i++) {
        *(array + i) = new int[colNumber];
    }
    // asign value for array
    for (int i = 0; i < rowNumber; i++) {
        for (int j = 0; j < colNumber; j++) {
            cout << "array[" << i << "][" << j << "] = ";
            cin >> array[i][j];
        }
        cout << endl;
    }
    return array;
}

void printTwoDimArray(int** array, const int& rowNumber, const int& colNumber) {
    if (rowNumber == 0 && colNumber == 0) {
        cout << "Empty array" << endl;
        return;
    }
    // if array is not empty, print it to screen
    for (int i = 0; i < rowNumber; i++) {
        if (i == rowNumber / 2) {
            cout << "array = {";
        }
        else {
            cout << "        {";
        }
        for (int j = 0; j < colNumber; j++) {
            cout << array[i][j];
            if (j != colNumber - 1) {
                cout << " , ";
            }
        }
        cout << "}" << endl;
    }
}

// ex 2
int* indexArray(const int& size) {
    int * array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = -1;
    }
    return array;
}

void printRow(int** array, int* index, const int& rows, const int& cols) {
    if (*index == -1) {
        return;
    }
    int idx = 0;
    for (int i = 0; i < rows; i++) {
        if (i != idx) continue;
        for (int j = 0; j < cols; j++) {
            cout << array[i][j];
            if (j != cols - 1) {
               cout << " , ";
            }
        }
        idx++;
        cout << endl;
    }
    cout << endl;
}

void printColumn(int** array, int* index, const int& rows, const int& cols) {
    if (*index == -1) {
        return;
    }
    int idx = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j != index[idx]) continue;
            idx++;
            cout << array[i][j] << "   ";
        }
        idx = 0;
        cout << endl;
    }
    cout << endl;
}

void checkAscending(int** array, const int& rowNumber, const int& colNumber) {
    if (rowNumber == 0 && colNumber == 0) {
        cout << "Empty array." << endl;
        return;
    }
    // if array is not empty, check on row and column
    // check on row
    // create an array to store ascending row index
    int* ascRow = indexArray(rowNumber);
    int index = 0;
    for (int i = 0; i < rowNumber; i++) {
        bool asc = true;
        for (int j = 1; j < colNumber; j++) {
            if (array[i][j] < array[i][j - 1]) {
                asc = false;
                break;
            }
        }
        if (asc) {
            ascRow[index] = i;
            index++;
        }
    }
    index = 0;
    // check on column
    // create an array to store ascending column index
    int* ascCol = indexArray(colNumber);
    for (int i = 0; i < colNumber; i++) {
        bool asc = true;
        for (int j = 1; j < rowNumber; j++) {
            if (array[j][i] < array[j - 1][i]) {
                asc = false;
                break;
            }
        }
        if (asc) {
            ascCol[index] = i;
            index++;
        }
    }
    // print the result;
    cout << "Ascending rows: " << endl;
    printRow(array, ascRow, rowNumber, colNumber);
    cout << endl << "Ascending columns: " << endl;
    printColumn(array, ascCol, rowNumber, colNumber);
    cout << endl;
}

// ex 3
int** transpose(int** array, const int& rows, const int& cols) {
    if (rows == 0 || cols == 0) {
        cout << "Empty array." << endl;
        return nullptr;
    }

    int** result = new int*[cols];
    for (int i = 0; i < cols; i++) {
        *(result + i) = new int[rows];
        for (int j = 0; j < rows; j++) {
            result[i][j] = array[j][i];
        }
    }
    return result;
}

// ex 4
int** doubleUp(int** array, const int& rows, const int& cols) {
    if (rows == 0 || cols == 0) {
        cout << "Empty array." << endl;
        return nullptr;
    }
    int** result = new int*[rows];
    for (int i = 0; i < rows; i++) {
        *(result + i) = new int[cols];
        for (int j = 0; j < cols; j++) {
            result[i][j] = array[i][j] * 2;
        }
    }
    return result;
}

// ex 5
bool isSymmetric(int** array, const int& rows, const int& cols) {
    if ((rows == 0 && cols == 0) || (rows == 1 && cols == 1)) {
        return true;
    }
    // if the matrix is not n x n, it is not symmetric
    if (rows != cols) return false;
    // other wise check if the given matrix equal to its transpose matrix
    int** trans = transpose(array, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (array[i][j] != trans[i][j]) return false;
        }
    }
    return true;
}

// ex 6
int** deleteColumn(int** array, const int& rows, int& cols) {
    if (rows == 0 || cols == 0) {
        cout << "Empty array." << endl;
        return nullptr;
    }
    int index;
    do {
        cout << "Deleting column: " << endl;
        cin >> index;
        if (index < 0 || index >= cols) {
            cout << "Invalid." << endl;
        }
        else break;
    } while (true);

    for (int i = 0; i < rows; i++) {
        for (index; index < cols - 1; index++) {
            array[i][index] = array[i][index + 1];
        }
    }
    cols--;
    return array;
}

void trashCollector(int** array, const int& rows) {
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
        array[i] = nullptr;
    }
    delete[] array;
    array = nullptr;
}