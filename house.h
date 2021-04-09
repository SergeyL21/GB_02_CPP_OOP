/*
 * Created by Qt Creator 4.11.0 @ 30 Mar 2021 19:51:33
 *
 * Project: GB_CppOOP
 * File: house.h
 *
 * Author: Sergey Lola
 */
#pragma once

#include "generic_player.h"

// --------------------------------------------------------------------------------------
class House : public GenericPlayer {
public:
  inline House() : GenericPlayer(std::wstring{L"House"}) {}
  inline virtual ~House() override {}

  virtual bool isHitting() const override;

  void flipFirstCard();
};
