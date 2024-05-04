#include "header.h"

bool checkValid(Student s) {
	if (s.math < 0 || s.math > 10 || s.literature < 0 || s.literature > 10 || s.english < 0 || s.english > 10) return false;
	if (s.year <= 0) return false;
	if (s.month < 1 || s.month > 12) return false;
	if (s.day < 1 || s.day > 31) return false;

	if ((s.month == 4 || s.month == 6 || s.month == 9 || s.month == 11) && s.day > 30) return false;
	if (s.month == 2) {
		if ((s.year % 4 == 0 && s.year % 100 != 0) && s.day > 29) return false;
		if (s.day > 28) return false;
	}

	return true;
}

void readFile(Student*& array, int& size) {
	int valid = 0;
	ifstream fileIn;
	fileIn.open("input.txt", ios::in);
	// Get number of students in file
	fileIn >> size;

	Student* students = new Student[size];
	for (int i = 0; i < size; i++) {
		Student temp;
		temp.name = new char;
		fileIn >> temp.name;
		fileIn >> temp.day >> temp.month >> temp.year >> temp.math >> temp.literature >> temp.english;
		if (checkValid(temp)) {
			students[valid] = temp;
			valid++;
		}
	}
	fileIn.close();
	size = valid;
	array = students;
	cout << "Data read successfully!" << endl;
}

void writeFile(Student* array, int size) {
	if (size == 0) {
		cout << "No data." << endl;
		return;
	}
	ofstream fileOut;
	fileOut.open("output.txt", ios::out);
	fileOut << size << endl;
	for (int i = 0; i < size; i++) {
		fileOut << array[i].name << " ";
		fileOut << array[i].day << " ";
		fileOut << array[i].month << " ";
		fileOut << array[i].year << " ";
		fileOut << array[i].math << " ";
		fileOut << array[i].literature << " ";
		fileOut << array[i].english << endl;
	}
	fileOut.close();
	cout << "Data written successfully!" << endl;
}

double avgScore(Student s) {
	return (s.math + s.literature + s.english) / 3.0;
}

Student highestScore(Student* array, int size) {
	if (size == 0) {
		cout << "No data." << endl;
		Student null;
		null.name = nullptr;
		return null;
	}
	Student highest = array[0];
	for (int i = 1; i < size; i++) {
		if (avgScore(array[i]) > avgScore(highest)) {
			highest = array[i];
		}
	}
	return highest;
}

void printStudent(Student s) {
	if (s.name == nullptr) return;
	cout << setw(10) << left << "Name" <<
		setw(5) << left << "Day" <<
		setw(7) << left << "Month" <<
		setw(5) << left << "Year" <<
		setw(7) << left << "Math" <<
		setw(13) << left << "Literature" <<
		setw(10) << left << "English" << 
		setw(10) << left << "Average" << endl;
	cout << setw(10) << left << s.name <<
		setw(5) << left << s.day <<
		setw(7) << left << s.month <<
		setw(5) << left << s.year <<
		setw(7) << left << s.math <<
		setw(13) << left << s.literature <<
		setw(10) << left << s.english << 
		setw(10) << left << avgScore(s) << endl;
}