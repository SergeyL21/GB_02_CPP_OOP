/*
 * Created by Qt Creator 4.11.0 @ 24 Mar 2021 21:52:41
 *
 * Project: GB_CppOOP
 * File: task_1.h
 *
 * Author: Sergey Lola
 */
#pragma once

#include <type_traits>

namespace task_1 {

// --------------------------------------------------------------------------------------
template <typename T>
class Pair {
  using __rule_T__ = typename std::is_nothrow_default_constructible<T>;
public:
  inline Pair() noexcept((__rule_T__::value)) {}
  inline Pair(T const &first, T const &second) noexcept((__rule_T__::value))
    : m_first(first), m_second(second) {}

  inline T first() const { return m_first; }
  inline T second() const { return m_second; }

private:
  T m_first {};
  T m_second {};
};

} // namespace task_1

