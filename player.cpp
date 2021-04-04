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
  cout << m_name << ", do you want a hit? (Y/N): ";
  char input;
  cin >> input;
  return (input == 'y' || input == 'Y');
}

// --------------------------------------------------------------------------------------
void Player::win() const {
  cout << m_name << " wins." << endl;
}

// --------------------------------------------------------------------------------------
void Player::lose() const {
  cout << m_name << " loses." << endl;
}

// --------------------------------------------------------------------------------------
void Player::push() const {
  cout << m_name << " pushes." << endl;
}
