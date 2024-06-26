#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[6];
} s21_big_decimal;

enum { NORMAL_VALUE, MY_INFINITY, NEGATIVE_INFINITY, MY_NAN };

// Арифметические операторы
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Операторы сравнение
int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);

// Преобразователи
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// Другие функции

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// HELP

int s21_get_float_exp(float *src);
int get_sign(int val);
void set_sign(unsigned int *val);
int get_scale(s21_decimal *dec);
void set_scale(s21_decimal *dec, int scale);
int set_bit(s21_decimal *dec, int index);
int get_bit(s21_decimal dec, int index);
int is_zero(s21_decimal val);
void copy_decimal(s21_decimal *dest, s21_decimal *src);
void clean_decimal(s21_decimal *dec);
int sum(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
s21_decimal div_no_scale(s21_decimal dividend, s21_decimal divisor);
void equal_scale(s21_decimal *dec1, s21_decimal *dec2);
void lower_scale(s21_decimal *dec);
void upper_scale(s21_decimal *dec);

void set_minus_sign(unsigned int *val);
s21_decimal negtive(s21_decimal dec);
int is_greater_by_abc(s21_decimal val_1, s21_decimal val_2);
void big_dop_code(s21_big_decimal *big);
void shift_left(s21_decimal *value);
void switch_sign(s21_decimal *num, int result);

// big
int get_bit_big(s21_big_decimal big, int index);
void set_bit_big(s21_big_decimal *big, int index);
void bigdecimal_copy(s21_big_decimal *, s21_big_decimal *);
void shift_left_big(s21_big_decimal *big);
void shift_righ_big(s21_big_decimal *big);
s21_big_decimal div_big_on_ten(s21_big_decimal big1);
s21_big_decimal sum_big_decimal(s21_big_decimal big1, s21_big_decimal big2);
s21_big_decimal big_decimal_init(s21_decimal value);
void clean_big_decimal(s21_big_decimal *big);
void big_to_decimal(s21_decimal *dst, s21_big_decimal *src);
void decimal_to_big_decimal(s21_big_decimal *dst, s21_decimal *src);
int is_greater_or_equal_big(s21_big_decimal big1, s21_big_decimal big2);
void s21_mul_helper(s21_big_decimal v1, s21_big_decimal v2,
                    s21_big_decimal *result, int *scale);

#endif  // S21_DECIMAL_H