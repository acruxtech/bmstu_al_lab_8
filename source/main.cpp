#include <iostream>

#include "../include/task1.hpp"
#include "../include/task2.hpp"


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
            Matrix matrix;
            Construct(matrix, 3, 3);
            for (size_t i = 0; i < 3; ++i) {
                for (size_t j = 0; j < 3; ++j) {
                    matrix.data_[i][j] = i + j;
                }
            }

            std::cout << "Матрица:" << std::endl;
            for (size_t i = 0; i < 3; ++i) {
                for (size_t j = 0; j < 3; ++j) {
                    std::cout << matrix.data_[i][j] << " ";
                }
                std::cout << std::endl;
            }

            Matrix copy = Copy(matrix);
            std::cout << "Копия матрицы:" << std::endl;
            for (size_t i = 0; i < 3; ++i) {
                for (size_t j = 0; j < 3; ++j) {
                    std::cout << copy.data_[i][j] << " ";
                }
                std::cout << std::endl;
            }

            Matrix a;
            Construct(a, 3, 3);
            for (size_t i = 0; i < 3; ++i) {
                for (size_t j = 0; j < 3; ++j) {
                    a.data_[i][j] = i - j;
                }
            }
            Matrix sum = Add(matrix, a);
            std::cout << "Сумма матриц:" << std::endl;
            for (size_t i = 0; i < 3; ++i) {
                for (size_t j = 0; j < 3; ++j) {
                    std::cout << sum.data_[i][j] << " ";
                }
                std::cout << std::endl;
            }

            Matrix diff = Sub(matrix, a);
            std::cout << "Разность матриц:" << std::endl;
            for (size_t i = 0; i < 3; ++i) {
                for (size_t j = 0; j < 3; ++j) {
                    std::cout << diff.data_[i][j] << " ";
                }
                std::cout << std::endl;
            }

            Matrix b;
            Construct(b, 3, 3);
            for (size_t i = 0; i < 3; ++i) {
                for (size_t j = 0; j < 3; ++j) {
                    b.data_[i][j] = i * j;
                }
            }
            Matrix prod = Mult(matrix, b);
            std::cout << "Произведение матриц:" << std::endl;
            for (size_t i = 0; i < 3; ++i) {
                for (size_t j = 0; j < 3; ++j) {
                    std::cout << prod.data_[i][j] << " ";
                }
                std::cout << std::endl;
            }

            Transposition(matrix);
            std::cout << "Транспонированная матрица:" << std::endl;
            for (size_t i = 0; i < 3; ++i) {
                for (size_t j = 0; j < 3; ++j) {
                    std::cout << matrix.data_[i][j] << " ";
                }
                std::cout << std::endl;
            }
            break;
        }
        default: {
            std::cout << "Неверный номер задания" << std::endl;
            break;
        }       
    }
    
    return 0;
}
