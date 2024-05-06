#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <fstream>

using namespace std;

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
	Student* next;

    Student(string Name, string Gender, const int &Date, const int &Month, const int &Year, const int &MathScore, const int &LiteratureScore, const int &EnglishScore) : name(Name), gender(Gender), date(Date), month(Month), year(Year), mathScore(MathScore), literatureScore(LiteratureScore), englishScore(EnglishScore) {
        auto now = chrono::system_clock::now();
        time_t now_c = chrono::system_clock::to_time_t(now);
        tm* now_tm = localtime(&now_c);
        int nam = now_tm->tm_year + 1900;
        age = nam - year;
        averageScore = (mathScore + literatureScore + englishScore) / 3;
    }

    void inHS() {
        cout << name << " " << gender << " " << age << " " << date << "/" << month << "/" << year << " " << mathScore << " " << literatureScore << " " << englishScore << " " << averageScore << endl;
    }
};

struct StudentList {
	Student* head;
	int size;

    StudentList() {
        head = nullptr;
        size = 0;
    }

    void themCuoi(Student *s) {
        if (0 == size) {
            head = s;
            size++;
            return;
        }
        Student *p = head;
        while (p->next) {
            p = p->next;
        }
        p->next = s;
        size++;
    }
    
    void swap(Student *&a, Student *&b) {
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

    void sort() {
        Student *p = head;
        while (p->next) {
            Student *q = p->next;
            Student *s = p;
            while (q) {
                if (s->name > q->name) {
                    s = q;
                }
                else if (s->name == q->name && s->averageScore > q->averageScore) {
                    s = q;
                }
                q = q->next;
            }
            swap(p, s);
            p = p->next;
        }
    }

    void inDs() {
        Student *p = head;
        while (p) {
            p->inHS();
            p = p->next;
        }
    }
};

void docFile(StudentList &, string);
StudentList hsg(StudentList);