#include <iostream>

#include "../include/task1.hpp"


int main() {
    int task_number;
    std::cout << "Введите номер задачи: ";
    std::cin >> task_number;
    switch (task_number) {
        case 1: {
            const char* original = "test string";
            char* copy = CopyString(original);
            if (copy != nullptr) {
                std::cout << "Оригинал: " << original << std::endl;
                std::cout << "Копия: " << copy << std::endl;
                free(copy);
            }

            const char* str1 = "test ";
            const char* str2 = "string";
            char* result = ConcatinateStrings(str1, str2);
            if (result != nullptr) {
                std::cout << result << std::endl;
                delete[] result;
            }

            break;
        }
        case 2: {
            std::cout << "not implemented" << std::endl;
            break;
        }
        default: {
            std::cout << "Неверный номер задания" << std::endl;
            break;
        }       
    }
    
    return 0;
}
