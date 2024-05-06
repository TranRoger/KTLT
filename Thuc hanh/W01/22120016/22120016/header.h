#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Student {
	char* name;
	int day;
	int month;
	int year;
	double math;
	double literature;
	double english;
};

bool checkValid(Student);
void readFile(Student*&, int&);
void writeFile(Student*, int);
double avgScore(Student);
Student highestScore(Student*, int);
void printStudent(Student);