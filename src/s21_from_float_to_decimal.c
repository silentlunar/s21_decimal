#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int result = 0;
  int sign = 0;

  // Определение знака числа
  if (src < 0) {
    sign = 1;
    src = -src;
  }

  // Проверка на NaN или бесконечность
  if (dst == NULL || src == MY_NAN || src == MY_INFINITY ||
      src == -MY_INFINITY) {
    result = 1;
    clean_decimal(dst);
  } else if (src == 0.0) {  // Обработка случая, когда src равен нулю
    clean_decimal(dst);
  } else {
    clean_decimal(dst);
    int exp = s21_get_float_exp(&src);

    // Проверка диапазона экспоненты
    if (exp > 95 || exp < -94) {
      result = 1;
    } else {
      int scale = 0;
      int scale_2 = 0;
      double src_2 = src;

      // Определение масштаба числа
      for (; !(int)src_2; src_2 *= 10, ++scale) {
      }
      for (; src_2 > 10; src_2 /= 10, scale--) {
      }
      for (int i = 0; i < 6; ++i, ++scale_2) {
        src_2 = src_2 * 10.0;
      }
      src = src_2;

      // Проверка на допустимость масштаба
      if (scale > 28) {
        result = 1;
      } else {
        long int mask = 1;

        // Удаление лишних нулей в конце числа
        while ((unsigned int)src % 10 == 0) {
          src /= 10;
          scale_2--;
        }

        long int src_tmp = src;

        // Установка битов мантиссы в dst
        for (int i = 0; i < 96; ++i, mask <<= 1) {
          if (!!(mask & src_tmp)) set_bit(dst, i);
        }

        // При необходимости корректировка масштаба
        if (scale + scale_2 < 0) {
          int temp = 0;
          s21_from_decimal_to_int(*dst, &temp);
          for (; scale + scale_2 < 0; scale++) {
            temp *= 10;
          }
          s21_from_int_to_decimal(temp, dst);
        }

        // Установка масштаба в dst
        set_scale(dst, scale + scale_2);

        // Установка знака в dst
        if (sign) set_sign(&dst->bits[3]);
      }
    }
  }

  // Установка знака в dst (если необходимо)
  if (sign) set_sign(&dst->bits[3]);

  return result;
}
