/*
 * Created by Qt Creator 4.11.0 @ 29 Mar 2021 14:32:15
 *
 * Project: GB_CppOOP
 * File: generic_player.h
 *
 * Author: Sergey Lola
 */
#pragma once

#include "hand.h"

// --------------------------------------------------------------------------------------
class GenericPlayer : public Hand {
public:
  inline GenericPlayer(const std::string &name) :
    Hand(), m_name(name) {}
  inline virtual ~GenericPlayer() override {}

  friend std::wostream &operator<<(std::wostream &s, const GenericPlayer &p);

  virtual bool isHitting() const = 0;

  bool isBusted() const;
  void bust() const;

protected:
  std::string m_name;
};
