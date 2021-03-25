/*
 * Created by Qt Creator 4.11.0 @ 07 Mar 2021 16:24:09
 *
 * Project: GB_CppOOP
 * File: main.cpp
 *
 * Author: Sergey Lola
 */

#include <iostream>
#include <memory>

#include "task_1.h"
#include "task_2.h"
#include "task_3.h"

#include "card.h"

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
  // ЗАДАНИЕ 1: Создать абстрактный класс Figure (фигура). Его наследниками являются
  // классы Parallelogram (параллелограмм) и Circle (круг). Класс Parallelogram — базовый
  // для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб). Для всех
  // классов создать конструкторы. Для класса Figure добавить чисто виртуальную функцию
  // area() (площадь). Во всех остальных классах переопределить эту функцию, исходя из
  // геометрических формул нахождения площади.
  {
    cout << " --- TASK 1 --- " << endl;
    namespace n = task_1;
    std::unique_ptr<n::Figure> figure_1 {new n::Circle{4}};
    std::unique_ptr<n::Rectangle> figure_2 {new n::Rectangle{2.5, 4}};
    std::unique_ptr<n::Square> figure_3 {new n::Square{4}};
    std::unique_ptr<n::Rhombus> figure_4 {new n::Rhombus{2.5, 4}};

    cout << "Circle area: " << figure_1->area() << endl;
    cout << "Rectangle area: " << figure_2->area() << endl;
    cout << "Square area: " << figure_3->area() << endl;
    cout << "Rhombus area: " << figure_4->area() << endl;
  }
  // ------------------------------------------------------------------------------------
  // ЗАДАНИЕ 2: Создать класс Car (автомобиль) с полями company (компания) и model
  // (модель). Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). От
  // этих классов наследует класс Minivan (минивэн). Создать конструкторы для каждого из
  // классов, чтобы они выводили данные о классах. Создать объекты для каждого из классов
  // и посмотреть, в какой последовательности выполняются конструкторы. Обратить внимание
  // на проблему «алмаз смерти».
  {
    cout << endl << " --- TASK 2 --- " << endl;
    namespace n = task_2;
    cout << "CLASS \"Car\"" << endl;
    std::unique_ptr<n::Car> ptr {new n::Car{}};
    ptr.reset();

    cout << endl << "CLASS \"PassengerCar\"" << endl;
    ptr.reset(new n::PassengerCar{});
    ptr.reset();

    cout << endl << "CLASS \"Bus\"" << endl;
    ptr.reset(new n::Bus{});
    ptr.reset();

    cout << endl << "CLASS \"Minivan\"" << endl;
    ptr.reset(new n::Minivan{});
  }
  // ------------------------------------------------------------------------------------
  // ЗАДАНИЕ 3: Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель
  // (например, 3/7 или 9/2). Предусмотреть, чтобы знаменатель не был равен 0.
  // Перегрузить: математические бинарные операторы (+, -, *, /) для выполнения действий
  // с дробями; унарный оператор (-); логические операторы сравнения двух дробей (==, !=,
  // <, >, <=, >=).
  {
    cout << endl << " --- TASK 3 --- " << endl;
    namespace n = task_3;
    n::Fraction f1{1, 2}, f2{2, 8};
    cout << "f1 + f2 = " << (f1 + f2).print() << endl;
    cout << "f1 - f2 = " << (f1 - f2).print() << endl;
    cout << "f1 * f2 = " << (f1 * f2).print() << endl;
    cout << "f1 / f2 = " << (f1 / f2).print() << endl;
    cout << "-f1 = " << (-f1).print() << endl;
    cout << "(f1 == f2) = " << (f1 == f2) << endl;
    cout << "(f1 != f2) = " << (f1 != f2) << endl;
    cout << "(f1 > f2) = " << (f1 > f2) << endl;
    cout << "(f1 >= f2) = " << (f1 >= f2) << endl;
    cout << "(f1 < f2) = " << (f1 < f2) << endl;
    cout << "(f1 <= f2) = " << (f1 <= f2) << endl;
  }

  return 0;
}
