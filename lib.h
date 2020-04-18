//Made by Daniel Ivanov with GCC-9 C++20.

#ifndef H_LIB
#define H_LIB

#include <iostream>

struct Entry {
    char* name;
    unsigned FN;
    double avgGrade;
    Entry(const char* name = "No Name", unsigned FN = 0, double avgGrade = 2);
    ~Entry();
    Entry& operator=(double avgGrade);
    Entry& operator=(const char* name);
    virtual std::ostream& ins(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, const Entry& ob);

class Students {
   private:
    Entry** container;
    unsigned vSize;

   public:
    Students(unsigned vSize = 0);
    Students(const Students& r);
    Students& operator=(const Students& r);
    ~Students();

    unsigned studMod(unsigned FN);
    unsigned searchFN(unsigned FN);
    void insert(const char* name = "No Name", unsigned FN = 0, double avgGrade = 1);

    Entry& bestStudent() const;

    Entry& operator[](unsigned FN);
    virtual std::ostream& ins(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, const Students& ob);

#endif