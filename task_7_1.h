/*
 * Created by Qt Creator 4.11.0 @ 04 Apr 2021 22:33:01
 *
 * Project: GB_CppOOP
 * File: task_7_1.h
 *
 * Author: Sergey Lola
 */
#pragma once

#include "common.h"

#include <chrono>
#include <memory>

// --------------------------------------------------------------------------------------
// ЗАДАНИЕ 1: Создайте класс Date с полями день, месяц, год и методами доступа к этим
// полям. Перегрузите оператор вывода для данного класса. Создайте два "умных" указателя
// today и date. Первому присвойте значение сегодняшней даты. Для него вызовите по
// отдельности методы доступа к полям класса Date, а также выведите на экран данные всего
// объекта с помощью перегруженного оператора вывода. Затем переместите ресурс, которым
// владеет указатель today в указатель date. Проверьте, являются ли нулевыми указатели
// today и date и выведите соответствующую информацию об этом в консоль.

class Date {
public:
  inline Date(int day, int month, int year) : m_day(day), m_month(month), m_year(year) {
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    auto local_tm = *localtime(&now);
    local_tm.tm_mday = day;
    local_tm.tm_mon = month - 1;
    local_tm.tm_year = year - 1900;
    m_tm = mktime(&local_tm);
  }

  inline friend std::wostream &operator<<(std::wostream &s, const Date &date) {
    static const std::wstring sep{L"/"};
    return (s << date.m_day << sep << date.m_month << sep << date.m_year);
  }

  inline bool operator>(const Date &other) const {
    return (m_tm > other.m_tm);
  }

  GETTER(int, Day, m_day)
  GETTER(int, Month, m_month)
  GETTER(int, Year, m_year)

private:
  int m_day{0};
  int m_month{0};
  int m_year{0};
  std::time_t m_tm;
};

using PtrDate = std::unique_ptr<Date>;
