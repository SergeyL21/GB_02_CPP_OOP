/*
 * Created by Qt Creator 4.11.0 @ 21 Mar 2021 21:34:21
 *
 * Project: GB_CppOOP
 * File: task_6_2.h
 *
 * Author: Sergey Lola
 */
#pragma once

#include <ostream>

// ------------------------------------------------------------------------------------
// ЗАДАНИЕ 2: Создать собственный манипулятор endll для стандартного потока вывода,
// который выводит два перевода строки и сбрасывает буфер.

inline std::ostream &endll(std::ostream &s) {
  return std::flush((s.put('\n').put('\n')));
}


