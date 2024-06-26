#include "s21_decimal.h"

// Равно
int s21_is_equal(s21_decimal dec_1, s21_decimal dec_2) {
  int exp_1 = 0, exp_2 = 0, res = 1;
  equal_scale(&dec_1, &dec_2);
  if (is_zero(dec_1) && is_zero(dec_2)) {
    res = 1;
  } else {
    exp_1 = get_sign(dec_1.bits[3]);
    exp_2 = get_sign(dec_2.bits[3]);
    if ((exp_1 ^ exp_2) == 0) {
      for (int i = 0; i < 3; i++) {
        if (dec_1.bits[i] != dec_2.bits[i]) res = 0;
      }
    } else
      res = 0;
  }

  return res;
}