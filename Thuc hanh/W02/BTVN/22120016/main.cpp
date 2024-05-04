#include "header.h"

int main() {
	int* array, size;
	createArray(array, size);
	system("cls");
	cout << "Array[]";
	output(array, size);
	checkSorted(array, size);
	int result = sum(array, size);
	cout << "Array sum = " << result << endl;
	int maxValue = max(array, size);
	cout << "Array max value =  " << maxValue << endl;
	findPrime(array, size);
	reverse(array, size);
	cout << "ReversedArray[]";
	output(array, size);

	system("pause");
	return 0;
}