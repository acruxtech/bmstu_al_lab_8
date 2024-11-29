#include <iostream>

#include "../include/task1.hpp"


int main() {
    int task_number;
    std::cout << "Введите номер задачи: ";
    std::cin >> task_number;
    switch (task_number) {
        case 1: {
            
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
