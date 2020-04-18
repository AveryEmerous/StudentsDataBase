//Made by Daniel Ivanov with GCC-9 C++20.

#include "lib.h"

#include <cstring>
#include <iostream>

#include "myExcept.hpp"

//Constructor for the Entry struct. Space is allocated for the name
//and the grade is assigned based if it's between 2 or 6. 1 is assigned for an inavlid grade.
Entry::Entry(const char *name, unsigned FN, double avgGrade) : FN(FN) {
    this->avgGrade = (avgGrade >= 2 && avgGrade <= 6) ? avgGrade : 1;  //1 for inavalid grade
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
}

//Destructor for struct Entry. Frees up space associated with the name.
Entry::~Entry() {
    if (this->name != nullptr) {
        delete[] this->name;
        this->name = nullptr;
    }
}

//Redefinition of equal operator for a double.
Entry &Entry::operator=(double avgGrade) {
    this->avgGrade = avgGrade;
    return *this;
}

//Redefinition of equal operator for a double.
Entry &Entry::operator=(const char *name) {
    if (this->name != nullptr) {
        delete[] this->name;
        this->name = nullptr;
    }
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    return *this;
}

//Inserts variables into the ostream.
std::ostream &Entry::ins(std::ostream &os) const {
    return os << "Name: " << name << '\n'
              << "Faculty number: " << FN << '\n'
              << "Average grade: " << avgGrade << '\n';
}

//Redefines << so it can take the inputted stream from the inserter.
std::ostream &operator<<(std::ostream &os, const Entry &ob) {
    return ob.ins(os);
}

//Constructor for class Students. Allocates space for a 2D array of
//entries that point to nullptr by default.
Students::Students(unsigned vSize) : vSize(vSize) {
    container = new Entry *[vSize];
    for (unsigned i = 0; i < vSize; i++)
        container[i] = nullptr;
}

//Copy constructor. Assigns entries of the given database to this one.
Students::Students(const Students &r) : vSize(r.vSize) {
    container = new Entry *[vSize];
    for (unsigned i = 0; i < vSize; i++) {
        if (r.container[i] != nullptr)
            container[i] = r.container[i];
        else
            container[i] = nullptr;
    }
}

//Equal redefintion. Deletes old entries and assigns
//entries of the given database to this one.
Students &Students::operator=(const Students &r) {
    if (container != nullptr) {
        for (unsigned i = 0; i < vSize; i++) {
            if (container[i] != nullptr) {
                delete container[i];
                container[i] = nullptr;
            }
        }
        delete[] container;
        container = nullptr;
    }

    container = new Entry *[vSize];
    for (unsigned i = 0; i < vSize; i++) {
        if (r.container[i] != nullptr)
            container[i] = r.container[i];
        else
            container[i] = nullptr;
    }
}

//Deletes the container for the entries.
Students::~Students() {
    if (container != nullptr) {
        for (unsigned i = 0; i < vSize; i++) {
            if (container[i] != nullptr) {
                delete container[i];
                container[i] = nullptr;
            }
        }
        delete[] container;
        container = nullptr;
    }
}

//Returns the modulo of the facululty number for
//positioning purposes inside container.
unsigned Students::studMod(unsigned FN) {
    return FN % vSize;
}

//Searches the array for a faculty number
//while starting at it's modulo. Return -1
//if it's not found.
unsigned Students::searchFN(unsigned FN) {
    for (unsigned pos = FN % vSize; pos < vSize; pos++) {
        if (container[pos] != nullptr)
            if (FN == container[pos]->FN)
                return pos;
    }
    return -1;
}

//Inserting at a valid position using the modulo operator.
//If the current modulo position is taken, the next closest
//free position will be taken. If no such position is found,
//an exception will be thrown.
void Students::insert(const char *name, unsigned FN, double avgGrade) throw() {
    unsigned pos = studMod(FN);
    while (container[pos] != nullptr && pos < vSize - 1) {
        pos = studMod(pos + 1);
    }
    if (container[pos] != nullptr && vSize - 1 == pos) {
        throw noSpace("Not enough space to assign new entry.");
    }
    container[pos] = new Entry(name, FN, avgGrade);
}

//Returning an entry at the given faculty number.
Entry &Students::operator[](unsigned FN) {
    unsigned pos = studMod(FN);
    if (container[pos] == nullptr || vSize - 1 == pos) {
        insert("No Name", FN);
    }
    return *container[pos];
}

//Ostream inserter for all of the entries in the array.
std::ostream &Students::ins(std::ostream &os) const {
    for (unsigned i = 0; i < vSize; i++) {
        if (container[i] != nullptr) {
            os << *container[i] << "===================\n";
        }
    }
    return os;
}

//Returns the stream from the inserter.
std::ostream &operator<<(std::ostream &os, const Students &ob) {
    return ob.ins(os);
}

//Returns the best scoring student from the list.
//An exception is thrown if no student is found.
Entry &Students::bestStudent() const {
    double bestGrade = 0;
    Entry *bestStudent = nullptr;
    unsigned cnt = 0;

    for (unsigned i = 0; i < vSize; i++) {
        if (container[i] != nullptr) {
            cnt++;
            if (container[i]->avgGrade > bestGrade) {
                bestStudent = container[i];
            }
        }
    }

    if (cnt == 0) {
        throw notUsed("The array doesn't have any entries.");
    }

    return *bestStudent;
}
