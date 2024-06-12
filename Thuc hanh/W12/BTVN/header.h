#pragma once

#include <iostream>

using namespace std;

#define nd "no data"

struct Student {
	string name;
	string gender;
	int date;
	int month;
	int year;
	int mathScore;
	int literatureScore;
	int englishScore;

    // constructor
    Student() : 
        name(nd), gender(nd), date(1), month(1), year(1), mathScore(0), literatureScore(0), englishScore(0) { }

    Student(string name, string gender, int date, int month, int year, int mathScore, int literatureScore, int englishScore) :
        name(name), gender(gender), date(date), month(month), year(year), mathScore(mathScore), literatureScore(literatureScore), englishScore(englishScore) { }
};

struct Node {
	Student s;
	Node* next;

    // constructor
    Node() : next(nullptr) { }

    Node(Student student) : s(student), next(nullptr) { }
};

struct StudentList {
	Node* head;
	int size;

    // operations
    void readFile(string);
    void traverse();
    void remove(int);
};