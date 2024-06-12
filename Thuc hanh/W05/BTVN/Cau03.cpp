#include "header.h"

void docFile(StudentList &ll2, string tenFile) {
    ifstream fin;
    fin.open(tenFile, ios::in);
    if (!fin.good()) {
        cout << "Khong the mo file" << endl;
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
        Student *p = new Student(name, gender, stoi(day), stoi(month), stoi(year), stoi(math), stoi(literature), stoi(english));
        ll2.themCuoi(p);
    }
}

StudentList hsg(StudentList ll2) {
    Student *p = ll2.head;
    StudentList ll;
    while (p ) {
        if(p->averageScore >= 8 && p->mathScore >= 7 && p->literatureScore >= 7 && p->englishScore >= 7) {
            Student *s = new Student(p->name, p->gender, p->date, p->month, p->year, p->mathScore, p->literatureScore, p->englishScore);
            ll.themCuoi(s);
        }
        p = p->next;
    }
    return ll;
}