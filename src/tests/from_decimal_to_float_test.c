#include "tests.h"

// 5
START_TEST(test_dec_to_float_1) {
  s21_decimal number;
  number.bits[0] = 0b00000000000000000000000000000101;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1084227584;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

// 0.3
START_TEST(test_dec_to_float_2) {
  s21_decimal number;
  number.bits[0] = 0b00000000000000000000000000000011;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000010000000000000000;
  int result_int = 1050253722;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

// 0
START_TEST(test_dec_to_float_3) {
  s21_decimal number;
  number.bits[0] = 0b00000000000000000000000000000000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 0;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

// 123
START_TEST(test_dec_to_float_4) {
  s21_decimal number;
  number.bits[0] = 0b00000000000000000000000001111011;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1123418112;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

// 0.0
START_TEST(test_dec_to_float_5) {
  s21_decimal number;
  number.bits[0] = 0b00000000000000000000000000000000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000010000000000000000;
  int result_int = -2147483648;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

// -3.543
START_TEST(test_dec_to_float_6) {
  s21_decimal number;
  number.bits[0] = 0b00000000000000000000110111010111;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000110000000000000000;
  int result_int = -1067270013;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

// 7543
START_TEST(test_dec_to_float_7) {
  s21_decimal number;
  number.bits[0] = 0b00000000000000000001110101110111;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1173075968;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

// 43
START_TEST(test_dec_to_float_8) {
  s21_decimal number;
  number.bits[0] = 0b00000000000000000000000000101011;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1110179840;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

// 49272059
START_TEST(test_dec_to_float_9) {
  s21_decimal number;
  number.bits[0] = 0b00000010111011111101010011111011;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1278997823;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

// -69851269
START_TEST(test_dec_to_float_10) {
  s21_decimal number;
  number.bits[0] = 0b00000100001010011101100010000101;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000000000000000000000;
  int result_int = -863683823;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

// 0.0008
START_TEST(test_dec_to_float_11) {
  s21_decimal number;
  number.bits[0] = 0b00000000000000000000000000001000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000001000000000000000000;
  int result_int = 978433815;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

// -999999999999
START_TEST(test_dec_to_float_12) {
  s21_decimal number;
  number.bits[0] = 0b11010100101001010000111111111111;
  number.bits[1] = 0b00000000000000000000000011101000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000000000000000000000;
  int result_int = -748104539;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

// -79228162514264337593543950335
START_TEST(test_dec_to_float_13) {
  s21_decimal number;
  number.bits[0] = 0b11111111111111111111111111111111;
  number.bits[1] = 0b11111111111111111111111111111111;
  number.bits[2] = 0b11111111111111111111111111111111;
  number.bits[3] = 0b10000000000000000000000000000000;
  int result_int = -276824064;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

// -2.7986531268974139743
START_TEST(test_dec_to_float_14) {
  s21_decimal number;
  number.bits[0] = 0b11111110100100001101100101011111;
  number.bits[1] = 0b10000100011001000010000111101000;
  number.bits[2] = 0b00000000000000000000000000000001;
  number.bits[3] = 0b10000000000100110000000000000000;
  int result_int = -1070392030;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

Suite *suite_from_decimal_to_float(void) {
  Suite *s = suite_create("s21_from_decimal_to_float");
  TCase *tc = tcase_create("s21_from_decimal_to_float_tc");

  tcase_add_test(tc, test_dec_to_float_1);
  tcase_add_test(tc, test_dec_to_float_2);
  tcase_add_test(tc, test_dec_to_float_3);
  tcase_add_test(tc, test_dec_to_float_4);
  tcase_add_test(tc, test_dec_to_float_5);
  tcase_add_test(tc, test_dec_to_float_6);
  tcase_add_test(tc, test_dec_to_float_7);
  tcase_add_test(tc, test_dec_to_float_8);
  tcase_add_test(tc, test_dec_to_float_9);
  tcase_add_test(tc, test_dec_to_float_10);
  tcase_add_test(tc, test_dec_to_float_11);
  tcase_add_test(tc, test_dec_to_float_12);
  tcase_add_test(tc, test_dec_to_float_13);
  tcase_add_test(tc, test_dec_to_float_14);

  suite_add_tcase(s, tc);
  return s;
}
