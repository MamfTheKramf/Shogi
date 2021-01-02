#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <algorithm>

template <typename T>
bool containSameElements(const std::vector<T>& a, const std::vector<T>& b) {
    if (a.size() != b.size()) {
        return false;
    }
    for(T elemA: a) {
        if(std::count(a.begin(), a.end(), elemA) != std::count(b.begin(), b.end(), elemA)) {
            return false;
        }
    }
    return true;
}

#endif // FUNCTIONS_H
