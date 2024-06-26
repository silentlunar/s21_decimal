#include "s21_decimal.h"

// Вычитание децималов
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int sign = !get_sign(value_2.bits[3]);
  switch_sign(&value_2, sign);
  s21_add(value_1, value_2, result);

  return 0;
}