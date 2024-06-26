#include "s21_decimal.h"

// Округляет s21_decimal до ближайшего целого числа.
int s21_round(s21_decimal value, s21_decimal *result) {
  int scale = 0, sign = 0;
  scale = get_scale(&value);
  sign = get_sign(value.bits[3]);
  if (scale > 0) {
    while (scale > 1) {
      lower_scale(&value);
      scale = get_scale(&value);
    }
    s21_decimal five;
    clean_decimal(&five);
    five.bits[0] = 5;
    sum(value, five, &value);
    set_scale(&value, scale);
    lower_scale(&value);
  }
  copy_decimal(result, &value);

  if (sign) {
    set_sign(&result->bits[3]);
  }

  return 0;
}