#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

template <typename T>
bool containSameElements(const std::vector<T>& a, const std::vector<T>& b) {
    if (a.size() != b.size()) {
        return false;
    }
    for(T elemA: a) {
        bool found = false;
        for (T elemB: b) {
            if (elemA == elemB) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

#endif // FUNCTIONS_H
