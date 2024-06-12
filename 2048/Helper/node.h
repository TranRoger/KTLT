#pragma once

template <class T>
class node {
private:
    T _value;
    node* _next;
public:
    // constructor
    node() = default;
    node(const T& value) : _value(value), _next(nullptr) { }
    // operation
    node* next() {
        return _next;
    }

    T value() {
        return _value;
    }

    void setNext(node* p) {
        this->_next = p;
    }
};