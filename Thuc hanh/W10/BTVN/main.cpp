#include <iostream>
#include <random>
#include "header.h" 

int main() {
    srand(time(nullptr));
    // Bai 1
    int s1 = rand() % 10; // size of queue
    HangDoi q;
    cout << "Empty queue? " << q.empty() << endl;
    for (int i = 0; i < s1; i++) {
        int p = rand() % 20;
        cout << "push(" << p << ")" << endl;
        q.push(p);
    }
    cout << "Empty queue? " << q.empty() << endl;
    cout << "Queue: ";
    q.print();
    q.pop();
    cout << "Queue after pop(): ";
    q.print();
    cout << "Queue front: " << q.front() << endl;
    cout << "Queue back: " << q.back() << endl;

    // Bai 2
    int i, j;
    // create integer array
    int s2 = rand() % 10;
    int* iArray = new int[s2];
    for (int i = 0; i < s2; i++) {
        *(iArray + i) = rand() % 20;
    }
    cout << "Integer array: ";
    printArray(iArray, s2);
    i = rand() % s2;
    j = rand() % s2;
    swap(iArray, s2, i, j);
    cout << "Swap between " << i << " and " << j << ": ";
    printArray(iArray, s2);
    // create floating point array
    int s3 = rand() % 10;
    float* fArray = new float[s3];
    for (int i = 0; i < s3; i++) {
        *(fArray + i) = (float)rand() / (float)(RAND_MAX / 20);
    }
    cout << "Floating point array: ";
    printArray(fArray, s3);
    i = rand() % s3;
    j = rand() % s3;
    swap(fArray, s3, i, j);
    cout << "Swap between " << i << " and " << j << ": ";
    printArray(fArray, s3);
    
    // Bai 3
    int a = rand() % 20, b = rand() % 20;
    PhanSo<int> ia(a, b);
    a = rand() % 20, b = rand() % 20;
    PhanSo<int> ib(a, b);
    cout << ia.toString() << " + " << ib.toString() << " = " << ia.add(ib).toString() << endl;
    cout << ia.toString() << " - " << ib.toString() << " = " << ia.sub(ib).toString() << endl;
    cout << ia.toString() << " * " << ib.toString() << " = " << ia.mul(ib).toString() << endl;
    cout << ia.toString() << " / " << ib.toString() << " = " << ia.div(ib).toString() << endl;

    float c = (float)rand() / (float)(RAND_MAX / 20), d = (float)rand() / (float)(RAND_MAX / 20);
    PhanSo<float> fa(c, d);
    c = (float)rand() / (float)(RAND_MAX / 20), d = (float)rand() / (float)(RAND_MAX / 20);
    PhanSo<float> fb(c, d);
    cout << fa.toString() << " + " << fb.toString() << " = " << fa.add(fb).toString() << endl;
    cout << fa.toString() << " - " << fb.toString() << " = " << fa.sub(fb).toString() << endl;
    cout << fa.toString() << " * " << fb.toString() << " = " << fa.mul(fb).toString() << endl;
    cout << fa.toString() << " / " << fb.toString() << " = " << fa.div(fb).toString() << endl;

    return 0;
}