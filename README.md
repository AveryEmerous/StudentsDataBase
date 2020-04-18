# StudentsDataBase 0.1
Built with GCC9-C++20 on Manjaro.

# Basic interface
Contains a basic interface in main.cpp to use a basic implementation of these functions with custom exception handling.

# Functions
* Struct Entry
  - Data members
    - Name
    - Faculty number
    - Average grade
  - Constructor that initializes the above mentioned values. Also works as a default constructor as it has default values.
  - Two equal redefinitions for changing the grade and name.
  - Inserter and redefintion of << for compatability with ostream. Prints out the data members contained in an object.

* Class Students
  - Data members
    - 2D container dynamic array
    - Size of the array
  - Constuctor that initializes that array with null pointers. Also works as a default constructor as it has default values.
  - Copy constructor and redefintion of equal sign. They initialize the array to the same size and with the same contents as the source array.
  - Destructor that frees up all of the memory assigned to the current object.
  - A modulo function for finding the best position for the entry number.
  - An insertion function that allocates memory for an entry with a name, faculty number and average grade. If the faculty number position is already taken, a new position will be found and assigned to it. If there are no more positions availble, an exception is thrown.
  - A search function that allows finding a faculty number if it is not found at the expected position in the array.
  - Returns the entry of the best performing student based on their average grade. If there are no students to be found and exception will be thrown.
  - Redefinition of the square brackets for easier acess to entries and modification. 
  - Inserter and redefintion of << for compatability with ostream. Prints out all of the entries in the array.

* Classes for custom exception handling that can have an appended description of their own.
  - noSpace exception - is meant to be thrown when there's not enough space to allocate for a new entry.
  - notUsed exception - is meant to be thrown when there's a function that needs at least one entry to function but none were found. 
  
