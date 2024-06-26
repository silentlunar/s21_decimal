#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  // Извлекаем знак из бита 31 в bits[3]
  int sign = (src.bits[3] >> 31) & 0x1;

  // Извлекаем показатель степени из битов с 16 по 23 в bits[3]
  int exponent = (src.bits[3] >> 16) & 0xFF;

  // Проверяем, что показатель степени находится в допустимом диапазоне
  if (exponent < 0 || exponent > 28) {
    return 1;  // Ошибка конвертации
  }

  // Извлекаем целое число из bits[0], bits[1] и bits[2]
  long long int integer_part = src.bits[0] |
                               ((long long int)src.bits[1] << 32) |
                               ((long long int)src.bits[2] << 32);

  // Убираем дробную часть путем деления на 10 в степени показателя
  for (int i = 0; i < exponent; i++) {
    integer_part /= 10;
  }

  // Устанавливаем знак в зависимости от значения бита 31 в bits[3]
  if (sign) {
    integer_part *= -1;
  }

  *dst = (int)integer_part;

  return 0;  // OK
}