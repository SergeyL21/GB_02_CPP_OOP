/*
 * Created by Qt Creator 4.11.0 @ 08 Apr 2021 21:13:51
 *
 * Project: GB_CppOOP
 * File: task_8_3.h
 *
 * Author: Sergey Lola
 */

#pragma once

#include <stdexcept>
#include <memory>
#include <sstream>

#include "common.h"

// --------------------------------------------------------------------------------------
// ЗАДАНИЕ 3: Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у
// которого есть метод, означающий задание переместиться на соседнюю позицию. Эти методы
// должны запускать классы-исключения OffTheField, если робот должен уйти с сетки, и
// IllegalCommand, если подана неверная команда (направление не находится в нужном
// диапазоне). Объект исключения должен содержать всю необходимую информацию — текущую
// позицию и направление движения. Написать функцию main, пользующуюся этим классом и
// перехватывающую все исключения от его методов, а также выводящую подробную информацию
// о всех возникающих ошибках.

// структура описывающая точку
struct Point {
  int x {0};
  int y {0};
};

// --------------------------------------------------------------------------------------
// перечисление описывающее направление движения
enum class Direction { None, North, East, South, West };

// --------------------------------------------------------------------------------------
// класс описывающий сетку
class Grid {
public:
  inline Grid() {}
  inline Grid(int width, int height) : m_size({width, height}) {}
  ~Grid() = default;

  GETTER(Point, Size, m_size)

private:
  Point m_size;
};

// --------------------------------------------------------------------------------------
// класс описывающий робота
class Robot {
  friend class RobotException;
public:
  Robot() = default;
  ~Robot() = default;

  GETTER(Point, Pos, m_pos)
  GETTER(Grid, Grid, m_grid)
  GETTER_SETTER(Direction, Direction, m_direction)

  void move();
  void setGrid(const Grid &grid);

private:
  Point m_pos;
  Direction m_direction {Direction::None};
  Grid m_grid;
};

// --------------------------------------------------------------------------------------
// базовый класс для исключений выбрасываемых при использовании класса робот
class RobotException : public std::logic_error {
public:
  RobotException(const std::string &ltext, const Robot *data);
  virtual ~RobotException() = default;

  inline virtual const char *what() const noexcept override {
    return p_ltext.c_str();
  }

protected:
  std::string p_ltext;
};

// --------------------------------------------------------------------------------------
// производный класс для исключения, когда робот выходит за пределы поля
class OffTheField : public RobotException {
public:
  inline OffTheField(const Robot *data) :
    RobotException(std::string{"off the field"}, data) {}
  virtual ~OffTheField() = default;
};

// --------------------------------------------------------------------------------------
// производный класс для исключения, когда роботу передается неверная команда
class IllegalCommand : public RobotException {
public:
  inline IllegalCommand(const Robot *data) :
    RobotException(std::string{"illegal command"}, data) {}
  virtual ~IllegalCommand() = default;
};


