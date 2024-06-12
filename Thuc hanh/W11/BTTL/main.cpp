#include <iostream>
#include "header.h"

using namespace std;

int main() {
    char* str = "aBc DeF";
    cout << reverse(str) << endl;

    int rows, cols;
    char* fileName= "data.txt";
    int** matrix = createMatrix(fileName, rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }

    return 0;
}