#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int is_negative = get_sign(src.bits[3]);  // Получаем знак числа
  set_minus_sign(&src.bits[3]);  // Устанавливаем минусовый знак
  int precision = get_scale(&src);  // Получаем точность числа

  // Преобразование числа из десятичного формата в формат с плавающей точкой
  double result = 0.0;

  // Проходим по всем битам числа и суммируем соответствующие степени двойки
  for (int i = 0; i < 96; ++i) {
    if (get_bit(src, i)) {
      result += pow(2., (double)i);
    }
  }

  // Уменьшаем точность числа, если необходимо
  while (precision > 0) {
    result = result / 10.;  // Деление на 10 для уменьшения разрядности числа
    precision--;
  }

  *dst = (float)result;  // Приведение результата к типу float
  if (is_negative)
    *dst = -*dst;  // Применяем знак к результату, если необходимо

  return 0;
}