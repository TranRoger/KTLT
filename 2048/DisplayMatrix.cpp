#include "DisplayMatrix.h"

void display(const Matrix &matrix) {
    hline(matrix._columns * 6 + 1);
    HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < matrix._rows; i++) {
        cout << "|";
        for (int j = 0; j < matrix._columns; j++) {
            cout << setw(5) << setfill(' ');
            if (-1 == matrix._matrix[i][j]) {
                cout << " ";
            }
            else {
                SetConsoleTextAttribute(hConsole, matrix._matrix[i][j] % 100);
                cout << helper(std::to_string(matrix._matrix[i][j]));
                SetConsoleTextAttribute(hConsole, 15);
            }
            cout << "|";
        }
        cout << endl;
        hline(matrix._columns * 6 + 1);
    }
}

void hline(const int &size) {
    cout << setw(size) << setfill('-') << "-" << endl;
}

string helper(const string &str) {
    int len = str.length();
    if(5 < len) { return str; }

    int diff = 5 - len;
    int pad1 = diff/2;
    int pad2 = diff - pad1;
    return string(pad1, ' ') + str + string(pad2, ' ');
}