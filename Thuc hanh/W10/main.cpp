#include <iostream>
#include <random>
#include "header.h"

using namespace std;

int main() {
    srand(time(nullptr));

    int s1 = rand() % 10; // so phan tu cua ngan xep
    NganXep stack;
    
    if (stack.empty()) cout << "Ngan xep rong" << endl;
    else cout << "Ngan xep co phan tu" << endl;

    for (int i = 0; i < s1; i++) {
        int a = rand() % 20;
        cout << "push(" << a << ")" << endl;
        stack.push(a);
    }
    
    cout << "Ngan xep sau khi them phan tu: ";
    printStack(stack);
    
    stack.pop();
    cout << "Ngan xep sau khi xoa phan tu dau: ";
    printStack(stack);

    cout << endl << endl;
    
    int s2 = rand() % 10, s3 = rand() % 10; // so phan tu cua mang kieu int va kieu float
    int *array1 = new int[s2];
    float *array2 = new float[s3];
    for (int i = 0; i < s2; i++) {
        array1[i] = rand() % 20;
    }
    for (int i = 0; i < s3; i++) {
        array2[i] = (float)rand() / (float)(RAND_MAX / 20);
    }
    
    cout << "Integer Array: ";
    printArray<int>(array1, s2);
    cout << "max: " << findMax(array1, s2) << endl << endl;
    cout << "Float Array: ";
    printArray(array2, s3);
    cout << "max: " << findMax(array2, s3) << endl;

    stack.destroy();
    delete[] array1;
    delete[] array2;
    
    return 0;
}
