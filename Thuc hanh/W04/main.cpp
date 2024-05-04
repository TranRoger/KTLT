#include <iostream>
using namespace std;

#include "header.h"

int main() {
    List list;
    int size;
    cout << "Size = ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        addHead(list);
    }
    cout << "List: ";
    print(list);
    int k;
    cout << "k = ";
    cin >> k;
    deleteNode(list, k);
    cout << "List after deletion: ";
    print(list);

    system("pause");
    return 0;
}