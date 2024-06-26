#include "s21_decimal.h"
// divident (делимое), divisor (делитель)
int s21_div(s21_decimal divident, s21_decimal divisor, s21_decimal *result) {
  int error = NORMAL_VALUE;
  // Выравнивание разрядности делимого и делителя с помощью функции equal_scale.
  equal_scale(&divident, &divisor);
  // Создание переменной dec_null и очистка ее значений.
  s21_decimal dec_null;
  clean_decimal(&dec_null);
  int scale_result = 0;
  int sign = 0;
  // Проверка знаков делимого и делителя. Если оба числа отрицательные, то знак результата будет положительным, 
  // а затем оба числа будут приведены к положительному виду. Если только одно из чисел отрицательное, 
  // то знак результата будет отрицательным, а затем оба числа будут приведены к положительному виду.
  // 
  // 
  if (get_sign(divident.bits[3]) && get_sign(divisor.bits[3])) {
    sign = 0;
    set_minus_sign(&divident.bits[3]);
    set_minus_sign(&divisor.bits[3]);
  } else if (get_sign(divident.bits[3]) || get_sign(divisor.bits[3])) {
    sign = 1;
    set_minus_sign(&divident.bits[3]);
    set_minus_sign(&divisor.bits[3]);
  }
  // Проверка на случай деления на ноль. Если делитель равен нулю, то результатом будет NaN (не число), а указатель на result будет очищен.
  if (s21_is_equal(divisor, dec_null)) {
    error = MY_NAN;
    clean_decimal(result);
    // Проверка на случай деления нуля на что-то. Если делимое равно нулю, то результатом будет ноль, а указатель на result будет очищен.
  } else if (s21_is_equal(divident, dec_null)) {
    clean_decimal(result);
    // Проверка на случай, когда делимое и делитель равны. В этом случае результатом будет единица, а указатель на result будет очищен.
  } else if (s21_is_equal(divident, divisor)) {
    clean_decimal(result);
    result->bits[0] = 1;
    set_scale(result, scale_result);
    if (sign) set_sign(&result->bits[3]);
    // Если ни одно из вышеперечисленных условий не выполняется, то происходит деление с помощью цикла while. 
    // В цикле происходит проверка на то, что делимое больше или равно делителю. 
    // Если это так, то происходит вычитание делителя из делимого, а затем результату прибавляется единица. 
    // Если делимое меньше делителя, то происходит увеличение разрядности делимого на единицу.
  } else {
    clean_decimal(result);
    s21_decimal mask;
    clean_decimal(&mask);
    mask.bits[0] = 1;
    s21_decimal ten;
    clean_decimal(&ten);
    ten.bits[0] = 10;
    s21_decimal temp;
    copy_decimal(&temp, &divisor);
    s21_decimal temp_divisor;
    clean_decimal(&temp_divisor);
// divident (делимое), divisor (делитель)

    while (s21_is_not_equal(divident, dec_null) && scale_result < 28) {
      // Проверка на то, что делимое меньше делителя (if (s21_is_less(divident, divisor))). 
      // Если это условие выполняется, то увеличивается scale_result на единицу. Это означает, что десятки в делимое должны быть умножены на 10.
      if (s21_is_less(divident, divisor)) {
        scale_result++;
        s21_mul(divident, ten, &divident);
      }
      copy_decimal(&temp_divisor, &divisor);
      // Сдвиг битов в левую сторону для делителя (shift_left(&temp_divisor)). Это создает новую "единицу" для сравнения с делимовым числом.
      shift_left(&temp_divisor);
      if (s21_is_greater_or_equal(divident, temp_divisor) &&
          s21_is_greater(temp_divisor, dec_null)) {
            // Если эти условия выполнены, то делитель должен быть увеличен на единицу и сдвинут в левую сторону
        shift_left(&divisor);
        shift_left(&mask);
      } else {
        // Если условия 6 не выполнены, то выполняется операция вычитания делителя из делимого (s21_sub(divident, divisor, &divident)). 
        // Затем делитель копируется в временную переменную temp, а флаг маски сбрасывается (clean_decimal(&mask)). 
        // Маска обновляется, чтобы содержать единицу в первом бите (mask.bits = 1).
        sum(*result, mask, result);
        s21_sub(divident, divisor, &divident);
        copy_decimal(&divisor, &temp);
        clean_decimal(&mask);
        mask.bits[0] = 1;
      }
    }
    set_scale(result, scale_result);
    if (sign) set_sign(&result->bits[3]);
  }
  return error;
}
// Сравнение scale_result с константой 28. Конкретно здесь используется максимально допустимое количество разрядов 
// для представления чисел в формате S21 Decimal. Если scale_result превышает 28, то это означает, что результат 
// деления превышает возможность представить его в данном формате. Такое состояние считается ошибкой.

// Таким образом, mask используется для отслеживания позиции в результате деления и обеспечивает правильное размещение цифр в результирующем числе.