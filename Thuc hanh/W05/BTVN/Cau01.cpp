#include "header.h"

int **createMatrix(const int &n, const int &m) {
    int **result = new int*[n];
    for (int i = 0; i < n; i++) {
        result[i] = new int[m];
    }
    return result;
}

void inMaTran(int **matrix, const int &n, const int &m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int tongCheoChinh(int **matrix, const int &size) {
    int sum = 0;
    for (int i = 0; i < size; i++) { 
        sum += matrix[i][i];
    }
    return sum;
}

int tongCheoPhu(int **matrix, const int &size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += matrix[i][size - i - 1];
    }
    return sum;
}

void tinhDuongCheo(int **matrix, const int &n, const int &m) {
    if (n != m) {
        cout << "n khac m" << endl;
        return;
    }
    cout << "Tong duong cheo chinh: " << tongCheoChinh(matrix, n) << endl;
    cout << "Tong duong cheo phu: " << tongCheoPhu(matrix, n) << endl;
}

int **congMaTran(int **A, int **B, const int &n, const int &m) {
    int **result = new int*[n];
    for (int i = 0; i < n; i++) {
        result[i] = new int[m];
        for (int j = 0; j < m; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

int tongMaTran(int **matrix, const int &n, const int &m) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

bool isPrime(const int &number) {
    if (number < 2) return false;
    if (2 == number) return true;
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) return false;
    }
    return true;
}

bool isPerfect(const int &number) {
    if (number < 0) return false;
    int sum = 0;
    for (int i = 1; i < number; i++) {
        if (number % i == 0) sum += i;
    }
    if (sum == number) return true;
    return false;
}

int **thuNho(int **matran, const int &n, const int &m) {
    if (0 == n || 0 == m) {
        cout << "Khong the thu nho" << endl;
        return nullptr;
    }
    int **result = new int*[n - 1];
    for (int i = 0; i < n - 1; i++) {
        result[i] = new int[m - 1];
        for (int j = 0; j < m - 1; j++) {
            result[i][j] = matran[i][j];
        }
    }
    return result;
}