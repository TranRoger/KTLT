#pragma once

#include "Progress.h"
#include <string>

using std::string;

class Player {
private:
    string _name;
    Progress _progress;
    int _time;
public:
    // constructor
    Player(const string&, const Progress&);
    // operation
    Progress& getProgress();
    string name();
    int time();
};

Player::Player(const string& name, const Progress& progress) :
    _name(name), _progress(progress), _time(0) { }

Progress& Player::getProgress() {
    return _progress;
}

string Player::name() {
    return _name;
}

int Player::time() {
    return _time;
}