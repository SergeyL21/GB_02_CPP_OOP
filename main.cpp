/*
 * Created by Qt Creator 4.11.0 @ 07 Mar 2021 16:24:09
 *
 * Project: GB_CppOOP
 * File: main.cpp
 *
 * Author: Sergey Lola
 */

#include <iostream>

#include "task_5_1.h"
#include "task_5_2.h"
#include "task_5_3.h"

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

#include "task_5_1.impl"
#include "task_5_2.impl"
#include "task_5_3.impl"

  return 0;
}
