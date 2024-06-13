#pragma once

#include "../Helper/stack.h"
#include "Matrix.h"
#include "../Setting/LoadSetting.h"
#include "../UI/DisplayMatrix.h"

class Progress {
public:
    stack<Matrix> _data;
    stack<Matrix> _cache;
public:
    // constructor
    Progress() = default;
    Progress(LoadSetting);
    Progress(stack<Matrix>, stack<Matrix>);
    // operation
    Matrix getCurrent();
    void update(Matrix);
    void undo();
    void redo();
    stack<Matrix> getData();
    stack<Matrix> getCache();
    void freeMemory();
};