#include "header.h"

void createArray(int*& array, int& size) {
	// Require user to input the valid size
	do {
		cout << "Kich thuoc cua mang: ";
		cin >> size;
		if (size < 0) cout << "Khong hop le!" << endl;
		else break;
	} while (true);
	// Create a new dynamic array
	array = new int[size];
	// Input value for array
	for (int i = 0; i < size; i++) {
		cout << "array[" << i << "] = ";
		cin >> array[i];
	}
}

void output(int* array, const int& size) {
	// If size = 0, return
	if (size == 0) {
		cout << ": Empty array." << endl;
		return;
	}
	
	cout << " = {";
	for (int i = 0; i < size; i++) {
		cout << " " << array[i] << " ";
		if (i != size - 1) cout << ",";
	}
	cout << "}" << endl;
}

void checkSorted(int* array, const int& size) {
	// If array has no value, return. If array has only 1 value, return.
	if (size == 0) {
		cout << "Empty array." << endl;
		return;
	}
	else if (size == 1) {
		cout << "Array has only one element." << endl;
		return;
	}
	// Create a variable to store the sorted type of array (ascending > 0, descending < 0, similar values = 0)
	int sorted = array[1] - array[0];
	for (int i = 1; i < size - 1; i++) {
		int traverse = array[i + 1] - array[i];
		// If sorted = 0, two adjacent value are equal, find the array sort type
		if (sorted == 0) {
			sorted = traverse;
			continue;
		}
		// If two selected value are equal, skip
		if (traverse == 0) {
			continue;
		}
		// traverse * sorted > 0 means two selected value are sorted correctly, otherwise array is not sorted, return -2
		if (traverse * sorted < 0) {
			cout << "Array is neither ascending nor descending." << endl;
			return;
		}
	}
	if (sorted > 0) {
		cout << "Array is ascending." << endl;
		return;
	}
	else if (sorted < 0) {
		cout << "Array is descending." << endl;
		return;
	}
	else {
		cout << "Array has similar values." << endl;
		return;
	}
}

int sum(int* array, const int& size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += array[i];
	}
	return sum;
}

int max(int* array, const int& size) {
	if (size == 0) {
		cout << "Empty array." << endl;
		return INT_MIN;
	}
	int max = array[0];
	for (int i = 1; i < size; i++) {
		if (max < array[i]) max = array[i];
	}
	return max;
}

bool isPrime(const int& number) {
	if (number < 2) return false;
	else if (number == 2) return true;
	
	for (int i = 2; i <= sqrt(number); i++) {
		if (number % i == 0) return false;
	}
	return true;
}

void findPrime(int* array, const int& size) {
	// If array size = 0, return
	if (size == 0) {
		cout << "Empty array." << endl;
		return;
	}
	// Count prime number
	int primeSize = 0;
	for (int i = 0; i < size; i++) {
		if (isPrime(array[i])) primeSize++;
	}
	cout << "There are/is " << primeSize << " prime number(s) in the array: ";

	for (int i = 0; i < size; i++) {
		if (isPrime(array[i])) {
			cout << array[i] << " ";
		}
	}
	cout << endl;
}

void reverse(int* array, const int& size) {
	if (size == 0) return;

	for (int i = 0; i < size / 2; i++) {
		int temp = array[i];
		array[i] = array[size - i - 1];
		array[size - i - 1] = temp;
	}
}