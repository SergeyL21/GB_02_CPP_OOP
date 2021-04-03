/*
 * Created by Qt Creator 4.11.0 @ 02 Apr 2021 19:21:04
 *
 * Project: GB_CppOOP
 * File: card.cpp
 *
 * Author: Sergey Lola
 */
#include "card.h"

// --------------------------------------------------------------------------------------
std::wostream &operator<<(std::wostream &s, const Card &card) {
  static const std::map<CardSuit, std::wstring> SUIT_MAP {
    {CardSuit::Undefined, std::wstring{L"0"}},
    {CardSuit::Clubs, std::wstring{L"♣"}},
    {CardSuit::Spades, std::wstring{L"♠"}},
    {CardSuit::Hearts, std::wstring{L"♥"}},
    {CardSuit::Diamonds, std::wstring{L"♦"}}
  };

  static const std::map<CardValue, std::wstring> VALUE_MAP {
    {CardValue::Undefined, std::wstring{L"0"}},
    {CardValue::Ace, std::wstring{L"A"}},
    {CardValue::Num_2, std::wstring{L"2"}},
    {CardValue::Num_3, std::wstring{L"3"}},
    {CardValue::Num_4, std::wstring{L"4"}},
    {CardValue::Num_5, std::wstring{L"5"}},
    {CardValue::Num_6, std::wstring{L"6"}},
    {CardValue::Num_7, std::wstring{L"7"}},
    {CardValue::Num_8, std::wstring{L"8"}},
    {CardValue::Num_9, std::wstring{L"9"}},
    {CardValue::Num_10, std::wstring{L"10"}},
    {CardValue::Jack, std::wstring{L"J"}},
    {CardValue::Queen, std::wstring{L"Q"}},
    {CardValue::King, std::wstring{L"K"}}
   };

  if (card.m_isFaceUp) {
    s << SUIT_MAP.at(card.m_suit) << VALUE_MAP.at(card.m_value);
  }
  else {
    s << std::wstring{L"XX"};
  }

  return s;
}
