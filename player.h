/*
 * Created by Qt Creator 4.11.0 @ 30 Mar 2021 19:45:42
 *
 * Project: GB_CppOOP
 * File: player.h
 *
 * Author: Sergey Lola
 */
#pragma once

#include "generic_player.h"

// --------------------------------------------------------------------------------------
class Player : public GenericPlayer {
public:
  inline Player(const std::wstring& name) : GenericPlayer(name) {}
  inline virtual ~Player() override {}

  virtual bool isHitting() const override;

  void win() const;
  void lose() const;
  void push() const;
};

