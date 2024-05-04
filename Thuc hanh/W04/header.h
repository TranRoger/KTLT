#pragma once

#include <iostream>
using namespace std;

struct Node {
    int score;
    Node* next;
    Node(int value) {
        score = value;
        next = nullptr;
    }
};

struct List {
    Node* head;
    int size;
    List() {
        head = nullptr;
        size = 0;
    }
    ~List() {
        Node* p = head;
        while (nullptr != p) {
            p = p->next;
            delete head;
            head = p;
        }
    }
};

void addHead(List&);
void print(const List&);
void deleteNode(List&, const int&);