/*
 * Created by Qt Creator 4.11.0 @ 07 Mar 2021 16:24:09
 *
 * Project: GB_CppOOP
 * File: main.cpp
 *
 * Author: Sergey Lola
 */

#include <iostream>
#include <vector>
#include <unordered_map>

#include "task_1.h"
#include "task_2.h"
#include "task_3.h"

// ---------------------------------------------------------------------------
// вспомогательный макрос для удаления предупреждения об неиспользуемой
// переменной
#undef UNUSED
#define UNUSED(X) (void)(X);

// ---------------------------------------------------------------------------
// вспомогательный макрос для обозначения передачи аргумента по ссылке
#undef OUT
#define OUT

using namespace std;

// --------------------------------------------------------------------------------------
int main(int argc, const char ** argv) {
  UNUSED(argc)
  UNUSED(argv)

  // ------------------------------------------------------------------------------------
  // ЗАДАНИЕ 1: Добавить в контейнерный класс, который был написан в этом уроке, методы:
  // для удаления последнего элемента массива (аналог функции pop_back() в векторах);
  // для удаления первого элемента массива (аналог pop_front() в векторах);
  // для сортировки массива;
  // для вывода на экран элементов.
  {
    cout << " --- TASK 1 --- " << endl;
    namespace n = task_1;
    const std::string separator{", "};
    n::MyArray<int> arr {3, -7, 2, 8, 12, 11, 15, 1, -4};
    cout << "Origin array: " << arr.toString(separator) << endl;
    arr.popBack();
    cout << "Array popBack(): " << arr.toString(separator) << endl;
    arr.popFront();
    cout << "Array popFront(): " << arr.toString(separator) << endl;
    arr.sort();
    cout << "Array sort(): " << arr.toString(separator) << endl;
  }
  // ------------------------------------------------------------------------------------
  // ЗАДАНИЕ 2: Дан вектор чисел, требуется выяснить, сколько среди них различных.
  // Постараться использовать максимально быстрый алгоритм.
  {
    cout << endl << " --- TASK 2 --- " << endl;
    namespace n = task_1;
    n::MyArray<int> arr {1, 3, 7, 8, 1, 2, 3, 3, 9, 7};
    int result{0};
    // используем для подсчета кол-ва именно различных чисел ассоциативный контейнер
    // (да, "ленивый вариант", возможно не самый быстрый, зато пишется в течении пары
    // минут :)
    unordered_map<int, int> map;
    for (std::size_t n{0u}; n < arr.getLength(); ++n) {
      auto &element = map[arr[n]];
      ++element;
      if (element == 1) {
        ++result;
      }
    }
    cout << "Array: " << arr.toString(std::string{", "}) << endl;
    cout << "Count of non-repeating array elements : " << result << endl;
  }
  return 0;
}
