/*
 * Created by Qt Creator 4.11.0 @ 21 Mar 2021 21:34:21
 *
 * Project: GB_CppOOP
 * File: task_2.h
 *
 * Author: Sergey Lola
 */
#pragma once

#include <iostream>
#include <string>

namespace task_2 {

class Car {
public:
  inline Car() { std::cout << " Car()" << std::endl; }
  inline virtual ~Car() { std::cout << " ~Car()" << std::endl; }

protected:
  std::string m_company;
  std::string m_model;
};

class PassengerCar : public virtual Car {
public:
  inline PassengerCar() { std::cout << " PassengerCar()" << std::endl; }
  inline virtual ~PassengerCar() { std::cout << " ~PassengerCar()" << std::endl; }
};

class Bus : public virtual Car {
public:
  inline Bus() { std::cout << " Bus()" << std::endl; }
  inline virtual ~Bus() { std::cout << " ~Bus()" << std::endl; }
};

class Minivan : public PassengerCar, public Bus {
public:
  inline Minivan() { std::cout << " Minivan()" << std::endl; }
  inline virtual ~Minivan() { std::cout << " ~Minivan()" << std::endl; }
};

} // namespace task_2

