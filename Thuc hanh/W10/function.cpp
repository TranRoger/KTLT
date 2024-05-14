#include "header.h"

void NganXep::push(int data) {
    if (empty()) {
        head = new Node(data);
    }
    else {
        Node *n = new Node(data);
        n->next = head;
        head = n;
    }
    size++;
}

void NganXep::pop() {
    if (empty()) return;
    Node *p = head;
    head = p->next;
    delete p;
    size--;
}

int NganXep::top() {
    if (empty()) exit(0);
    return head->data;
}

bool NganXep::empty() {
    if (nullptr == head) return true;
    return false;
}

void printStack(NganXep stack) {
    if (stack.empty()) {
        cout << "Ngan xep rong" << endl;
        return;
    }

    Node *p = stack.head;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
