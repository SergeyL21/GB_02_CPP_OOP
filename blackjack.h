/*
 * Created by Qt Creator 4.11.0 @ 18 Mar 2021 16:56:37
 *
 * Project: GB_CppOOP
 * File: blackjack.h
 *
 * Author: Sergey Lola
 *
 * Note: Прототип классов игры "BlackJack" для задания 3 в ДЗ
 */
#pragma once

#include <vector>
#include <memory>

// класс описывающий абстрактную карту
class AbstractCard {
public:
  enum Type {
    Type_Numeric,    // карты с числовым значением
    Type_Picture,    // карты с "картинкой" (валет, дама, король)
    Type_Trumph      // туз
  };

  enum Sign {
    Sign_Clubs,      // трефы
    Sign_Spades,     // пики
    Sign_Hearts,     // червы
    Sign_Diamonds,   // бубны
  };

  AbstractCard(Type type, Sign sign);
  virtual ~AbstractCard();

  virtual int getScore() const = 0;

  Type getType() const;
  Sign getSign() const;
  bool isFlip() const;
  void setFlip(bool flag);

protected:
  // очки, которые приносит карта
  int p_score;

private:
  // тип карты
  Type type;
  // масть карты
  Sign m_sing;
  // карта перевернута или нет
  bool m_isFlip;
};

// класс описывающий карту с числовым значением
class NumericCard : public AbstractCard {
public:
  NumericCard(Sign sign, int score);
  virtual ~NumericCard() override;

  virtual int getScore() const override;
};

// класс описывающий карту с "картинкой"
class PictureCard : public AbstractCard {
public:
  enum Picture {
    Picture_Jack,   // валет
    Picture_Queen,  // дама
    Picture_King    // король
  };

  PictureCard(Sign sign, Picture picture);
  virtual ~PictureCard() override;

  virtual int getScore() const override;
  Picture getPicture() const;

private:
  // тип карты "картинки"
  Picture m_picture;
};

// класс описывающий карту "туз"
class TrumpCard : public AbstractCard {
public:
  TrumpCard(Sign sign);
  virtual ~TrumpCard() override;

  virtual int getScore() const override;

  bool isMaxScore() const;
  void setMaxScore(bool flag);

private:
  // взять 11 очков
  bool m_isMaxScore;
};

using CardCollection = std::vector<std::unique_ptr<AbstractCard>>;

// класс, описывающий колоду карт
class Deck {
public:
  Deck();
  ~Deck();

  // извлечь карту из колоды на раздачу
  AbstractCard dequeue();
  // перетасовать колоду из оставшихся карт
  void shuffle();
  // вернуть все карты в колоду
  void reset();

private:
  CardCollection m_cards;
};

// класс, описывающий общего игрока и его действия
class Player {
public:
  enum Type {
    Human,    // человек
    AI        // компьютер
  };

  Player(Type type);
  virtual ~Player();

  // получить тип игрока
  Type getType() const;
  // получить уникальный идентификатор игрока
  int getId() const;

  // взять карту из колоды
  virtual void drawCard(const Deck &deck);
  // TODO: дополнить функционал игрока

  // получить число карт в коллекции
  int count() const;
  // получить общее число очков ото всех карт в коллекции
  int getTotalScore() const;

  // получить доступ к классу карт игрока
  const CardCollection &hand() const;
  CardCollection &hand();

protected:
  // колода карт игрока
  CardCollection m_hand;

private:
  const Type m_type;
  int m_id;
};

// класс, описывающий дилера (технически можно задать,
// что дилером может быть как человек, так и компьютер)
class Dealer : public Player {
public:
  Dealer(Type type);
  virtual ~Dealer();

  // TODO: дополнить функционал дилера
};
