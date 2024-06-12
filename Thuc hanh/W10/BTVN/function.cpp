#include "header.h"

// HangDoi
void HangDoi::print() {
    if (0 == size) {
        cout << "Empty" << endl;
    }
    Node* node = head;
    while (node) {
        cout << node->data << " , ";
        node = node->next;
    }
    cout << endl;
}

void HangDoi::push(const int& n) {
    if (0 == size) {
        head = new Node(n);
        tail = head;
    }
    else {
        tail->next = new Node(n);
        tail = tail->next;
    }
    size++;
}

int HangDoi::back() {
    return tail->data;
}

int HangDoi::front() {
    return head->data;
}

void HangDoi::pop() {
    if (0 == size) {
        return;
    }
    Node* d = head;
    head = d->next;
    delete d;
    size--; 
    return;
}

bool HangDoi::empty() {
    if (0 == size) return true;
    return false;
}