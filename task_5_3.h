/*
 * Created by Qt Creator 4.11.0 @ 21 Mar 2021 22:05:45
 *
 * Project: GB_CppOOP
 * File: task_3.h
 *
 * Author: Sergey Lola
 */
#pragma once

#include <string>

#include "task_5_2.h"

namespace task_3 {

template <typename T>
using BasePair = task_2::Pair<std::string, T>;

// --------------------------------------------------------------------------------------
template <typename T>
class StringValuePair : public BasePair<T> {
public:
  inline StringValuePair() : BasePair<T>() {}
  inline StringValuePair(std::string const &first, T const &second) :
    BasePair<T>(first, second) {}
};

} // namespace task_3

