#include "Progress.h"

Progress::Progress(LoadSetting setting) {
    Matrix matrix(setting.rows(), setting.cols());
    _data.push_back(matrix);
}

Matrix Progress::getCurrent() {
    return _data.top();
}

void Progress::update(Matrix newMatrix) {
    _cache.clear();
    _data.push_back(newMatrix);
}

void Progress::undo() {
    if (1 == _data.size()) {
        throw "Nothing to undo";
    }

    _cache.push_back(_data.top());
    _data.pop();
}

void Progress::redo() {
    if (_cache.empty()) {
        throw "Nothing to redo";
    }

    _data.push_back(_cache.top());
    _cache.pop();
}