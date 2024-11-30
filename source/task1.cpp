#include "../include/task1.hpp"
#include <cstring>


char* CopyString(const char* str) {
    if (str == nullptr) {
        return nullptr;
    }

    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    char* copy = new char[length + 1];

    if (copy == nullptr) {
        return nullptr;
    }

    memcpy(copy, str, length + 1);
    return copy;
}


char* ConcatinateStrings(const char* a, const char* b) {
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return CopyString(b);
    }
    if (b == nullptr) {
        return CopyString(a);
    }
    
    int length_a = 0;
    int length_b = 0;
    while (a[length_a] != '\0') {
        length_a++;
    }
    while (b[length_b] != '\0') {
        length_b++;
    }
    
    char* copy = new char[length_a + length_b + 1];

    if (copy == nullptr) {
        return nullptr;
    }

    memcpy(copy, a, length_a);
    memcpy(copy + length_a, b, length_b + 1);
    return copy;
}
