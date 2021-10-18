[comment]: <> (# Autograding Example: C++)

[comment]: <> (This example project is written in C++, and tested with make and [Catch2]&#40;https://github.com/catchorg/Catch2&#41;.)

[comment]: <> (### The assignment)

[comment]: <> (The tests are failing right now because of a bad base case in the factorial function. Correcting the base case will fix the tests.)

[comment]: <> (### Setup command)

[comment]: <> (N/A)

[comment]: <> (### Run command)

[comment]: <> (`make test`)

[comment]: <> (### Notes)

[comment]: <> (- `g++` can be used to compile and link C++ applications for use with existing test harnesses or other C++ testing frameworks.)

[comment]: <> (- If students push `a.out` files, the autograder may attempt to run that version instead of a newly compiled binary. If this happens, and your student isn't on Linux, the script will crash. To fix this issue, it's recommended to clean before building.)


# Лабораторная работа 3

    Сдать до 31.10 включительно.
    За каждую неделю опоздания количество баллов за задание умножается на 0.7.
    Количество баллов за каждое задание сданное на неделю раньше умножается на 1.1.

    
    Во всех задачах матрицы задаются вектором векторов.
    Длины строк матрицы одинаковы, если не сказано обратное.
    Имена функций должны совпадатать с именами функций в примерах.

### Сложность А
        (1 балл за задание)
        (6 задач)

<ol>
<li>
Напишите функцию, которая принимает на вход две матрицы, заполненные целыми числами.
Функция должна возвращать true, если они равны 
и false, если нет.

```c++
    AreMatricesIdentical( {{1, 2}, {1, 2}}, {{1, 2}, {1, 2}} ) -> true
    AreMatricesIdentical( {{1, 2, 3}}, {{3, 2, 1}} ) -> false
    AreMatricesIdentical( {}, {{}} ) -> false
```
</li>

<li>
Напишите функцию, которая принимает на вход матрицу, заполненную целыми числами.
Функция должна находить столбец с максимальной суммой элементов и возвращает сумму его элементов.

[comment]: <> (_0 &le; N &le; 10<sup>3</sup>_)

```c++
    TheGreatestColumnSum( {{1, 2}, {3, 4}} ) -> 6
    TheGreatestColumnSum( {{1, 2, 3}, {3, 2, 1}} ) -> 4
    TheGreatestColumnSum( {} ) -> 0 
```
</li>


<li>
Напишите функцию, которая принимает на вход две строки. Функция должна проверять
является ли вторая строка префиксом первой. Пустая строка
является префиксом любой другой строки.

```c++
    IsPrefix( "automobile", "auto" ) -> true
    IsPrefix( "automobile", "Auto" ) -> false
    IsPrefix( "Promiscuous girl", "Prom" ) -> true
```
</li>

<li>
Напишите функцию, которая принимает на вход целое число N. Она должна возвращать
квадратную симметричную относительно главной диагонали матрицу
<a href="https://en.wikipedia.org/wiki/Symmetric_matrix">[ Wiki ]</a>
размера N. Все числа в матрице, за исключением симметричных
элементов должны различаться.

```c++
    CreateSymmetricMatrix(2) -> {{1, 2},
                                 {2, 3}}
    CreateSymmetricMatrix(3) -> {{1, 2, 3},
                                 {2, 4, 5},
                                 {3, 5, 6}}
    CreateSymmetricMatrix(0) -> {}
```
</li>

<li>
Напишите функцию, которая на вход принимает строку. В строке находится информация, которая
описывает группу студентов. Формат строки следующий: "(имя студента) (фамилия студента) 
"                          

```c++
    AreMatricesIdentical( {{1, 2}, {1, 2}}, {{1, 2}, {1, 2}} ) -> true
    AreMatricesIdentical( {{1, 2, 3}}, {{3, 2, 1}} ) -> false
    AreMatricesIdentical( {}, {{}} ) -> false
```
</li>

<li>
Напишите функцию, которая сравнивает две матрицы и возвращает true, если они равны
и false, если нет. Размеры матриц могут отличаться.

```c++
    AreMatricesIdentical( {{1, 2}, {1, 2}}, {{1, 2}, {1, 2}} ) -> true
    AreMatricesIdentical( {{1, 2, 3}}, {{3, 2, 1}} ) -> false
    AreMatricesIdentical( {}, {{}} ) -> false
```
</li>
</ol>
