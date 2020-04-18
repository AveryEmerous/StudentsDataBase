//Made by Daniel Ivanov with GCC-9 C++20.

#ifndef H_EXCEP
#define H_EXCEP

#include <exception>

class noSpace : public std::bad_alloc {
   private:
    char *vDesc;

   public:
    noSpace(const char *desc);
    ~noSpace();

    const char *desc();
};

class notUsed : public std::bad_alloc {
   private:
    char *vDesc;

   public:
    notUsed(const char *desc);
    ~notUsed();

    const char *desc();
};

#endif
