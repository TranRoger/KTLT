#include "header.h"

int main() {
    int number;
    cout << "number: ";
    cin >> number;
    cout << number;
    if (isPerfect(number)) {
        cout << " is a perfect number." << endl;
    }
    else {
        cout << " is not a perfect number." << endl;
    }

    system("pause");
    return 0;
}