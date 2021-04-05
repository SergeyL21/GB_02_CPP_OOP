/*
 * Created by Qt Creator 4.11.0 @ 18 Mar 2021 16:56:37
 *
 * Project: GB_CppOOP
 * File: common.h
 *
 * Author: Sergey Lola
 */
#pragma once

#include <string>
#include <iostream>

#define GETTER(Type, Name, Operand) \
  public: \
  inline Type get##Name() const { return Operand; }

#define SETTER(Type, Name, Operand) \
  public: \
  inline void set##Name(Type value) { Operand = value; }

#define GETTER_SETTER(Type, Name, Operand) \
  GETTER(Type, Name, Operand) \
  SETTER(Type, Name, Operand)

// --------------------------------------------------------------------------------------
// вспомогательный шаблонный класс для имитации for-ranged перечислений
template<typename T, T /*_First*/, T /*_Last*/>
class ExtEnum {
public:
  class Iterator {
  public:
    Iterator(int value) : m_value( value ) {}
    T operator*() const { return static_cast<T>(m_value); }
    void operator++() { ++m_value; }
    bool operator!=(Iterator rhs) { return m_value != rhs.m_value; }
   private:
    int m_value;
  };
};

// --------------------------------------------------------------------------------------
template<typename T, T _First, T _Last>
typename ExtEnum<T, _First, _Last>::Iterator begin(ExtEnum<T, _First, _Last>) {
  return typename ExtEnum<T, _First, _Last>::Iterator(static_cast<int>(_First));
}

// --------------------------------------------------------------------------------------
template<typename T, T _First, T _Last>
typename ExtEnum<T, _First, _Last>::Iterator end(ExtEnum<T, _First, _Last>) {
  return typename ExtEnum<T, _First, _Last>::Iterator(static_cast<int>(_Last) + 1);
}
