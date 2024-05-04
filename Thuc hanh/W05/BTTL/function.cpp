#include <iostream>
#include <string>
#include "header.h"

using namespace std;

void StudentList::addHead(Student *node) {
    if (0 != size) {
        node->next = head;
    }
    head = node;
    size++;
}

void StudentList::addTail(Student *node) {
    if (0 == size) {
        head = node;
        size++;
        return;
    }
    Student *p = head;
    while (nullptr != p->next) {
        p = p->next;
    }
    p->next = node;
    size++;
}

void StudentList::sort() {
    if (0 == size) {
        return;
    }
    Student *p = head;
    while (nullptr != p->next) {
        Student *sw = p;
        Student *q = p->next;
        while (nullptr != q) {
            if (sw->name > q->name) {
                sw = q;
            }
            q = q->next;
        }
        swap(p, sw);
        p = sw->next;
    }
}


void StudentList::swap(Student *a, Student *b) {
    if (a == head) {
        head = b;
    }
    else {
        Student *p = head;
        while (p->next != a) {
            p = p->next;
        }
        p->next = b;
    }

    if (a->next == b) {
        a->next = b->next;
        b->next = a;
    }
    else {
        Student *q = a->next;
        while (q->next != b);
        q->next = a;
        a->next = b->next;
        b->next = q;
    }
}

void readFile(StudentList &list) {
    ifstream fin;
    fin.open("data.txt", ios::in);
    if (!fin.is_open()) {
        cout << "Khong the mo file" << endl;
        return;
    }
    while (!fin.eof()) {
        string name, day, month, year, math, literature, english;
        getline(fin, name, ' ');
        getline(fin, day, '/');
        getline(fin, month, '/');
        getline(fin, year, ' ');
        getline(fin, math, ' ');
        getline(fin, literature, ' ');
        getline(fin, english);
        list.addTail(new Student(name, stoi(day), stoi(month), stoi(year), stoi(math), stoi(literature), stoi(english)));
    }
    fin.close();
}

void writeFile(const StudentList &list) {
    if (0 == list.size) {
        return;
    }
    ofstream fout;
    fout.open("result.txt", ios::out);
    if (!fout.is_open()) {
        cout << "Khong the mo file" << endl;
        return;
    }
    Student *p = list.head;
    while (nullptr != p) {
        if (p->averageScore < 5) {
            fout << p->name << " ";
            fout << p->day << "/" << p->month << "/" << p->year << " ";
            fout << p->mathScore << " " << p->literatureScore << " " << p->englishScore << endl;
        }
        p = p->next;
    }
    fout.close();
}