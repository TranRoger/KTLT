#include <iostream>
#include "KeyboardHandler/HandleInput.h"
#include "KeyboardHandler/PlayerNameInputHandler.h"
#include "Object/Matrix.h"
#include "UI/MainMenu.h"
#include "UI/DisplayMatrix.h"  
#include "Object/Player.h"
#include "Setting/LoadSetting.h"
#include "UI/MainGame.h"
#include "UI/SettingDisplay.h"  
#include "Helper/vector.h"

using std::cout, std::cin, std::endl;

int main() {
    string settingFile = "Setting/setting.bin";
    LoadSetting setting;
    setting.load(settingFile);

    do {
        int opt = MainMenu::modeChooser();
        system("cls");
        if (1 == opt) {
            cout << "Enter player name: ";
            string pName = PlayerNameInputHandler::next();
            Progress progress(setting);
            Player p(pName, progress);

            Game::display(p, setting.allowUndoRedo());
        }
        else if (2 == opt) {
            
        }
        else if (3 == opt) {
            SettingDisplay::display(setting);
            continue;
        }
        else {

        }

        if (KeyboardInputHandler::next() == 27) break;        
    } while (true);

    system("pause");

    return 0;
}