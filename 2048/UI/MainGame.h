#pragma once

#include "../Helper/string.h"
#include "../Object/Player.h"
#include "../KeyboardHandler/HandleInput.h"
#include "DisplayMatrix.h"

class Game {
private:
public:
    static void display(Player&, bool);
};

void Game::display(Player& p, bool rule) {
    p.getProgress().getCurrent().addRandom();
    p.getProgress().getCurrent().addRandom();

    do {
        system("cls");
        cout << "Score: " << p.getProgress().getCurrent().score() << endl << endl;
        Matrix matrix(p.getProgress().getCurrent());

        if (matrix.stuck()) {
            break;
        }

        DisplayMatrix::display(matrix);
        int k = KeyboardInputHandler::next();

        if (k == Up) {
            matrix.moveUp();
            matrix.addRandom();
        }
        if (k == Down) {
            matrix.moveDown();
            matrix.addRandom();
        }
        if (k == Left) {
            matrix.moveLeft();
            matrix.addRandom();
        }
        if (k == Right) {
            matrix.moveRight();
            matrix.addRandom();
        }
        if (k == Undo && rule) {
            try {
                p.getProgress().undo();
            } catch (string ex) {
                cout << "Cannot undo" << endl;
            }
        }
        if (k == Redo && rule) {
            try {
                p.getProgress().redo();
            } catch (string ex) {
                cout << "Cannot redo" << endl;
            }
        }
        if (k == 27) {
            system("cls");
            cout << "Do you want to exit?" << endl;
            k = KeyboardInputHandler::next();
            if (k == Enter) {
                break;
            }
        }

        p.getProgress().update(matrix);
    } while (true);

    cout << "Game over. Score: " << p.getProgress().getCurrent().score() << endl;
}