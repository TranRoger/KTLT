#pragma once

#include <iostream>
#include <sstream>
#include <random>

using namespace std;

// Bai 1
struct Node {
    int data;
    Node* next;

    Node(const int& d) : data(d), next(nullptr) { } // constructor
};

struct HangDoi {
    Node* head;
    Node* tail;
    int size;

    HangDoi() : head(nullptr), tail(nullptr), size(0) { } // default constructor

    void print();

    void push(const int&);	//Thêm một phần tử vào cuối hàng đợi
    int back();			//Trả về giá trị của phần tử ở cuối hàng đợi
    int front();		//Trả về giá trị của phần tử ở đầu hàng đợi
    void pop();			//Xóa phần tử ở đầu hàng đợi
    bool empty();		//Trả về kết quả cho biết hàng đợi có rỗng hay không
};

// Bai 2
template <class T>
void printArray(T* array, const int& size) {
    for (int i = 0; i < size; i++) {
        cout << *(array + i) << " , ";
    }
    cout << endl;
}

template <class T>
void swap(T* array, const int& size, const int& i, const int& j) {
    if (i >= size || j >= size) {
        cout << "Insufficient input";
        return;
    }

    T temp = *(array + i);
    *(array + i) = *(array + j);
    *(array + j) = temp;
}

// Bai 3
template <class T>
struct PhanSo {
    T num;
    T denom;

    PhanSo(const T& n, const T& d) : num(n), denom(d) { }

    std::string toString() {
        stringstream builder;
        builder << num << "/" << denom;
        return builder.str();
    }

    PhanSo add(const PhanSo& ps) {
        T num = this->num * ps.denom + ps.num * this->denom;
        T denom = this->denom * ps.denom;
        return PhanSo(num, denom);
    }

    PhanSo sub(const PhanSo& ps) {
        T num = this->num * ps.denom - ps.num * this->denom;
        T denom = this->denom * ps.denom;
        return PhanSo(num, denom);
    }

    PhanSo mul(const PhanSo& ps) {
        T num = this->num * ps.num;
        T denom = this->denom * ps.denom;
        return PhanSo(num, denom);
    }

    PhanSo div(const PhanSo& ps) {
        T num = this->denom * ps.denom;
        T denom = this->num * ps.num;
        return PhanSo(num, denom);
    }
};