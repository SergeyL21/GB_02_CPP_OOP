/*
 * Created by Qt Creator 4.11.0 @ 04 Apr 2021 23:34:12
 *
 * Project: GB_CppOOP
 * File: game.h
 *
 * Author: Sergey Lola
 */
#pragma once

#include "deck.h"
#include "house.h"
#include "player.h"

class GenericPlayer;

// --------------------------------------------------------------------------------------
class Game {
public:
  Game(const std::vector<std::wstring> &names);
  ~Game();

  void play();

private:
  Deck m_deck;
  House m_house;
  std::vector<Player> m_players;
};


