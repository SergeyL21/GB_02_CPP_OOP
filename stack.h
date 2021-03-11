/*
 * Created by Qt Creator 4.11.0 @ 07 Mar 2021 16:58:41
 *
 * Project: GB_CppOOP
 * File: stack.h
 *
 * Author: Sergey Lola
 */
#pragma once

#include <list>

// --------------------------------------------------------------------------------------
class Stack {
  static const int ARRAY_SIZE{10};

 public:
  Stack() = default;
  ~Stack() = default;

  void reset();
  bool push(int value);
  int pop();
  void print() const;

 private:
  std::list<int> m_data;
  int m_size{0};
};
