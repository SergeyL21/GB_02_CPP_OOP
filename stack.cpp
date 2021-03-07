/*
 * Created by Qt Creator 4.11.0 @ 07 Mar 2021 16:59:53
 *
 * Project: GB_CppOOP
 * File: stack.cpp
 *
 * Author: Sergey Lola
 */

#include "stack.h"

#include <iostream>

using namespace std;

// --------------------------------------------------------------------------------------
void Stack::reset() {
  m_data.clear();
  m_size = 0;
}

// --------------------------------------------------------------------------------------
bool Stack::push(int value) {
  if (m_size < ARRAY_SIZE) {
    m_data.push_back(value);
    ++m_size;
    return true;
  }
  return false;
}

// --------------------------------------------------------------------------------------
int Stack::pop() {
  int res{0};
  if (m_size != 0) {
    res = m_data.back();
    m_data.pop_back();
    --m_size;
    return res;
  } else {
    cout << "It's not possible to pop a number from the stack!" << endl;
  }
  return res;
}

// --------------------------------------------------------------------------------------
void Stack::print() const {
  cout << "( ";
  for (auto it = m_data.cbegin(); it != m_data.cend(); ++it) {
    cout << *it << " ";
  }
  cout << ")" << endl;
}
