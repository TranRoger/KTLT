#include "header.h"

int main() {
	int option;
	Student* array = nullptr;
	int size = 0;
	do {
		system("cls");
		cout << "MENU" << endl;
		cout << "1. Read students information from file." << endl <<
			"2. Write valid students information to file." << endl <<
			"3. Print student with highest average score." << endl <<
			"4. Quit." << endl << endl;
		do {
			cout << "Selection: ";
			cin >> option;
		} while (option < 1 && option > 4);
		system("cls");

		if (option == 1) {
			readFile(array, size);
		}
		else if (option == 2) {
			writeFile(array, size);
		}
		else if (option == 3) {
			printStudent(highestScore(array, size));
		}
		system("pause");
	} while (option != 4);

	cout << "Good bye" << endl;
	return 0;
}