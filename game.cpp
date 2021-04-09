/*
 * Created by Qt Creator 4.11.0 @ 04 Apr 2021 23:45:58
 *
 * Project: GB_CppOOP
 * File: game.cpp
 *
 * Author: Sergey Lola
 */
#include "game.h"

#include <chrono>

using namespace std;

// --------------------------------------------------------------------------------------
Game::Game(const vector<wstring> &names) {
  for (auto it = names.cbegin(); it != names.cend(); ++it) {
    m_players.push_back(Player{*it});
  }

  // запускаем генератор случайных чисел для метода shuffle
  srand(static_cast<unsigned int>(time(nullptr)));
  m_deck.populate();
  m_deck.shuffle();
}

// --------------------------------------------------------------------------------------
Game::~Game() {}

// --------------------------------------------------------------------------------------
void Game::play() {
  // раздаем каждому игроку по две стартовые карты
  for (int i = 0; i < 2; ++i) {
    for (auto it = m_players.begin(); it != m_players.end(); ++it) {
      m_deck.deal(*it);
    }
    m_deck.deal(m_house);
  }

  // прячем первую карту дилера
  m_house.flipFirstCard();

  // открываем набор карт всех игроков и раздаем дополнительные карты
  for (auto it = m_players.begin(); it != m_players.end(); ++it) {
    wcout << *it;
  }
  wcout << m_house;

  // раздаем дополнительные карты игрокам
  for (auto it = m_players.begin(); it != m_players.end(); ++it) {
    m_deck.additionalCards(*it);
  }

  // показываем первую карту дилера
  m_house.flipFirstCard();
  wcout << endl << m_house;
  // раздаем дилеру дополнительные карты
  m_deck.additionalCards(m_house);

  // если у дилера перебор, то все оставшиеся игроки побеждают
  if (m_house.isBusted()) {
    for (auto it = m_players.cbegin(); it != m_players.cend(); ++it) {
      if (!((*it).isBusted())) {
        (*it).win();
      }
    }
  }
  // в противном случае сравнимаем очки всех оставшихся игроков с суммой очков дилера
  else {
    for (auto it = m_players.cbegin(); it != m_players.cend(); ++it) {
      const auto &player = *it;
      if (!(player.isBusted())) {
        const auto playerValue = player.getValue();
        const auto houseValue = m_house.getValue();
        if (playerValue > houseValue) {
          player.win();
        }
        else if (playerValue < houseValue) {
          player.lose();
        }
        else {
          player.push();
        }
        wcout << endl;
      }
    }
  }

  // сбрасываем все карты со всех игроков
  for (auto it = m_players.begin(); it != m_players.end(); ++it) {
    (*it).clear();
  }
  m_house.clear();
}

