#pragma once

#include <iostream>
#include "node.h"

template <class T>
class vector {
protected:
    int _size;
    node<T>* _head;
    node<T>* _tail;
public:
    // constructor
    vector() : _size(0), _head(nullptr), _tail(nullptr) {}
    vector(const T& value) : _size(1) {
        node<T>* p = new node<T>(value);
        this->_head = p;
        this->_tail = p;
    }
    // operation
    virtual void push_back(const T& value) {
        node<T>* p = new node<T>(value);

        if (0 == _size) {
            this->_head = p; 
        }
        else {
            this->_tail->setNext(p);
        }
        this->_tail = p;
        this->_size++;
    }

    virtual void pop() {
        if (0 == this->_size) {
            return;
        }

        node<T>* p = this->_head;
        while (p->next() != _tail) {
            p = p->next();
        }
        
        delete _tail;
        this->_tail = p;
        this->_size--;
    }

    T at(const int& index) {
        if (index >= this->_size) {
            throw "Out of range";
        }

        node<T>* p = this->_head;
        int i = 0;
        while(i != index) {
            p = p->next();
            i++;
        }

        return p->value();
    }
    
    T operator[] (const int& index) {
        return at(index);
    }

    void clear() {
        while (0 != this->_size) {
            pop();
        }
    }

    bool empty() {
        if (0 == this->_size) {
            return true;
        }
        return false;
    }

    int size() {
        return this->_size;
    }
};