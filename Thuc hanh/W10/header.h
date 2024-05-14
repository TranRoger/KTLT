#pragma once

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    // constructor
    Node() : data(0), next(nullptr) { }
    Node(const int &d) : data(d), next(nullptr) { }
};

struct NganXep {
    Node* head;
    int size;
    void push(int data);	//Thêm một phần tử vào cuối ngăn xếp
    void pop();			//Xóa phần tử ở cuối ngăn xếp
    int top();			//Trả về giá trị của phần tử ở cuối ngăn xếp
    bool empty();		//Trả về kết quả cho biết ngăn xếp có rỗng hay không
    // constructor
    NganXep() : head(nullptr), size(0) { }
    // destructor
    void destroy() {
        while (!empty()) {
            pop();
        }
    }
};

template <typename T> T findMax(T *array, int size) {
    T max = array[0];
    for (int i = 1; i < size; i++) {
        if (max < array[i]) 
            max = array[i];
    }
    return max;
}

template <typename T> void printArray(T *array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void printStack(const NganXep);