/*
 * Created by Qt Creator 4.11.0 @ 30 Mar 2021 19:48:09
 *
 * Project: GB_CppOOP
 * File: player.cpp
 *
 * Author: Sergey Lola
 */
#include "player.h"

using namespace std;

// --------------------------------------------------------------------------------------
bool Player::isHitting() const {
  wcout << m_name << L", do you want a hit? (Y/N): ";
  wchar_t input;
  wcin >> input;
  return (input == L'y' || input == L'Y');
}

// --------------------------------------------------------------------------------------
void Player::win() const {
  wcout << m_name << L" wins.";
}

// --------------------------------------------------------------------------------------
void Player::lose() const {
  wcout << m_name << L" loses.";
}

// --------------------------------------------------------------------------------------
void Player::push() const {
  wcout << m_name << L" pushes.";
}
