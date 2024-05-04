#include <iostream>
using namespace std;

#include "header.h"

void addHead(List& list) {
    cout << "Value: ";
    int value;
    cin >> value;
    Node* p = new Node(value);
    if (nullptr == list.head) {
        list.head = p;
        list.size++;
    }
    else {
        Node* traverse = list.head;
        while (nullptr != traverse->next) {
            traverse = traverse->next;
        }
        list.size++;
        traverse->next = p;
    }
}

void print(const List& list) {
    if (nullptr == list.head) {
        cout << "Empty list." << endl;
        return;
    }
    Node* traverse = list.head;
    while(nullptr != traverse) {
        cout << traverse->score << " ";
        traverse = traverse->next;
    }
    cout << endl;
}

void deleteNode(List& list, const int& k) {
    if (nullptr == list.head) {
        cout << "Empty list" << endl;
        return;
    }

    Node* traverse = list.head;
    if (k == traverse->score) {
        list.head = traverse->next;
        list.size--;
        delete traverse;
        return deleteNode(list, k);
    }

    while (nullptr != traverse->next) {
        if (k == traverse->next->score) break;
        traverse = traverse->next;
    }
    if (nullptr == traverse->next) {
        cout << "Not found!" << endl;
        return;
    }
    Node* del = traverse->next;
    traverse->next = del->next;
    delete del;
    list.size--;
    return deleteNode(list, k);
}