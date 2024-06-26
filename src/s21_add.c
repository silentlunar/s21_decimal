#include "s21_decimal.h"

// Сложение децимелов
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  // Получение знаковых битов из значений value_1 и value_2
  int sign1 = get_sign(value_1.bits[3]);
  int sign2 = get_sign(value_2.bits[3]);

  // Проверка и выравнивание масштабов значений value_1 и value_2
  if (get_scale(&value_1) != get_scale(&value_2)) {
    equal_scale(&value_1, &value_2);
  }

  // Получение масштаба из значения value_1
  int scale = get_scale(&value_1);
  // Очистка результирующего значения
  clean_decimal(result);
  int sign = 0, flag = 0;
  int error = 0;

  // Выполнение операции сложения в зависимости от знаков значений value_1 и
  // value_2
  // Если оба числа отрицательные, то они складываются, а затем результату устанавливается отрицательный знак. 
  // Если оба числа положительные, то они складываются. Если одно число отрицательное, а другое положительное, 
  // то они складываются, а затем результату устанавливается знак числа с большим по модулю значением.
  // 
  if (sign1 == sign2) {
    if (sign1 && sign2) {
      error = sum(value_1, value_2, result);
      sign = 1;
      if (error) {
        clean_decimal(result);
        error = 2;
      }
    } else {
      error = sum(value_1, value_2, result);
      if (error) {
        clean_decimal(result);
        error = 1;
      }
    }
  } else if (sign1 && !sign2) {
    // проверка кокое число больше по модулю
    if (is_greater_by_abc(value_1, value_2)) {
      flag = 1;
    }
    value_1 = negtive(value_1);
    sum(value_1, value_2, result);
  } else {
    if (is_greater_by_abc(value_2, value_1)) {
      flag = 1;
    }
    value_2 = negtive(value_2);
    sum(value_1, value_2, result);
  }
  // Изменение знака результата, если необходимо
  if (flag) {
    *result = negtive(*result);
    sign = 1;
  }
  // Установка масштаба и знака для результата
  if (error == 0) {
    set_scale(result, scale);
    if (sign) {
      set_sign(&result->bits[3]);
    }
  }
  // Возврат ошибки или успешного завершения
  return error;
}