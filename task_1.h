/*
 * Created by Qt Creator 4.11.0 @ 21 Mar 2021 21:02:13
 *
 * Project: GB_CppOOP
 * File: task_1.h
 *
 * Author: Sergey Lola
 */
#pragma once

#include <math.h>

namespace task_1 {

// --------------------------------------------------------------------------------------
class Figure {
public:
  inline virtual ~Figure() {}

  virtual double area() const = 0;
};

// --------------------------------------------------------------------------------------
class Parallelogram : public Figure {
public:
  inline virtual ~Parallelogram() override {}
};

// --------------------------------------------------------------------------------------
class Circle : public Figure {
public:
  inline Circle(double r) : Figure(), p_r(r) {}
  inline virtual ~Circle() override {}

  inline virtual double area() const override { return M_PI * std::pow(p_r, 2.); }

protected:
  double p_r {0.};
};

// --------------------------------------------------------------------------------------
class Rectangle : public Parallelogram {
public:
  inline Rectangle(double a, double b) : Parallelogram(), p_a(a), p_b(b) {}
  inline virtual ~Rectangle() override {}

  inline virtual double area() const override { return p_a * p_b; }

protected:
  double p_a {0.}, p_b {0.};
};

// --------------------------------------------------------------------------------------
class Square : public Parallelogram {
public:
  inline Square(double a) : Parallelogram(), p_a(a) {}
  inline virtual ~Square() override {}

  inline virtual double area() const override { return std::pow(p_a, 2.); }

protected:
  double p_a {0.};
};

// --------------------------------------------------------------------------------------
class Rhombus : public Parallelogram {
public:
  inline Rhombus(double d1, double d2) : Parallelogram(), p_d1(d1), p_d2(d2) {}
  inline virtual ~Rhombus() override {}

  inline virtual double area() const override { return 0.5 * p_d1 * p_d2; }

protected:
  double p_d1 {0.}, p_d2 {0.};
};

} // namespace task_1

