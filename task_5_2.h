/*
 * Created by Qt Creator 4.11.0 @ 21 Mar 2021 21:34:21
 *
 * Project: GB_CppOOP
 * File: task_2.h
 *
 * Author: Sergey Lola
 */
#pragma once

#include <type_traits>

namespace task_2 {

// --------------------------------------------------------------------------------------
template <typename T1, typename T2>
class Pair {
  using __rule_T1__ = typename std::is_nothrow_default_constructible<T1>;
  using __rule_T2__ = typename std::is_nothrow_default_constructible<T2>;
public:
  inline Pair() noexcept((__rule_T1__::value && __rule_T2__::value)) {}
  inline Pair(T1 const &first, T2 const &second)
    noexcept((__rule_T1__::value && __rule_T2__::value)) :
    m_first(first), m_second(second) {}

  inline T1 first() const { return m_first; }
  inline T2 second() const { return m_second; }

private:
  T1 m_first {};
  T2 m_second {};
};

} // namespace task_2

