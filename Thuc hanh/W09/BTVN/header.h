#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

// Dem so lan xuat hien cua mot phan tu cu the trong mang
int count(int *, const int &, const int &);
// Tinh tich cua 2 so khong dung toan tu *
int multiply(const int &, const int &);
// Tinh tong cac chu so cua mot so nguyen cho truoc
int calculate(const int &);
// Bai 4
struct Student {
    string name;
    string gender;
    int date;
    int month;
    int year;
    int age;
    int mathScore;
    int literatureScore;
    int englishScore;
    int averageScore;
    Student *next;
    
    // constructor
    Student(string name_, string gender_, int date_, int month_, int year_, int math_, int literature_, int english_) :
        name(name_), gender(gender_), date(date_), month(month_), year(year_), mathScore(math_), literatureScore(literature_), englishScore(english_) {
        age = 2024 - year;
        averageScore = (mathScore + literatureScore + englishScore) / 3;
        next = nullptr;
    }
    // operation
    string toString();
};

struct StudentList {
    Student *head;
    int size;

    // constructor
    StudentList() : head(nullptr), size(0) { }
    StudentList(Student* h) : head(h), size(1) { }
    // operation
    // Doc file data.txt va tao mot danh sach lien ket
    void readFile(string);
    void addTail(Student*);
    // Duyet dslk va in phan tu
    void print(Student*);
    // Luu tong diem cua cac nut
    int *totalScore(int &);
};

void printArray(int *, const int &, const int &);
int findMax(int *, const int &, const int &, int &);
