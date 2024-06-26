#include "s21_decimal.h"

// Возвращает результат умножения указанного Decimal на -1.
int s21_negate(s21_decimal dec, s21_decimal *result) {
  clean_decimal(result);
  int sign = get_sign(dec.bits[3]);
  *result = dec;
  if (sign == 1) {
    set_minus_sign(&result->bits[3]);
  } else {
    set_sign(&result->bits[3]);
  }
  return 0;
}