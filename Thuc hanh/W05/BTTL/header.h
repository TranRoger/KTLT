#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Student {
	string name;
	int day;
	int month;
	int year;
	int age;
	int mathScore;
	int literatureScore;
	int englishScore;
	int averageScore;
	Student* next;
    // constructor
    Student() : next(nullptr) {};
    Student(const string& n, const int& d, const int &m, const int &y, const int &math, const int &literature, const int &english) 
    : name(n), day(d), month(m), year(y), mathScore(math), literatureScore(literature), englishScore(english), next(nullptr) {
        averageScore = (math + literature + english) / 3;
    }
};

struct StudentList {
	Student* head;
	int size;
    // constructor
    StudentList() : head(nullptr), size(0) {}
    // destructor
    ~StudentList() {
        Student* p = head;
        while (nullptr != p) {
            head = p->next;
            delete p;
            p = head;
        }
    }
    // operation
    void addHead(Student*);
    void addTail(Student*);
    void sort();
    void swap(Student*, Student*);
};

void readFile(StudentList&);
void writeFile(const StudentList&);
