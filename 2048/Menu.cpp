#include "Menu.h"

void printMenu() {
    cout << "   2222222        0000000           4444444       888888888" << endl;
    cout << "  2::222::2     0::00000::0        4::44::4      8:::888:::8" << endl;
    cout << " 2222   2::2   0::0     0::0      4::4 4::4     8:::8   8:::8" << endl;
    cout << "       2::2    0::0     0::0     4::4  4::4      8:::888:::8" << endl;
    cout << "     2::2      0::0     0::0    4::44444::444    8:::888:::8" << endl;
    cout << "    2::2       0::0     0::0    44444444::444   8:::8   8:::8" << endl;
    cout << "  2::2_______   0::00000::0            4::4      8:::888:::8" << endl;
    cout << " 222222222222     0000000              4444       888888888" << endl;
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