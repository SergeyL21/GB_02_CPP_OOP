/*
 * Created by Qt Creator 4.11.0 @ 07 Mar 2021 16:24:09
 *
 * Project: GB_CppOOP
 * File: main.cpp
 *
 * Author: Sergey Lola
 */

#include <iostream>

#include <io.h>
#include <fcntl.h>

#include "task_7_1.h"
#include "task_7_2.h"

#include "game.h"

// ---------------------------------------------------------------------------
// вспомогательный макрос для удаления предупреждения об неиспользуемой
// переменной
#undef UNUSED
#define UNUSED(X) (void)(X);

// ---------------------------------------------------------------------------
// вспомогательный макрос для обозначения передачи аргумента по ссылке
#undef OUT
#define OUT

using namespace std;

// --------------------------------------------------------------------------------------
int main(int argc, const char ** argv) {
  UNUSED(argc)
  UNUSED(argv)

  _setmode(_fileno(stdout), _O_U8TEXT);

  // --------------------------------------------------------------------------------------
  // ЗАДАНИЕ 1: Создайте класс Date с полями день, месяц, год и методами доступа к этим
  // полям. Перегрузите оператор вывода для данного класса. Создайте два "умных" указателя
  // today и date. Первому присвойте значение сегодняшней даты. Для него вызовите по
  // отдельности методы доступа к полям класса Date, а также выведите на экран данные всего
  // объекта с помощью перегруженного оператора вывода. Затем переместите ресурс, которым
  // владеет указатель today в указатель date. Проверьте, являются ли нулевыми указатели
  // today и date и выведите соответствующую информацию об этом в консоль.
  {
    wcout << L"--- TASK 1 ---" << endl;
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    auto local_tm = *localtime(&now);
    auto today {make_unique<Date>(local_tm.tm_mday, local_tm.tm_mon + 1, local_tm.tm_year + 1900)};
    wcout << L"Today manual call: " << today->getDay() <<
            L"," << today->getMonth() << L"," << today->getYear() << endl;
    wcout << L"Today operator << : " << *today << endl;
    auto date = move(today);
    wcout << L"Today ptr is " << today.get() << endl;
    wcout << L"Date ptr is " << date.get() << endl;
  }
  // --------------------------------------------------------------------------------------
  // ЗАДАНИЕ 2: По условию предыдущей задачи создайте два умных указателя date1 и date2.
  // 1) Создайте функцию, которая принимает в качестве параметра два умных указателя типа
  // Date и сравнивает их между собой (сравнение происходит по датам). Функция должна
  // вернуть более позднюю дату.
  // 2) Создайте функцию, которая обменивает ресурсами (датами) два умных указателя,
  // переданных в функцию в качестве параметров.
  {
    wcout << endl << L"--- TASK 2 ---" << endl;
    auto date1 {make_unique<Date>(5, 3, 2021)};
    auto date2 {make_unique<Date>(6, 4, 2021)};
    const auto &date = compareDates(date1, date2);
    wcout << L"Date: " << *date << endl;
    swapDates(OUT date1, OUT date2);
    wcout << L"Date 1: " << *date1 << endl;
    wcout << L"Date 2: " << *date2 << endl;
  }

  // --------------------------------------------------------------------------------------
  // ЗАДАНИЕ 5: Написать функцию main() к игре Блекджек. В этой функции вводятся имена
  // игроков. Создается объект класса Game и запускается игровой процесс. Предусмотреть
  // возможность повторной игры.
  {
    wcout << endl << L"--- BLACKJACK GAME ---" << endl;
    bool is_playing{false};
    do {
      int players_count = 0;
      while (players_count < 2 || players_count > 7) {
        wcout << L"Enter the number of players (2 to 7): ";
        wcin >> players_count;
        wcin.clear();
      }

      vector<wstring> player_names;
      player_names.resize(players_count);
      for (int n = 0; n < players_count; ++n) {
        wcout << L"Enter the name of Player " << n + 1 << L": ";
        wcin >> player_names[n];
      }

      wcout << endl;
      Game game{player_names};
      game.play();

      wcout << endl << L"Game over. Try again? (Y/N): ";
      wchar_t input;
      wcin >> input;
      is_playing = (input == L'y' || input == L'Y');

    } while (is_playing);
  }
  return 0;
}
