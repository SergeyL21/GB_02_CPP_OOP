/*
 * Created by Qt Creator 4.11.0 @ 18 Mar 2021 16:54:07
 *
 * Project: GB_CppOOP
 * File: fruit.h
 *
 * Author: Sergey Lola
 */
#pragma once

#include "common.h"

namespace task_2 {

class Fruit {
public:
  inline Fruit(const std::string &name, const std::string &color) :
    p_name(name), p_color(color) {}
  virtual ~Fruit() {}

  GETTER_SETTER(const std::string&, Name, p_name)
  GETTER_SETTER(const std::string&, Color, p_color)

protected:
  std::string p_name;
  std::string p_color;
};

class Apple : public Fruit {
public:
  inline Apple() : Fruit(Apple::defaultName(), Apple::defaultColor()) {}
  inline Apple(const std::string &color) : Fruit(Apple::defaultName(), color) {}
  virtual ~Apple() {}

  inline static std::string defaultName() { return std::string {"apple"}; }
  inline static std::string defaultColor() { return std::string {"red"}; }
};

class Banana : public Fruit {
public:
  inline Banana() : Fruit(Banana::defaultName(), Banana::defaultColor()) {}
  inline Banana(const std::string &color) : Fruit(Banana::defaultName(), color) {}
  virtual ~Banana() {}

  inline static std::string defaultName() { return std::string {"banana"}; }
  inline static std::string defaultColor() { return std::string {"yellow"}; }
};

class GrannySmith : public Apple {
public:
  inline GrannySmith() : Apple() {
    p_name = GrannySmith::defaultName();
    p_color = GrannySmith::defaultColor();
  }
  virtual ~GrannySmith() {}

  inline static std::string defaultName() {
    return std::string{"Granny Smith "} + Apple::defaultName();
  }
  inline static std::string defaultColor() { return std::string {"green"}; }
};

} // namespace task_2

