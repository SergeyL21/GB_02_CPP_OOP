/*
 * Created by Qt Creator 4.11.0 @ 22 Mar 2021 18:09:56
 *
 * Project: GB_CppOOP
 * File: card.h
 *
 * Author: Sergey Lola
 */
#pragma once

#include "common.h"

#include <map>

// --------------------------------------------------------------------------------------
// перечисление для мастей карты
enum class CardSuit {
  Undefined,  // значение по умолчанию
  Clubs,      // трефы
  Spades,     // пики
  Hearts,     // червы
  Diamonds,   // бубны
};

// --------------------------------------------------------------------------------------
// перечисление для значения карты
enum class CardValue {
  Undefined = 0,  // значение по умолчанию
  Ace = 1,        // карта с тузом
  Num_2,          // карта с двойкой (для большой колоды)
  Num_3,          // карта с тройкой (для большой колоды)
  Num_4,          // карта с четверкой (для большой колоды)
  Num_5,          // карта с пятеркой (для большой колоды)
  Num_6,          // карта с шестеркой (для стандартной колоды)
  Num_7,          // карта с семеркой (для стандартной колоды)
  Num_8,          // карта с восьмеркой (для стандартной колоды)
  Num_9,          // карта с девяткой (для стандартной колоды)
  Num_10,         // карта с десяткой (для стандартной колоды)
  Jack,           // карта с вальтом
  Queen,          // карта с дамой
  King,           // карта с королем
};

// --------------------------------------------------------------------------------------
class Card {
public:
  Card(CardSuit suit, CardValue value, bool isFaceUp = false) :
    m_suit(suit), m_value(value), m_isFaceUp(isFaceUp) {}
  ~Card() = default;

  friend std::wostream &operator<<(std::wostream &s, const Card &card);

  // возращаем кол-во очков, которые можно получить за карту
  inline int getValue() const {
    // валет, дама и король дают по 10 очков
    return static_cast<int>(m_value) > 10 ? 10 : static_cast<int>(m_value);
  }

  // проверка, повернута ли карта "лицом"
  inline bool isFaceUp() const { return m_isFaceUp; }

  // переворачиваем карту
  inline void flip() { m_isFaceUp ^= true; }

private:
  CardSuit m_suit {CardSuit::Undefined};
  CardValue m_value {CardValue::Undefined};
  bool m_isFaceUp {false};
};
