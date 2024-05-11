#include "header.h"

int count(int *array, const int &size, const int &value) {
    if (-1 == size) return 0;
    if (array[size - 1] == value) return 1 + count(array, size - 1, value);
    else return count(array, size - 1, value);
}

int multiply(const int &a, const int &b) {
    if (0 == a || 0 == b) return 0;
    if (1 == a) return b;
    if (1 == b) return a;
    return a + multiply(a, b - 1);
}

int calculate(const int &number) {
    if (0 == number) return 0;
    return number % 10 + calculate(number / 10);
}

string Student::toString() {
    stringstream builder;
    builder << name << "\t" << gender << "\t" << age << " tuoi\t" << averageScore << endl;
    return builder.str();
}

void StudentList::readFile(string fileName) {
    ifstream fin;
    fin.open(fileName, ios::in);
    if (!fin.good()) {
        cout << "Khong the tim thay file" << endl;
        return;
    }
    while (!fin.eof()) {
        string name, gender, day, month, year, math, literature, english;
        getline(fin, name, ' ');
        getline(fin, gender, ' ');
        getline(fin, day, '/');
        getline(fin, month, '/');
        getline(fin, year, ' ');
        getline(fin, math, ' ');
        getline(fin, literature, ' ');
        getline(fin, english);
        Student *s = new Student(name, gender, stoi(day), stoi(month), stoi(year), stoi(math), stoi(literature), stoi(english));
        addTail(s);
    }
    fin.close();
}

void StudentList::addTail(Student *s) {
    if (nullptr == head) {
        head = s;
    }
    else {
        Student *h = head;
        while (nullptr != h->next) {
            h = h->next;
        }
        h->next = s;
    }
    size++;
}

void StudentList::print(Student *s) {
    if (nullptr == s) return;
    cout << s->toString();
    print(s->next);
}

int *StudentList::totalScore(int &s) {
    s = size;
    int *array = new int[s];
    
    Student *h = head;
    for (int i = 0; i < s; i++) {
        array[i] = h->mathScore + h->literatureScore + h->englishScore;
        h = h->next;
    }
    return array;
}

void printArray(int *array, const int &size, const int &index) {
    if (index == size) {
        cout << endl;
        return;
    }
    cout << array[index] << " ";
    printArray(array, size, index + 1);
}

int findMax(int *array, const int &size, const int &index, int &max) {
    if (size == index) return max;
    if (max < array[index]) max = array[index];
    return findMax(array, size, index + 1, max);
}
