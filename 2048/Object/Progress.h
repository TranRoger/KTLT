#pragma once

#include "../Helper/stack.h"
#include "Matrix.h"
#include "../Setting/LoadSetting.h"

class Progress {
public:
    stack<Matrix> _data;
    stack<Matrix> _cache;
public:
    // constructor
    Progress() = default;
    Progress(LoadSetting);
    // operation
    Matrix getCurrent();
    void update(Matrix);
    void undo();
    void redo();
};