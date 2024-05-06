#include <iostream>
#include "HandleInput.h"
#include "Matrix.h"
#include "Menu.h"
#include "DisplayMatrix.h"  

using std::cout, std::cin, std::endl;

int main() {
    do {
        int rows, cols;
        modeChooser(rows, cols);
        Matrix matrix(rows, cols);
        matrix.addRandom();
        matrix.addRandom();
        do {
            system("cls");
            cout << "Score: " << matrix.score() << endl << endl;
            display(matrix);
            int k = next();
            if (k == Up) {
                matrix.moveUp();
            }
            if (k == Down) {
                matrix.moveDown();
            }
            if (k == Left) {
                matrix.moveLeft();
            }
            if (k == Right) {
                matrix.moveRight();
            }
            if (k == 27) {
                break;
            }
            matrix.addRandom();
        } while (matrix.stuck() == false);
        system("cls");
        cout << "Game over. Score: " << matrix.score() << endl;
        cout << "Play again? Enter to play again, Esc to quit.";
        if (next() == 27) break;
    } while (true);
    return 0;
}