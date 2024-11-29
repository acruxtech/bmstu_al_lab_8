# bmstu_al_lab_8

# Лабораторная работа № 9

## Теоретическая справка

> В C++ можно использовать различные типы объектов, которые различаются по использованию памяти. Так, глобальные объекты создаются при запуске программы и освобождаются при ее завершении. Локальные автоматические объекты создаются в блоке кода и удаляются, когда этот блок кода завершает работу. Локальные статические объекты создаются перед их первым использованием и освобождаются при завершении программы.

> Глобальные, а также статические локальные объекты помещаются в статической памяти, а локальные автоматические объекты размещаются в стеке. Объекты в статической памяти и стеке создаются и удаляются компилятором. Статическая память очищается при завершении программы, а объекты из стека существуют, пока выполняется блок, в котором они определены.

> В дополнение к этим типам в C++ можно создавать динамические объекты. Продолжительность их жизни не зависит от того, где они созданы. Динамические объекты существуют, пока не будут удалены явным образом. Динамические объекты размещаются в динамической памяти (free store).

Для управления динамическими объектами применяются операторы **new** и **delete**.

Оператор `new` выделяет место в динамической памяти для объекта и возвращает указатель на этот объект.

Оператор `delete` получает указатель на динамический объект и удаляет его из памяти.

#### Пример
```cc
int* p = new int(42);
std::cout << "value: " << *p << std::endl;
std::cout << "address: " << std::hex << p << std::endl;
delete p;
```

Кроме отдельных динамических объектов в языке C++ мы можем использовать динамические массивы. Для выделения памяти под динамический массив также используется оператор **new[]**. Для удаления динамического массива и освобождения его памяти применяется специальная форма оператора **delete[]**.

#### Пример
```cc
size_t n = 0;
std::cin > n;
int* p = new int[n];
for (size_t i = 0; i < n; ++i) {
    p[i] = rand();
}
// ...
delete[] p;
```

Полее полную информацию можно найти по ссылкам:
* [Динамические объекты](https://metanit.com/cpp/tutorial/4.11.php)
* [Динамические массивы](https://metanit.com/cpp/tutorial/4.12.php)
* [Еще про динамичесике массивы в C++](https://ravesli.com/urok-86-dinamicheskie-massivy/)
* [И еще](http://cppstudio.com/post/432/)

### Задание 1

Реализуйте фунции для работы со строками:

```cc
// Создает копию строки |str|.
char* CopyString(const char* str);

// Соединяет две строки в одну новую.
char* ConcatinateStrings(const char* a, const char* b);
```
**Примечание 1**. Использовать функции для работы со строками (`strstr`, `strlen`, `strcpy`, `strcat` и др) запрещено.

**Примечание 2**. Для копирования памяти необходимо использовать функции `memcpy` или `std::copy`.

### Задание 2

Реализуйте функции для работы со структурой матрицы.

```cc
struct Matrix {
  // двумерный массив с данными.
  int** data_ = nullptr;
  // количество столбцов
  size_t n_ = 0u;
  // количество строк
  size_t m_ = 0u;
};

// Создает заполненную нулями матрицу n x m.
void Construct(Matrix& out, size_t n, size_t m);
// Освобождает выделенную память.
void Destruct(Matrix& in);

// Создает копию матрицы |matrix|.
Matrix Copy(const Matrix& matrix);
// Возвращает сумму двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Add(const Matrix& a, const Matrix& b);
// Возвращает разницу двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Sub(const Matrix& a, const Matrix& b);
// Возвращает произведение двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Mult(const Matrix& a, const Matrix& b);

// Транспонирование матрицы.
void Transposition(Matrix& matrix);

// Сравнение двух матриц.
bool operator==(const Matrix& a, const Matrix& b);
```
