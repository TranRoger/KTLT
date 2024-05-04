#pragma once

#include <iostream>
#include <math.h>

using namespace std;

int **createMatrix(const int &, const int &);
void inMaTran(int **, const int &, const int &);
int tongCheoChinh(int **, const int &);
int tongCheoPhu(int **, const int &);
void tinhDuongCheo(int **, const int &, const int &);
int **congMaTran(int **, int **, const int &, const int &);
int tongMaTran(int **, const int &, const int &);
bool isPrime(const int &);
bool isPerfect(const int &);
int **thuNho(int **, const int &, const int &);
