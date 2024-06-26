#include "s21_decimal.h"

/*
 * Округляет указанное Decimal число до ближайшего
 * целого числа в сторону отрицательной бесконечности.
 */
int s21_floor(s21_decimal value, s21_decimal *result) {
  int scale = get_scale(&value);
  int sign = get_sign(value.bits[3]);

  if (scale > 0 && !is_zero(value)) {
    s21_truncate(value, result);
    if (sign) {
      s21_decimal one;
      clean_decimal(&one);
      one.bits[0] = 1;
      one.bits[3] = 0x80000000;
      s21_add(*result, one, result);
    }
  } else {
    set_scale(&value, 0);
    copy_decimal(result, &value);
    if (sign) {
      set_sign(&result->bits[3]);
    }
  }

  return 0;
}
