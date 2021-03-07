/*
 * Created by Qt Creator 4.11.0 @ 07 Mar 2021 17:03:21
 *
 * Project: GB_CppOOP
 * File: rgba.h
 *
 * Author: Sergey Lola
 */
#pragma once

#include <string>

// --------------------------------------------------------------------------------------
class RGBA {
 public:
  RGBA() = default;
  inline RGBA(std::uint8_t red, std::uint8_t green, std::uint8_t blue,
              std::uint8_t alpha = 255)
      : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {}
  ~RGBA() = default;

  std::string print() const;

 private:
  std::uint8_t m_red{0};
  std::uint8_t m_green{0};
  std::uint8_t m_blue{0};
  std::uint8_t m_alpha{255};
};
