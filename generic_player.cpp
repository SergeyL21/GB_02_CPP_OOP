/*
 * Created by Qt Creator 4.11.0 @ 29 Mar 2021 14:37:23
 *
 * Project: GB_CppOOP
 * File: generic_player.cpp
 *
 * Author: Sergey Lola
 */
#include "generic_player.h"
#include "card.h"

#include <iomanip>

using namespace std;
// --------------------------------------------------------------------------------------
// лимит перебора
const int SCORE_LIMIT{21};

// --------------------------------------------------------------------------------------
bool GenericPlayer::isBusted() const {
  return (getValue() > SCORE_LIMIT);
}

// --------------------------------------------------------------------------------------
void GenericPlayer::bust() const {
  wcout << m_name << L" busts." << endl;
}

// --------------------------------------------------------------------------------------
wostream &operator<<(wostream &s, const GenericPlayer &p) {
  s << p.m_name << L": ";

  if (!p.m_cards.empty()) {
    for (auto it = p.m_cards.cbegin(); it != p.m_cards.cend(); ++it) {
      s << *((*it).get()) << L' ';
    }
    s << L"= [" << p.getValue() << L"]" << endl;
  }
  else {
    s << L"<EMPTY>" << endl;
  }
  return s;
}

