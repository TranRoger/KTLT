#include "Menu.h"

void printMenu() {
    cout << "   ______          _______           _____         _______" << endl;
    cout << "  /  ___  \\       /  ___  \\         /     |      /   ___   \\" << endl;
    cout << " /__/   \\  \\     /  /   \\  \\       /  /|  |     |   |___|   |" << endl;
    cout << "        /  /    |  |     |  |     /  / |  |      \\         /" << endl;
    cout << "      /  /      |  |     |  |    /  /__|  |_     /   ___   \\" << endl;
    cout << "    /  /        |  |     |  |   |______    _|   |   /   \\   |" << endl;
    cout << "  /  /______     \\  \\___/  /           |  |     |   \\___/   |" << endl;
    cout << " |__________|     \\_______/            |__|      \\_________/" << endl;
    cout << endl << endl;
}

void modeChooser(int &rows, int &cols) {
    int text = Color::White;
    int background = Color::Black; 
    int selected = 1;
    while (true) {
        system("cls");
        printMenu();
        cout << "Use -> and <- to switch between modes. Press Enter to choose" << endl << endl;
        HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 15);

        if (1 == selected) {
            SetConsoleTextAttribute(hConsole, selected + background * 16);
            rows = 4;
            cols = 4;
        }
        cout << "4x4";
        SetConsoleTextAttribute(hConsole, 15);
        cout << "\t";
        if (2 == selected) {
            SetConsoleTextAttribute(hConsole, selected + background * 16);
            rows = 8;
            cols = 8;
        }
        cout << "8x8";
        SetConsoleTextAttribute(hConsole, 15);
        cout << "\t";
        if (3 == selected) {
            SetConsoleTextAttribute(hConsole, selected + background * 16);
            rows = 16;
            cols = 16;
        }
        cout << "16x16";
        SetConsoleTextAttribute(hConsole, 15);
        cout << endl;

        int c = next();
        if (c == Left && selected > 1) {
            selected--;

        }
        else if (c == Right && selected < 3) {
            selected++;
        }
        else if (c == Enter) break;
    }
    system("cls");
}