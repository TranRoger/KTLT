#pragma once

#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
    int *ptr;
    int arrSize;
    Node *next;

    Node() {
        ptr = nullptr;
        arrSize = 0;
        next = nullptr;
    }

    Node(int *head, int size) {
        ptr = head;
        arrSize = size;
        next = nullptr;
    }

    void themCuoi(int *, const int &);
    void inList();
    void sort();
};

int **taoMang2Chieu(int &, int &);
Node *taoList(int **, const int &, const int &);
void sapXep(int *&, const int &);
int tongMang(int *, const int &);
void ghiFile(Node *, string);
int* docFile(string, int &);
bool fibonacci(const int &, const int &, const int &);