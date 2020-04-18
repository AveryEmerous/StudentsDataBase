//Made by Daniel Ivanov with GCC-9 C++20.

#include "myExcept.hpp"

#include <cstring>
#include <iostream>

noSpace::noSpace(const char *vDesc) : bad_alloc() {
    this->vDesc = new char[strlen(vDesc)];
    strcpy(this->vDesc, vDesc);
}

noSpace::~noSpace() {
    if (vDesc != nullptr) {
        delete[] vDesc;
        vDesc = nullptr;
    }
}

const char *noSpace::desc() {
    return vDesc;
}

notUsed::notUsed(const char *vDesc) : bad_alloc() {
    this->vDesc = new char[strlen(vDesc)];
    strcpy(this->vDesc, vDesc);
}

notUsed::~notUsed() {
    if (vDesc != nullptr) {
        delete[] vDesc;
        vDesc = nullptr;
    }
}

const char *notUsed::desc() {
    return vDesc;
}