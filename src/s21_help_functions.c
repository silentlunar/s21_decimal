#include "s21_decimal.h"

int get_sign(int val) { return (val & 0x80000000) ? 1 : 0; }

void set_sign(unsigned int *val) { *val |= 0x80000000; }

void set_minus_sign(unsigned int *val) { *val &= 0x7FFFFFFF; }

int get_scale(s21_decimal *dec) {
  int mask = 0;
  mask = dec->bits[3] & 0xFF0000;
  return mask >>= 16;
}

void set_scale(s21_decimal *dec, int scale) {
  scale <<= 16;
  dec->bits[3] = scale;
}

int set_bit(s21_decimal *dec, int index) {
  int err = 0;
  if (index >= 0 && index < 96) {
    int mask = 1 << index;
    dec->bits[index / 32] |= mask;
  } else {
    err = 1;
  }
  return err;
}

int get_bit(s21_decimal dec, int index) {
  int res = -1;
  if (index >= 0 && index < 128) {
    int mask = 1 << index;
    res = !!(dec.bits[index / 32] & mask);
  }
  return res;
}

int is_zero(s21_decimal val) {
  int flag = 1;
  for (int i = 0; i < 3; i++) {
    if (val.bits[i] != 0) {
      flag = 0;
      break;
    }
  }
  if (flag == 1) {
    val.bits[3] = (val.bits[3] & 0b01111111111111111111111111111111);
  }
  return flag;
}

void copy_decimal(s21_decimal *dest, s21_decimal *src) {
  dest->bits[0] = src->bits[0];
  dest->bits[1] = src->bits[1];
  dest->bits[2] = src->bits[2];
  dest->bits[3] = src->bits[3];
}

void clean_decimal(s21_decimal *dec) {
  for (int i = 0; i < 4; i++) {
    dec->bits[i] = 0;
  }
}

// принимает два числа типа децимал и возвращает их сумму в третьем аргументе
// без степени
int sum(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  clean_decimal(result);
  int a, b, res;
  int temp = 0, err = 0;
  for (int i = 0; i < 96; i++) {
    a = get_bit(value_1, i);
    b = get_bit(value_2, i);
    res = a + b + temp;
    if (i == 95 && res > 1) {
      err = MY_INFINITY;
      // break;
    }
    if (res == 0) {
      temp = 0;
    } else if (res == 1) {
      temp = 0;
      set_bit(result, i);
    } else if (res == 2) {
      temp = 1;
    } else if (res == 3) {
      temp = 1;
      set_bit(result, i);
    }
  }
  return err;
}
// Цикл while выполняется, пока все биты числа v2 не станут равными нулю.
// Внутри цикла происходит проверка младшего бита числа v2.
// Если младший бит равен 1, то к результирующему числу result прибавляется число v1.
// Затем происходит сдвиг битов числа v2 вправо и сдвиг битов числа v1 влево.
void s21_mul_helper(s21_big_decimal v1, s21_big_decimal v2,
                    s21_big_decimal *result, int *scale) {
  while (v2.bits[0] || v2.bits[1] || v2.bits[2] || v2.bits[3] || v2.bits[4] ||
         v2.bits[5]) {
    if (v2.bits[0] & 1) {
      *result = sum_big_decimal(v1, *result);
    }
    shift_righ_big(&v2);
    shift_left_big(&v1);
  }
  // коррекция результата
// Инициализируется переменная five и очищается её значение.
// Цикл while выполняется, пока хотя бы один из старших битов результата не равен нулю или масштаб результата больше 28.
// Внутри цикла к результирующему числу прибавляется число 5, затем результат деления на 10, и уменьшается масштаб.
  s21_big_decimal five;
  clean_big_decimal(&five);
  five.bits[0] = 5;
  while ((result->bits[3] || result->bits[4] || result->bits[5]) ||
         *scale > 28) {
    *result = sum_big_decimal(*result, five);
    *result = div_big_on_ten(*result);
    (*scale)--;
  }
}
// Переменная five инициализируется значением 5, потому что в данном контексте она используется для коррекции результата умножения. 
// В формате S21 Decimal максимальное значение для каждого разряда составляет 9, 
// поэтому при умножении двух чисел максимальное значение результата может быть 81 (если оба множителя равны 9). 
// Поэтому при коррекции результата умножения наиболее подходящим значением для добавления является 5, так как это половина 
// максимального значения разряда в формате S21 Decimal. Именно поэтому используется значение 5 для переменной five
// деление двух децималов без нормализации степени
s21_decimal div_no_scale(s21_decimal dividend, s21_decimal divisor) {
  s21_decimal quotient;
  s21_decimal dec_null;
  clean_decimal(&dec_null);
  dividend.bits[3] = 0;
  if (s21_is_equal(dividend, divisor)) {
    clean_decimal(&quotient);
    quotient.bits[0] = 1;
  } else if (s21_is_equal(dividend, dec_null)) {
    clean_decimal(&quotient);
  } else {
    clean_decimal(&quotient);
    s21_decimal mask;
    clean_decimal(&mask);
    mask.bits[0] = 1;
    s21_decimal one;
    clean_decimal(&one);
    one.bits[0] = 1;
    s21_decimal temp;
    copy_decimal(&temp, &divisor);
    s21_decimal t_divisor;
    clean_decimal(&t_divisor);
    int flag = 0;
    while (s21_is_greater_or_equal(dividend, divisor)) {
      copy_decimal(&t_divisor, &divisor);
      shift_left(&t_divisor);
      if (get_bit(t_divisor, 95)) flag = 1;
      if (s21_is_greater_or_equal(dividend, t_divisor) &&
          s21_is_greater(t_divisor, dec_null) && flag == 0) {
        shift_left(&divisor);
        shift_left(&mask);
      } else {
        sum(quotient, mask, &quotient);
        s21_sub(dividend, divisor, &dividend);
        copy_decimal(&divisor, &temp);
        clean_decimal(&mask);
        mask.bits[0] = 1;
        flag = 0;
      }
    }
  }
  return quotient;
}

// выполняет нормализацию масштаба
void equal_scale(s21_decimal *dec1, s21_decimal *dec2) {
  int scale_dec1 = 0, scale_dec2 = 0;
  scale_dec1 = get_scale(dec1);
  scale_dec2 = get_scale(dec2);
  s21_decimal five;
  clean_decimal(&five);
  five.bits[0] = 5;
  if (scale_dec1 < scale_dec2) {
    while (scale_dec1 < scale_dec2) {
      if (get_bit(*dec1, 92) || get_bit(*dec1, 93) || get_bit(*dec1, 94) ||
          get_bit(*dec1, 95) || scale_dec1 > 28) {
        if (scale_dec2 - scale_dec1 == 1) {
          sum(*dec2, five, dec2);
          set_scale(dec2, scale_dec2);
        }
        lower_scale(dec2);
        scale_dec2 = get_scale(dec2);
      } else {
        upper_scale(dec1);
        scale_dec1 = get_scale(dec1);
      }
    }
  } else if (scale_dec2 < scale_dec1) {
    while (scale_dec2 < scale_dec1) {
      if (get_bit(*dec2, 92) || get_bit(*dec2, 93) || get_bit(*dec2, 94) ||
          get_bit(*dec2, 95) || scale_dec2 > 28) {
        if (scale_dec1 - scale_dec2 == 1) {
          sum(*dec1, five, dec1);
          set_scale(dec1, scale_dec1);
        }
        lower_scale(dec1);
        scale_dec1 = get_scale(dec1);
      } else {
        upper_scale(dec2);
        scale_dec2 = get_scale(dec2);
      }
    }
  }
}

// уменьшает scale числа
void lower_scale(s21_decimal *dec) {
  int scale = 0;
  unsigned int sign = 0;
  sign = get_sign(dec->bits[3]);
  scale = get_scale(dec) - 1;
  s21_decimal ten;
  clean_decimal(&ten);
  ten.bits[0] = 10;
  *dec = div_no_scale(*dec, ten);
  set_scale(dec, scale);
  if (sign) set_sign(&dec->bits[3]);
}

// увеличивает scale числа
void upper_scale(s21_decimal *dec) {
  int scale = 0;
  unsigned int sign = 0;
  sign = get_sign(dec->bits[3]);
  scale = get_scale(dec) + 1;
  s21_decimal ten;
  clean_decimal(&ten);
  ten.bits[0] = 10;
  s21_mul(*dec, ten, dec);
  set_scale(dec, scale);
  if (sign) set_sign(&dec->bits[3]);
}

// сложение бигов
s21_big_decimal sum_big_decimal(s21_big_decimal big1, s21_big_decimal big2) {
  int a, b, res, temp;
  s21_big_decimal result;
  clean_big_decimal(&result);
  temp = 0;
  for (int i = 0; i < 192; i++) {
    a = get_bit_big(big1, i);
    b = get_bit_big(big2, i);
    res = a + b + temp;
    if (res == 0) {
      temp = 0;
    } else if (res == 1) {
      temp = 0;
      set_bit_big(&result, i);
    } else if (res == 2) {
      temp = 1;
    } else if (res == 3) {
      temp = 1;
      set_bit_big(&result, i);
    }
  }
  return result;
}
// деления бига на 10
s21_big_decimal div_big_on_ten(s21_big_decimal big1) {
  s21_big_decimal ten, result, mask, temp;
  clean_big_decimal(&ten);
  ten.bits[0] = 10;
  clean_big_decimal(&result);
  clean_big_decimal(&mask);
  mask.bits[0] = 1;
  clean_big_decimal(&temp);
  int flag = 0;
  while (is_greater_or_equal_big(big1, ten)) {
    bigdecimal_copy(&temp, &ten);
    shift_left_big(&temp);
    if (get_bit_big(temp, 191)) flag = 1;
    if (is_greater_or_equal_big(big1, temp) && flag == 0) {
      shift_left_big(&ten);
      shift_left_big(&mask);
    } else {
      result = sum_big_decimal(result, mask);
      big_dop_code(&ten);
      big1 = sum_big_decimal(big1, ten);
      clean_big_decimal(&ten);
      ten.bits[0] = 10;
      clean_big_decimal(&mask);
      mask.bits[0] = 1;
      flag = 0;
    }
  }
  return result;
}
// инвертирует все биты бига и затем прибавляет 1
void big_dop_code(s21_big_decimal *big) {
  for (int i = 0; i < 6; ++i) {
    big->bits[i] = ~big->bits[i];
  }
  s21_big_decimal one;
  clean_big_decimal(&one);
  one.bits[0] = 1;
  *big = sum_big_decimal(*big, one);
}

int is_greater_or_equal_big(s21_big_decimal big1, s21_big_decimal big2) {
  int res = 0;
  if (big1.bits[0] == big2.bits[0] && big1.bits[1] == big2.bits[1] &&
      big1.bits[2] == big2.bits[2] && big1.bits[3] == big2.bits[3] &&
      big1.bits[4] == big2.bits[4] && big1.bits[5] == big2.bits[5]) {
    res = 1;
  } else {
    int a = 0, b = 0;
    for (int i = 191; i >= 0; --i) {
      a = get_bit_big(big1, i);
      b = get_bit_big(big2, i);
      if (a == b) continue;
      res = a > b ? 1 : 0;
      break;
    }
  }
  return res;
}

int get_bit_big(s21_big_decimal big, int index) {
  int res = -1;
  int mask = 1 << index;
  res = !!(big.bits[index / 32] & mask);
  return res;
}

void set_bit_big(s21_big_decimal *big, int index) {
  int mask = 1 << index;
  big->bits[index / 32] |= mask;
}

void shift_righ_big(s21_big_decimal *big) {
  int bit_160 = 0;
  int bit_128 = 0;
  int bit_96 = 0;
  int bit_64 = 0;
  int bit_32 = 0;
  bit_160 = get_bit_big(*big, 160);
  bit_128 = get_bit_big(*big, 128);
  bit_96 = get_bit_big(*big, 96);
  bit_64 = get_bit_big(*big, 64);
  bit_32 = get_bit_big(*big, 32);
  big->bits[5] >>= 1;
  big->bits[4] >>= 1;
  if (bit_160) set_bit_big(big, 159);
  big->bits[3] >>= 1;
  if (bit_128) set_bit_big(big, 127);
  big->bits[2] >>= 1;
  if (bit_96) set_bit_big(big, 95);
  big->bits[1] >>= 1;
  if (bit_64) set_bit_big(big, 63);
  big->bits[0] >>= 1;
  if (bit_32) set_bit_big(big, 31);
}

void shift_left_big(s21_big_decimal *big) {
  int bit_31 = 0;
  int bit_63 = 0;
  int bit_95 = 0;
  int bit_127 = 0;
  int bit_159 = 0;
  bit_31 = get_bit_big(*big, 31);
  bit_63 = get_bit_big(*big, 63);
  bit_95 = get_bit_big(*big, 95);
  bit_127 = get_bit_big(*big, 127);
  bit_159 = get_bit_big(*big, 159);
  big->bits[0] <<= 1;
  big->bits[1] <<= 1;
  big->bits[1] += bit_31;
  big->bits[2] <<= 1;
  big->bits[2] += bit_63;
  big->bits[3] <<= 1;
  big->bits[3] += bit_95;
  big->bits[4] <<= 1;
  big->bits[4] += bit_127;
  big->bits[5] <<= 1;
  big->bits[5] += bit_159;
}

void shift_left(s21_decimal *value) {
  int bit_31 = 0;
  int bit_63 = 0;
  bit_31 = get_bit(*value, 31);
  bit_63 = get_bit(*value, 63);
  value->bits[0] <<= 1;
  value->bits[1] <<= 1;
  value->bits[1] += bit_31;
  value->bits[2] <<= 1;
  value->bits[2] += bit_63;
}

void clean_big_decimal(s21_big_decimal *big) {
  for (int i = 0; i < 6; i++) {
    big->bits[i] = 0;
  }
}

void bigdecimal_copy(s21_big_decimal *big_dst, s21_big_decimal *big_src) {
  for (int i = 0; i < 6; ++i) {
    big_dst->bits[i] = big_src->bits[i];
  }
}

// преобразует числа типа s21_decimal в числа типа s21_big_decimal
s21_big_decimal big_decimal_init(s21_decimal value) {
  s21_big_decimal big_value;
  clean_big_decimal(&big_value);
  decimal_to_big_decimal(&big_value, &value);
  return big_value;
}

// переводы в биг из оычного и обратно
void decimal_to_big_decimal(s21_big_decimal *dst, s21_decimal *src) {
  for (int i = 0; i < 3; ++i) {
    dst->bits[i] = src->bits[i];
  }
}

void big_to_decimal(s21_decimal *dst, s21_big_decimal *src) {
  for (int i = 0; i < 3; ++i) {
    dst->bits[i] = src->bits[i];
  }
}

void switch_sign(s21_decimal *num, int result) {
  if (result == 1) {
    num->bits[3] = num->bits[3] | (1 << 31);
  } else if (result == 0) {
    num->bits[3] = num->bits[3] & ~(1 << 31);
  }
}

// принимает на вход децимал и возврашает его отрицательное значение, для этого
// инвертирует все биты числа и прибавляет к нему единицу
s21_decimal negtive(s21_decimal dec) {
  s21_decimal negtive_dec, one_dec, result;
  clean_decimal(&negtive_dec);
  clean_decimal(&one_dec);
  one_dec.bits[0] = 0b1;
  for (int i = 0; i < 3; i++) {
    negtive_dec.bits[i] = ~dec.bits[i];
  }
  sum(negtive_dec, one_dec, &result);
  return result;
}

// Функция для проверки, является ли первое десятичное число больше второго по
// модулю
int is_greater_by_abc(s21_decimal val_1, s21_decimal val_2) {
  int a, b, res = 0;
  // Перебор битов чисел справа налево
  for (int i = 95; i >= 0; i--) {
    // Получение i-го бита из чисел val_1 и val_2
    a = get_bit(val_1, i);
    b = get_bit(val_2, i);

    // Если биты равны, переходим к следующей итерации цикла
    if (a == b) continue;

    // Если биты не равны, устанавливаем значение res в зависимости от того,
    // какой бит больше
    res = a > b ? 1 : 0;
    break;
  }
  return res;
}

// Функция определения экспоненты числа float
int s21_get_float_exp(float *src) {
  return ((*(int *)src & ~0x80000000) >> 23) - 127;
}