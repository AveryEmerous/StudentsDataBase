//Made by Daniel Ivanov with GCC-9 C++20.

#include <iostream>

#include "lib.h"
#include "myExcept.hpp"

int main() {
    unsigned choice, FN;
    double grade;
    char name[1000];

    std::cout << "Enter the desired size of the database.\n";
    std::cin >> choice;
    Students table(choice);

    do {
        try {
            std::cout << '\n';
            std::cout << "0)Exit.\n";
            std::cout << "1)Print all.\n";
            std::cout << "2)Add an FN.\n";
            std::cout << "3)Edit name to an FN.\n";
            std::cout << "4)Edit average grade to an FN.\n";
            std::cout << "5)Show best average grade.\n";

            std::cout << "\nChooce one option: ";
            std::cin >> choice;
            std::cout << '\n';

            switch (choice) {
                case 0:
                    break;
                case 1: {
                    std::cout << table;
                    break;
                }
                case 2: {
                    std::cout << "Enter FN:\n";
                    std::cin >> FN;
                    std::cout << "Enter name:\n";
                    std::cin.getline(name, 999);
                    std::cout << "Enter average grade:\n";
                    std::cin >> grade;
                    table.insert(name, FN, grade);
                    break;
                }
                case 3: {
                    std::cout << "Enter FN:\n";
                    std::cin >> FN;
                    std::cout << "Enter name:\n";
                    std::cin.getline(name, 999);
                    table[FN] = name;
                    break;
                }
                case 4: {
                    std::cout << "Enter FN:\n";
                    std::cin >> FN;
                    std::cout << "Enter average grade:\n";
                    std::cin >> grade;
                    table[FN] = grade;
                    break;
                }
                case 5: {
                    std::cout << table.bestStudent();
                    break;
                }
                default: {
                    std::cout << "Invalid choice.\n";
                    break;
                }
            }
        } catch (noSpace &e) {
            std::cout << "A memory error occured: " << e.what() << "|" << e.desc() << '\n';
            std::cout << "Type: " << typeid(e).name() << '\n';

            std::cout << "There's not enough memory to continue the operation. Please, assign more memory.\n";
        } catch (notUsed &e) {
            std::cout << "A memory error occured: " << e.what() << "|" << e.desc() << '\n';
            std::cout << "Type: " << typeid(e).name() << '\n';

            std::cout << "There are no entries. Please, assign a new entry to use this function.\n";
        } catch (std::exception &e) {
            std::cout << "An error occured: " << e.what() << '\n';
            std::cout << "Type: " << typeid(e).name() << '\n';
        }
    } while (choice);

    return 0;
}