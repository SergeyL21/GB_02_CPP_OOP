/*
 * Created by Qt Creator 4.11.0 @ 29 Mar 2021 14:37:23
 *
 * Project: GB_CppOOP
 * File: generic_player.cpp
 *
 * Author: Sergey Lola
 */
#include "generic_player.h"

#include <iostream>

// --------------------------------------------------------------------------------------
// лимит перебора
const int SCORE_LIMIT{21};

// --------------------------------------------------------------------------------------
bool GenericPlayer::isBusted() const {
  return (getValue() > SCORE_LIMIT);
}

// --------------------------------------------------------------------------------------
void GenericPlayer::bust() const {
  using namespace std;
  cout << m_name << " busts." << endl;
}


