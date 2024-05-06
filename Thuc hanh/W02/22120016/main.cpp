#include "header.h"

int main() {
	int* pointer = new int;
	int result;

	do {
		cout << "1. Cau 1." << endl;
		cout << "2. Cau 2." << endl;
		cout << "3. Cau 3." << endl;
		cout << "4. Cau 4." << endl;
		cout << "5.Thoat." << endl << endl;

		int opt;
		do {
			cout << "Chon: ";
			cin >> opt;
		} while (opt < 1 && opt > 5);

		if (opt == 1) {
			cout << "Gan gia tri cho con tro: ";
			cin >> *pointer;
			cout << "Gia tri cua con tro duoc gan: " << *pointer << endl;
		}
		else if (opt == 2) {
			giaTri(pointer);
			result = *pointer;
		}
		else if (opt == 3) {
			ofstream writer;
			writer.open("data.bin", ios::binary | ios::out);
			if (!writer.is_open()) {
				cout << "Khong the mo file." << endl;
				break;
			}
			writer.write((char*)&result, sizeof(result));
			writer.close();
		}
		else if (opt == 4) {
			ifstream scanner;
			scanner.open("data.bin", ios::binary | ios::in);
			if (!scanner.is_open()) {
				cout << "Khong the mo file." << endl;
				break;
			}
			int read;
			scanner.read((char*)&read, sizeof(int));
			cout << "Gia tri: " << read << endl;
			scanner.close();
		}
		else break;
		system("pause");
		system("cls");
	} while (true);

	delete pointer;
	pointer = nullptr;

	system("pause");
	return 0;
}