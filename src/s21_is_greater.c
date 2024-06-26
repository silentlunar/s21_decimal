#include "s21_decimal.h"

// Больше
int s21_is_greater(s21_decimal val_1, s21_decimal val_2) {
  int is_bigger = 0;
  equal_scale(&val_1, &val_2);
  if (get_sign(val_1.bits[3]) == get_sign(val_2.bits[3])) {
    int i = 95;
    while ((i >= 0) && (get_bit(val_1, i) == get_bit(val_2, i))) i--;
    if ((get_bit(val_1, i)) > (get_bit(val_2, i))) is_bigger = 1;
    if (get_sign(val_1.bits[3]) && s21_is_not_equal(val_1, val_2))
      is_bigger = (is_bigger == 0);
  } else if (get_sign(val_1.bits[3]) < get_sign(val_2.bits[3]))
    is_bigger = 1;
  return is_bigger;
}