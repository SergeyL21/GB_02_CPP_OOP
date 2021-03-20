/*
 * Created by Qt Creator 4.11.0 @ 17 Mar 2021 18:26:32
 *
 * Project: GB_CppOOP
 * File: person.cpp
 *
 * Author: Sergey Lola
 */

#include "person.h"

using namespace std;

namespace task_1 {
// ------------------------ STATIC MEMBERS INIT FIELD -----------------------------------
unsigned Student::m_studentCounter {0u};

// --------------------------------------------------------------------------------------
Student::Student() { ++m_studentCounter; }

// --------------------------------------------------------------------------------------
Student::Student(const string &name,
                 unsigned age,
                 Sex sex,
                 unsigned weight,
                 unsigned studyYear) :
  Person(name, age, sex, weight),
  m_studyYear(studyYear) {
  ++m_studentCounter;
}

// --------------------------------------------------------------------------------------
Student::Student(const Student &rhs) {
  ++m_studentCounter;
  *this = rhs;
}

// -------------------------------------------------------------------------------------
Student &Student::operator=(const Student &rhs) {
  if (this != &rhs) {
    this->m_studyYear = rhs.m_studyYear;
    Person::operator=(static_cast<const Person&>(rhs));
  }
  return *this;
}

// --------------------------------------------------------------------------------------
Student::~Student() { --m_studentCounter; }

} // namespace task_1
