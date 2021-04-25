/*
 * Created by Qt Creator 4.11.0 @ 08 Apr 2021 19:34:33
 *
 * Project: GB_CppOOP
 * File: task_8_1.h
 *
 * Author: Sergey Lola
 */
#pragma once

#include <limits>
#include <type_traits>
#include <string>

namespace my_funcs {

// --------------------------------------------------------------------------------------
// ЗАДАНИЕ 1: Написать шаблонную функцию div, которая должна вычислять результат деления
// двух параметров и запускать исключение DivisionByZero, если второй параметр равен 0.
// В функции main выводить результат вызова функции div в консоль, а также ловить
// исключения.
template <typename T>
std::enable_if_t<!std::numeric_limits<T>::is_integer, T> div(T num, T denom) {
  if (denom < std::numeric_limits<T>::epsilon()) {
    throw std::string{"DivisionByZero"};
  }
  return num / denom;
}

} // namespace my_funcs
