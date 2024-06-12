#pragma once

#include <iostream>
#include <string>

using std::string, std::getline, std::cin, std::cout, std::endl;

class PlayerNameInputHandler {
public:
    static string next();
};

string PlayerNameInputHandler::next() {
    string name;

    do {
        getline(cin, name);
        if(name.empty()) {
            cout << "Cannot leave blank" << endl;
        }
    } while(name.empty());

    return name;
}