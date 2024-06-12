#include "header.h"

char* reverse(char* str) {
    int size = sizeof(str);

    if (0 == size || nullptr == str) {
        return str;
    }

    char* result = new char[size];
    for (int i = 0; i < size; i++) {
        result[i] = str[size - i - 1];
    }
    return result;
}

int** createMatrix(const char* fileName, int& rows, int& cols) {
    ifstream fin;
    fin.open(fileName, ios::in);

    if (!fin.good()) {
        return nullptr;
    }

    fin >> rows;
    fin >> cols;

    int** result = new int*[rows];
    for (int i = 0; i < rows; i++) {
        *(result + i) = new int[cols];
        for (int j = 0; j < cols; j++) {
            fin >> *(*(result + i) + j);
        }
    }

    return result;
}

char* replace(char* str1, char* str2, char* str3) {
    int s1 = sizeof(str1), s2 = sizeof(str2), s3 = sizeof(str3);

    return str1;
}

int find(char* str1, char* str2, const int& index) {
    int s1 = sizeof(str1), s2 = sizeof(str2);

    if (s1 - index < s2) { 
        return -1;
    }

    int match = 0, result = -1;
    for (int i = index; i < s1; i++) {
        if (match == s2 && str1[i] == str2[match]) {
            return result;
        }

        if (str1[i] != str2[match]) {
            result = -1;
            match = 0;
        }
        else {
            match++;
            if (0 == match) {
                result = i;
            }
        }
    }

    return result;
}