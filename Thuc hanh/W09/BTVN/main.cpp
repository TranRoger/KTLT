#include <iostream>
#include <random>
#include "header.h"
using namespace std;

int main() {
    srand(time(nullptr));
    int s1 = rand() % 10;
    int *array = new int[s1];
    for (int i = 0; i < s1; i++) {
        array[i] = rand() % 10;
    }
    cout << "Mang: ";
    printArray(array, s1, 0);
    int n1 = rand() % 10;
    cout << "So lan xuat hien cua " << n1 << " trong mang la: " << count(array, s1, n1) << endl;
    int a = rand() % 10, b = rand() % 10;
    cout << a << " * " << b <<  " = " << multiply(a, b) << endl;
    int n2 = rand() % 10000;
    cout << "Tong cac chu so cua " << n2 << " la: " << calculate(n2) << endl;
    
    StudentList list;
    list.readFile("data.txt");
    list.print(list.head);
    
    int s2;
    int *scores = list.totalScore(s2);
    
    printArray(scores, s2, 0);
    cout << "Diem lon nhat: " << findMax(scores, s2, 1, scores[0]) << endl;

    return 0;
}
