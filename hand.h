/*
 * Created by Qt Creator 4.11.0 @ 26 Mar 2021 21:34:05
 *
 * Project: GB_CppOOP
 * File: hand.h
 *
 * Author: Sergey Lola
 */
#pragma once

#include <vector>
#include <memory>

#include "common.h"

class Card;

// --------------------------------------------------------------------------------------
class Hand {
  using PtrCard = std::shared_ptr<Card>;
public:
  Hand();
  virtual ~Hand();

  void add(PtrCard p_card);
  void clear();
  int getValue() const;

protected:
  std::vector<PtrCard> m_cards;
};
