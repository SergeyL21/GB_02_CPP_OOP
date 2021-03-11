/*
 * Created by Qt Creator 4.11.0 @ 07 Mar 2021 16:45:02
 *
 * Project: GB_CppOOP
 * File: power.cpp
 *
 * Author: Sergey Lola
 */

#include "power.h"

#include <math.h>

// --------------------------------------------------------------------------------------
void Power::set(double a, double b) {
  m_a = a;
  m_b = b;
}

// --------------------------------------------------------------------------------------
double Power::calculate() const { return std::pow(m_a, m_b); }
