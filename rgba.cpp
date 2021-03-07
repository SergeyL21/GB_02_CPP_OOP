/*
 * Created by Qt Creator 4.11.0 @ 07 Mar 2021 17:04:56
 *
 * Project: GB_CppOOP
 * File: rgba.cpp
 *
 * Author: Sergey Lola
 */

#include "rgba.h"

#include <sstream>

using namespace std;

// --------------------------------------------------------------------------------------
string RGBA::print() const {
  ostringstream ss;
  ss << "R=" << std::size_t(m_red) << ", G=" << std::size_t(m_green)
    << ", B=" << std::size_t(m_blue) << ", A=" << std::size_t(m_alpha);
  return ss.str();
}
