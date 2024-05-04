#pragma once

#include <iostream>
using namespace std;

int** twoDimArray(const int&, const int&);
void printTwoDimArray(int**, const int&, const int&);
int* indexArray(const int&);
void printRow(int**, int*, const int&, const int&);
void printColumn(int**, int*, const int&, const int&);
void checkAscending(int**, const int&, const int&);
int** transpose(int**, const int&, const int&);
int** doubleUp(int**, const int&, const int&);
bool isSymmetric(int**, const int&, const int&);
int** deleteColumn(int**, const int&, int&);
void trashCollector(int**, const int&);