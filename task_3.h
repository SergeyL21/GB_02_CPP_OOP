/*
 * Created by Qt Creator 4.11.0 @ 21 Mar 2021 22:05:45
 *
 * Project: GB_CppOOP
 * File: task_3.h
 *
 * Author: Sergey Lola
 */
#pragma once

#include <sstream>
#include "common.h"

namespace task_3 {

struct A { int x; int y; };

class Fraction {
public:
  inline Fraction(int numenator, int denominator) :
    m_num(numenator), m_denom(denominator) {
    // вызов assert'а в конструкторе не всегда хорошая идея,
    // если например мы хотим продолжить выполнение программы!
  }
  inline ~Fraction() {}

  GETTER(int, Numerator, m_num)
  GETTER(int, Denominator, m_denom)

  inline bool isValid() const { return (m_denom != 0); }

  // шаблонный оператор для преобразования из дроби в число
  template <typename T>
  inline operator T() const {
    static_assert(std::is_arithmetic<T>::value, "T must be an arithmetic type!");
    return (isValid() ? T(m_num) / m_denom : T{});
  }

  std::string print() const {
    std::ostringstream s;
    s << m_num << "/" << m_denom;
    return s.str();
  }

  friend Fraction operator+(const Fraction &lhs, const Fraction &rhs);
  friend Fraction operator-(const Fraction &lhs, const Fraction &rhs);
  friend Fraction operator*(const Fraction &lhs, const Fraction &rhs);
  friend Fraction operator/(const Fraction &lhs, const Fraction &rhs);

  friend Fraction operator-(const Fraction &f);

  friend bool operator==(const Fraction &lhs, const Fraction &rhs);
  friend bool operator!=(const Fraction &lhs, const Fraction &rhs);
  friend bool operator>(const Fraction &lhs, const Fraction &rhs);
  friend bool operator>=(const Fraction &lhs, const Fraction &rhs);
  friend bool operator<(const Fraction &lhs, const Fraction &rhs);
  friend bool operator<=(const Fraction &lhs, const Fraction &rhs);

private:
  int m_num {0};
  int m_denom {1};
};

Fraction operator+(const Fraction &lhs, const Fraction &rhs) {
  return {(lhs.m_num * rhs.m_denom) + (rhs.m_num * lhs.m_denom),
          (lhs.m_denom * rhs.m_denom)};
}

Fraction operator-(const Fraction &lhs, const Fraction &rhs) {
  return {(lhs.m_num * rhs.m_denom) - (rhs.m_num * lhs.m_denom),
          (lhs.m_denom * rhs.m_denom)};
}

Fraction operator*(const Fraction &lhs, const Fraction &rhs) {
  return {lhs.m_num * rhs.m_num, lhs.m_denom * rhs.m_denom};
}

Fraction operator/(const Fraction &lhs, const Fraction &rhs) {
  return {lhs.m_num * rhs.m_denom, lhs.m_denom * rhs.m_num};
}

Fraction operator-(const Fraction &f) {
  return {-f.m_num, f.m_denom};
}

bool operator==(const Fraction &lhs, const Fraction &rhs) {
  return (lhs.m_num * rhs.m_denom == lhs.m_denom * rhs.m_num);
}

bool operator!=(const Fraction &lhs, const Fraction &rhs) {
  return !(lhs == rhs);
}

bool operator>(const Fraction &lhs, const Fraction &rhs) {
  return (lhs.m_num * rhs.m_denom > lhs.m_denom * rhs.m_num);
}

bool operator<(const Fraction &lhs, const Fraction &rhs) {
  return (lhs.m_num * rhs.m_denom < lhs.m_denom * rhs.m_num);
}

bool operator>=(const Fraction &lhs, const Fraction &rhs) {
  return !(lhs < rhs);
}

bool operator<=(const Fraction &lhs, const Fraction &rhs) {
  return !(lhs > rhs);
}

} // namespace task_3

