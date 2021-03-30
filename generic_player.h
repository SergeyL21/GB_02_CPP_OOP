/*
 * Created by Qt Creator 4.11.0 @ 29 Mar 2021 14:32:15
 *
 * Project: GB_CppOOP
 * File: generic_player.h
 *
 * Author: Sergey Lola
 */
#pragma once

#include "hand.h"

// --------------------------------------------------------------------------------------
// ЗАДАНИЕ 4: Согласно иерархии классов, которая представлена в методичке к уроку 3, от
// класса Hand наследует класс GenericPlayer, который обобщенно представляет игрока,
// ведь у нас будет два типа игроков - человек и компьютер. Создать класс GenericPlayer,
// в который добавить поле name - имя игрока. Также добавить 3 метода:
// IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще
// одна карта;
// IsBoosted() - возвращает bool значение, есть ли у игрока перебор;
// Bust() - выводит на экран имя игрока и объявляет, что у него перебор.

class GenericPlayer : public Hand {
public:
  inline GenericPlayer(const std::string &name = std::string{}) :
    Hand(), m_name(name) {}
  inline virtual ~GenericPlayer() override {}

  virtual bool isHitting() const = 0;

  bool isBusted() const;
  void bust() const;

protected:
  std::string m_name;
};
