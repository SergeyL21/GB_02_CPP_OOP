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
