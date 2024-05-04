#include <iostream>
#include "header.h"

using namespace std;

void DanhSachLienKet::print() {
    if (0 == size) {
        cout << "Danh sach rong" << endl;
        return;
    }
    Node* p = head;
    while (nullptr != p) {
        cout << p->score << " ";
        p = p->next;
    }
}

void DanhSachLienKet::addHead(Node* node) {
    if (0 != size) {
        node->next = head;
    }
    head = node;
    size++;
}

void DanhSachLienKet::addTail(Node* node) {
    if (0 == size) {
        head = node;
        size++;
        return;
    }
    Node* p = head;
    while (nullptr != p->next) {
        p = p->next;
    }
    p->next = node;
    size++;
}

void DanhSachLienKet::addAtK(Node* node, const int &k) {
    if (k > size) {
        cout << "K lon hon chieu dai cua list" << endl;
        return;
    }
    if (k == size) {
        addTail(node);
        return;
    }
    if (k == 0) {
        addHead(node);
        return;
    }
    int i = 0;
    Node* p = head;
    while (i == k - 1) {
        p = p->next;
    }
    node->next = p->next->next;
    p->next = node;
    size++;
}

void DanhSachLienKet::deleteHead() {
    if (0 == size) {
        cout << "Danh sach rong" << endl;
        return;
    }
    Node* p = head;
    head = p->next;
    delete p;
    p = nullptr;
    size--;
}

void DanhSachLienKet::deleteTail() {
    if (0 == size) {
        cout << "Danh sach rong" << endl;
        return;
    }
    Node* p = head;
    while (nullptr != p->next->next) {
        p = p->next;
    }
    delete p->next;
    p->next = nullptr;
    size--;
}

void DanhSachLienKet::deleteAtK(const int &k) {
    if (k > size) {
        cout << "K lon hon chieu dai cua danh sach" << endl;
        return;
    }
    if (0 == k) {
        deleteHead();
        return;
    }
    if (size - 1 == k) {
        deleteTail();
        return;
    }
    int i = 0;
    Node* p = head;
    while (i != k - 1) {
        p = p->next;
        i++;
    }
    Node* q = p->next;
    p->next = q->next;
    delete q;
    q = nullptr;
    size--;
}

Node* DanhSachLienKet::highestScore() {
    if (0 == size) {
        cout << "Danh sach rong" << endl;
        return nullptr;
    }
    Node* max = head;
    Node *p = max->next;
    while (p->next != nullptr) {
        if (max->score < p->score) {
            max = p;
        }
        p = p->next;
    }
    return max;
}

double DanhSachLienKet::avgScore() {
    if (0 == size) {
        cout << "Danh sach rong" << endl;
        return 0;
    }
    double sum = 0.0;
    Node* p = head;
    while (p->next != nullptr)
    {
        sum+= p->score;
        p = p->next;
    }
    return sum / size;    
}

void DanhSachLienKet::sort() {
    if (0 == size) {
        cout << "Danh sach rong" << endl;
        return;
    }
    Node* p = head;
    while (p->next != nullptr) {
        Node* sw = p;
        Node* q = p->next;
        while (q != nullptr) {
            if (sw->score > q->score) {
                sw = q;
            }
            q = q->next;
        }
        int temp = p->score;
        p->score = sw->score;
        sw->score = temp;
        p = p->next;
    }
}