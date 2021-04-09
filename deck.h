/*
 * Created by Qt Creator 4.11.0 @ 04 Apr 2021 23:01:45
 *
 * Project: GB_CppOOP
 * File: deck.h
 *
 * Author: Sergey Lola
 */
#pragma once

#include "hand.h"

class GenericPlayer;

// --------------------------------------------------------------------------------------
class Deck : public Hand {
public:
  Deck();
  virtual ~Deck();

  void populate();
  void shuffle();
  void deal(Hand &hand);
  void additionalCards(GenericPlayer &genericPlayer);
};

