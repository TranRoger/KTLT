#include <iostream>
#include "header.h"

using namespace std;

int main() {
    StudentList list;
    readFile(list);
    list.sort();
    writeFile(list);

    return 0;
}