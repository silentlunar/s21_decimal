#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int err = 0, sign_1 = 0, sign_2 = 0, scale = 0;
  clean_decimal(result);

  sign_1 = get_sign(value_1.bits[3]);
  sign_2 = get_sign(value_2.bits[3]);
  if ((is_zero(value_1) && !sign_1) || (is_zero(value_2) && !sign_2)) {
    if (sign_1 != sign_2) {
      set_sign(&result->bits[3]);
    }
  } else {
    // Если оба числа не равны нулю, то вычисляется масштаб результата.

    scale = get_scale(&value_1) + get_scale(&value_2);
    s21_big_decimal v1, v2, res;
    v1 = big_decimal_init(value_1);
    v2 = big_decimal_init(value_2);
    res = big_decimal_init(*result);
    s21_mul_helper(v1, v2, &res, &scale);
    // Проверка на то, что результат умножения укладывается в допустимые пределы формата S21 Decimal.
    if ((res.bits[3] == 0 && res.bits[4] == 0 && res.bits[5] == 0) &&
        (scale >= 0 && scale <= 28)) {
      big_to_decimal(result, &res);
      set_scale(result, scale);
      if (sign_1 && !sign_2) {
        set_sign(&result->bits[3]);
      } else if (!sign_1 && sign_2) {
        set_sign(&result->bits[3]);
      }
    } else {
      // Если результат не укладывается в допустимые пределы
      if (sign_1 && !sign_2) {
        err = 2;
      } else if (!sign_1 && sign_2) {
        err = 2;
      } else {
        err = 1;
      }
      clean_decimal(result);
    }
  }
  return err;
}