#include "s21_decimal.h"

/* Возвращает целые цифры указанного Decimal числа;
 * любые дробные цифры отбрасываются, включая конечные нули.
 */
int s21_truncate(s21_decimal value, s21_decimal *result) {
  int res_scale = get_scale(&value);

  while (res_scale > 0) {
    lower_scale(&value);
    res_scale = get_scale(&value);
  }
  copy_decimal(result, &value);

  return 0;
}