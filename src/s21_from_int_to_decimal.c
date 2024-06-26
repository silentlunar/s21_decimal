#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  if (src < INT_MIN || src > INT_MAX) {
    return 1;  // Ошибка конвертации - значение вне допустимого диапазона
  }

  // Шаг 2: Преобразование в двоичное представление
  int sign = (src < 0) ? 1 : 0;  // Определение знака числа
  unsigned int value = (sign) ? -src : src;  // Абсолютное значение числа

  // Используем unsigned long long для избежания переполнения при сдвиге
  unsigned long long value_64 = value;

  dst->bits[0] = value_64 & 0xFFFFFFFF;  // Младшие 32 бита числа
  dst->bits[1] = (value_64 >> 32) & 0xFFFFFFFF;  // Средние 32 бита числа
  dst->bits[2] = 0;  // Для 96-разрядного целого числа
  dst->bits[3] = (sign << 31);  // Знак, размещенный в старшем бите

  return 0;  // Успешное завершение
}