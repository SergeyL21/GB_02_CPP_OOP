/*
 * Created by Qt Creator 4.11.0 @ 08 Apr 2021 21:24:56
 *
 * Project: GB_CppOOP
 * File: task_8_3.cpp
 *
 * Author: Sergey Lola
 */

#include "task_8_3.h"

// --------------------------------------------------------------------------------------
RobotException::RobotException(const std::string &ltext, const Robot *data) :
  std::logic_error("") {
  std::ostringstream s;
  s << ltext << " pos(" << data->m_pos.x << "," <<
       data->m_pos.y << ") direction=" << static_cast<int>(data->m_direction);
  p_ltext = s.str();
}

// --------------------------------------------------------------------------------------
void Robot::move() {
  switch (m_direction) {
    case Direction::North:  --m_pos.y; break;
    case Direction::East:   ++m_pos.x; break;
    case Direction::South:  ++m_pos.y; break;
    case Direction::West:   --m_pos.x; break;
    default: throw IllegalCommand{this};
  }

  // проверка на то, что не вышли за границы сетки
  auto gridSize = m_grid.getSize();
  if (((std::abs(m_pos.x)) > gridSize.x) ||
      ((std::abs(m_pos.y)) > gridSize.y)) {
    throw OffTheField{this};
  }
}

// --------------------------------------------------------------------------------------
void Robot::setGrid(const Grid &grid) {
  m_grid = grid;
  auto gridSize = m_grid.getSize();
  // если получена новая сетка, устанавливаем робота посередине этой новой сетки
  m_pos = {gridSize.x / 2, gridSize.y / 2};
}


