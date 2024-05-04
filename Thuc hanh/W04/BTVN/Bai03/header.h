#pragma once

#include <iostream>
using namespace std;

struct Node {
	int score;	
	Node* next;
    // constructor
    Node() : score(0), next(nullptr) {}
    Node(const int &data) : score(data), next(nullptr) {};

};

struct DanhSachLienKet {
	Node* head;
	int size;
    // constructor
    DanhSachLienKet() : head(nullptr), size(0) {}
    // destructor
    ~DanhSachLienKet() {
        Node* p = head;
        while (nullptr != p) {
            head = p->next;
            delete p;
            p = head;
        }
    }

    void print();
    void addHead(Node*);
    void addTail(Node*);
    void addAtK(Node*, const int&);
    void deleteHead();
    void deleteTail();
    void deleteAtK(const int &);
    Node* highestScore();
    double avgScore();
    void sort();
};