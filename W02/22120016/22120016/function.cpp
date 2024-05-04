#include "header.h"

bool isPerfect(int number) {
    int sum = 0;
    for (int iterator = 1; iterator < number; iterator++) {
        if (number % iterator == 0) sum += iterator;
    }
    if (sum != number) {
        return false;
    }
    else {
        return true;
    }
}