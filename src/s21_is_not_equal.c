#include "s21_decimal.h"

// Не равно
int s21_is_not_equal(s21_decimal dec_1, s21_decimal dec_2) {
  return !s21_is_equal(dec_1, dec_2);
}