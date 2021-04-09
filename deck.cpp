/*
 * Created by Qt Creator 4.11.0 @ 04 Apr 2021 23:04:39
 *
 * Project: GB_CppOOP
 * File: deck.cpp
 *
 * Author: Sergey Lola
 */
#include "deck.h"
#include "card.h"
#include "generic_player.h"

#include <algorithm>

// --------------------------------------------------------------------------------------
// число карт в колоде
const int CARDS_SIZE {52};

// --------------------------------------------------------------------------------------
Deck::Deck() {
  m_cards.reserve(CARDS_SIZE);
  populate();
}

// --------------------------------------------------------------------------------------
Deck::~Deck() {}

// --------------------------------------------------------------------------------------
void Deck::populate() {
  clear();
  for (auto s : ExtEnum<CardSuit, CardSuit::Clubs, CardSuit::Diamonds>{}) {
    for (auto v : ExtEnum<CardValue, CardValue::Ace, CardValue::King>{}) {
      add(std::make_shared<Card>(s, v));
    }
  }
}

// --------------------------------------------------------------------------------------
void Deck::shuffle() {
  std::random_shuffle(m_cards.begin(), m_cards.end());
}

// --------------------------------------------------------------------------------------
void Deck::deal(Hand &hand)
{
  if (!m_cards.empty()) {
    hand.add(m_cards.back());
    m_cards.pop_back();
  }
  else {
    std::wcout << L"Out of cards!";
  }
}

// --------------------------------------------------------------------------------------
void Deck::additionalCards(GenericPlayer &genericPlayer) {
  while (!(genericPlayer.isBusted()) && genericPlayer.isHitting()) {
    deal(genericPlayer);
    std::wcout << genericPlayer;
    if (genericPlayer.isBusted()) {
      genericPlayer.bust();
    }
  }
}
