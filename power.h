/*
 * Created by Qt Creator 4.11.0 @ 07 Mar 2021 16:44:19
 *
 * Project: GB_CppOOP
 * File: power.h
 *
 * Author: Sergey Lola
 */
#pragma once

// --------------------------------------------------------------------------------------
class Power {
 public:
  Power() = default;
  ~Power() = default;

  void set(double a, double b);
  double calculate() const;

 private:
  double m_a{0.};
  double m_b{0.};
};
