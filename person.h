/*
 * Created by Qt Creator 4.11.0 @ 17 Mar 2021 18:23:19
 *
 * Project: GB_CppOOP
 * File: person.h
 *
 * Author: Sergey Lola
 */
#pragma once

#include "common.h"

namespace task_1 {

enum class Sex {
  Undefined,
  Male,
  Female
};

class Person {
public:
  inline Person() {}
  inline Person(const std::string &name, unsigned age, Sex sex, unsigned weight) :
    m_name(name), m_age(age), m_sex(sex), m_weight(weight) {}
  virtual ~Person() {}

  GETTER_SETTER(const std::string&, Name, m_name)
  GETTER_SETTER(unsigned, Age, m_age)
  GETTER_SETTER(Sex, Sex, m_sex)
  GETTER_SETTER(unsigned, Weight, m_weight)

private:
  std::string m_name;
  unsigned m_age {0u};
  Sex m_sex {Sex::Undefined};
  unsigned m_weight {0u};
};

class Student : public Person {
public:
  Student();
  Student(const std::string &name, unsigned age, Sex sex, unsigned weight, unsigned studyYear);
  // конструктор копирования также должен увеличивать счетчик на 1
  Student(const Student &rhs);
  Student &operator=(const Student &rhs);
  virtual ~Student();

  GETTER_SETTER(unsigned, StudyYear, m_studyYear)

  inline static unsigned count() { return m_studentCounter; }

private:
  unsigned m_studyYear {0u};
  static unsigned m_studentCounter;
};

} // namespace task_1
