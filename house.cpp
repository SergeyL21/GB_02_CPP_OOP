/*
 * Created by Qt Creator 4.11.0 @ 30 Mar 2021 19:53:21
 *
 * Project: GB_CppOOP
 * File: house.cpp
 *
 * Author: Sergey Lola
 */
#include "house.h"
#include "card.h"

// --------------------------------------------------------------------------------------
bool House::isHitting() const {
  // брать всегда пока у дилера меньше или не равно 16
  return (getValue() <= 16);
}

// --------------------------------------------------------------------------------------
void House::flipFirstCard() {
  if (!m_cards.empty()) {
    (m_cards.front())->flip();
  }
}
