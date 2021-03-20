/*
 * Created by Qt Creator 4.11.0 @ 07 Mar 2021 16:24:09
 *
 * Project: GB_CppOOP
 * File: main.cpp
 *
 * Author: Sergey Lola
 */

#include <iostream>
#include <map>

#include "person.h"
#include "fruit.h"

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
  // ЗАДАНИЕ 1: Создать класс Person (человек) с полями: имя, возраст, пол и вес.
  // Определить методы переназначения имени, изменения возраста и веса. Создать
  // производный класс Student (студент), имеющий поле года обучения. Определить методы
  // переназначения и увеличения этого значения. Создать счетчик количества созданных
  // студентов. В функции main() создать несколько студентов. По запросу вывести
  // определенного человека.
  {
    cout << " --- TASK 1 --- " << endl;
    namespace n = task_1;
    const map<string, n::Student> students {
      {string{"John Smith"}, {string{"John Smith"}, 21, n::Sex::Male, 77, 1667}},
      {string{"Ivan Ivanov"}, {string{"Ivan Ivanov"}, 18, n::Sex::Male, 65, 2000}},
      {string{"Olga Buzova"}, {string{"Olga Buzova"}, 25, n::Sex::Female, 50, 2010}}
    };
    string request;
    cout << "Please enter a student's name (total number " << n::Student::count() << "): ";
    getline(OUT cin, OUT request);
    auto find_it = students.find(request);
    if (find_it != students.cend()) {
      const auto &info = find_it->second;
      cout << "Found the following information: age = " << info.getAge()
           << ", sex = " << (n::Sex::Male == info.getSex() ? string{"Male"} : string{"Female"})
           << ", weight = " << info.getWeight()
           << ", studyYear = " << info.getStudyYear()
           << endl;
    }
    else {
      cout << "There's no student with current request!" << endl;
    }
  }
  // ------------------------------------------------------------------------------------
  // ЗАДАНИЕ 2: Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс
  // Fruit (фрукт). У Fruit есть две переменные-члена: name (имя) и color (цвет). Добавить
  // новый класс GrannySmith, который наследует класс Apple.
  {
    cout << endl << " --- TASK 2 --- " << endl;
    namespace n = task_2;
    n::Apple a{std::string{"red"}};
    n::Banana b{};
    n::GrannySmith c{};

    cout << "My " << a.getName() << " is " << a.getColor() << "." << endl;
    cout << "My " << b.getName() << " is " << b.getColor() << "." << endl;
    cout << "My " << c.getName() << " is " << c.getColor() << "." << endl;
  }
  return 0;
}
