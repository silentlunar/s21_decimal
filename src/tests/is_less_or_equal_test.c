#include "tests.h"

START_TEST(test_is_less_or_equal_1) {
  s21_decimal src1, src2;
  int expected;
  // src1 = 8;
  src1.bits[0] = 0b00000000000000000000000000001000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // src2 = 8;
  src2.bits[0] = 0b00000000000000000000000000001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int s21_out = s21_is_less_or_equal(src1, src2);
  expected = 1;
  ck_assert_int_eq(expected, s21_out);
}
END_TEST

START_TEST(test_is_less_or_equal_2) {
  s21_decimal src1, src2;
  int expected;
  // src1 = 8;
  src1.bits[0] = 0b00000000000000000000000000001000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // src2 = 8.00;
  src2.bits[0] = 0b00000000000000000000001100100000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000100000000000000000;
  int s21_out = s21_is_less_or_equal(src1, src2);
  expected = 1;
  ck_assert_int_eq(expected, s21_out);
}
END_TEST

START_TEST(test_is_less_or_equal_3) {
  s21_decimal src1, src2;
  int expected;
  // src1 = 5;
  src1.bits[0] = 0b00000000000000000000000000000101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // src2 = 8;
  src2.bits[0] = 0b00000000000000000000000000001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int s21_out = s21_is_less_or_equal(src1, src2);
  expected = 1;
  ck_assert_int_eq(expected, s21_out);
}
END_TEST

START_TEST(test_is_less_or_equal_4) {
  s21_decimal src1, src2;
  int expected;
  // src1 = 0.000000000000000000000000000;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000110110000000000000000;
  // src2 = 0;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int s21_out = s21_is_less_or_equal(src1, src2);
  expected = 1;
  ck_assert_int_eq(expected, s21_out);
}
END_TEST

START_TEST(test_is_less_or_equal_5) {
  s21_decimal src1, src2;
  int expected;
  // src1 = -16;
  src1.bits[0] = 0b00000000000000000000000000010000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  // src2 = 16;
  src2.bits[0] = 0b00000000000000000000000000010000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int s21_out = s21_is_less_or_equal(src1, src2);
  expected = 1;
  ck_assert_int_eq(expected, s21_out);
}
END_TEST

START_TEST(test_is_less_or_equal_6) {
  s21_decimal src1, src2;
  int expected;
  // src1 = 3.333313;
  src1.bits[0] = 0b00000000001100101101110011000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  // src2 = 3.333313;
  src2.bits[0] = 0b00000000001100101101110011000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int s21_out = s21_is_less_or_equal(src1, src2);
  expected = 1;
  ck_assert_int_eq(expected, s21_out);
}
END_TEST

START_TEST(test_is_less_or_equal_7) {
  s21_decimal src1, src2;
  int expected;
  // src1 = 3.33331300000001000;
  src1.bits[0] = 0b00100001000001001110101111101000;
  src1.bits[1] = 0b00000100101000000011101100001101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100010000000000000000;
  // src2 = 3.333313;
  src2.bits[0] = 0b00000000001100101101110011000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int s21_out = s21_is_less_or_equal(src1, src2);
  expected = 0;
  ck_assert_int_eq(expected, s21_out);
}
END_TEST

START_TEST(test_is_less_or_equal_8) {
  s21_decimal src1, src2;
  int expected;
  // src1 = 5.2222121;
  src1.bits[0] = 0b00000011000111001101100010101001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001110000000000000000;
  // src2 = 5.222212;
  src2.bits[0] = 0b00000000010011111010111101000100;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000001100000000000000000;
  int s21_out = s21_is_less_or_equal(src1, src2);
  expected = 0;
  ck_assert_int_eq(expected, s21_out);
}
END_TEST

START_TEST(test_is_less_or_equal_9) {
  s21_decimal src1, src2;
  int expected;
  // src1 = 3.333313;
  src1.bits[0] = 0b00000000001100101101110011000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000001100000000000000000;
  // src2 = -3.3333130003;
  src2.bits[0] = 0b11000010110011110011001100010011;
  src2.bits[1] = 0b00000000000000000000000000000111;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000010100000000000000000;
  int s21_out = s21_is_less_or_equal(src1, src2);
  expected = 0;
  ck_assert_int_eq(expected, s21_out);
}
END_TEST

START_TEST(test_is_less_or_equal_10) {
  s21_decimal src1, src2;
  int expected;
  // src1 = -549842;
  src1.bits[0] = 0b00000000000010000110001111010010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  // src2 = 1;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int s21_out = s21_is_less_or_equal(src1, src2);
  expected = 1;
  ck_assert_int_eq(expected, s21_out);
}
END_TEST

START_TEST(test_is_less_or_equal_11) {
  s21_decimal src1, src2;
  int expected;
  // src1 = 987456543210.0;
  src1.bits[0] = 0b00011001111101110000001100100100;
  src1.bits[1] = 0b00000000000000000000100011111011;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  // src2 = 98745654321.0;
  src2.bits[0] = 0b11101000111111110001100111101010;
  src2.bits[1] = 0b00000000000000000000000011100101;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000010000000000000000;
  int s21_out = s21_is_less_or_equal(src1, src2);
  expected = 0;
  ck_assert_int_eq(expected, s21_out);
}
END_TEST

START_TEST(test_is_less_or_equal_12) {
  s21_decimal src1, src2;
  int expected;
  // src1 = -9878798789.5867800;
  src1.bits[0] = 0b11001110100110111101100110011000;
  src1.bits[1] = 0b00000001010111101111011100100110;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000001110000000000000000;
  // src2 = -9878798789.58678;
  src2.bits[0] = 0b10110101010001000001111001010110;
  src2.bits[1] = 0b00000000000000111000001001111000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001010000000000000000;
  int s21_out = s21_is_less_or_equal(src1, src2);
  expected = 1;
  ck_assert_int_eq(expected, s21_out);
}
END_TEST

START_TEST(test_is_less_or_equal_13) {
  s21_decimal src1, src2;
  int expected;
  // src1 = 18446744073709551615;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // src2 = 18446744073709551615.000000000;
  src2.bits[0] = 0b11000100011001010011011000000000;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b00111011100110101100100111111111;
  src2.bits[3] = 0b00000000000010010000000000000000;
  int s21_out = s21_is_less_or_equal(src1, src2);
  expected = 1;
  ck_assert_int_eq(expected, s21_out);
}
END_TEST

START_TEST(test_is_less_or_equal_14) {
  s21_decimal src1, src2;
  int expected;
  // src1 = -512315843546546.41215465184132;
  src1.bits[0] = 0b01100011011010011101101110000100;
  src1.bits[1] = 0b11011100000010110100011100010111;
  src1.bits[2] = 0b10100101100010011100010111111000;
  src1.bits[3] = 0b10000000000011100000000000000000;
  // src2 = -512315843546546.41215465184132;
  src2.bits[0] = 0b01100011011010011101101110000100;
  src2.bits[1] = 0b11011100000010110100011100010111;
  src2.bits[2] = 0b10100101100010011100010111111000;
  src2.bits[3] = 0b10000000000011100000000000000000;
  int s21_out = s21_is_less_or_equal(src1, src2);
  expected = 1;
  ck_assert_int_eq(expected, s21_out);
}
END_TEST

Suite *suite_is_less_or_equal(void) {
  Suite *s = suite_create("s21_is_less_or_equal");
  TCase *tc = tcase_create("s21_is_less_or_equal_tc");

  tcase_add_test(tc, test_is_less_or_equal_1);
  tcase_add_test(tc, test_is_less_or_equal_2);
  tcase_add_test(tc, test_is_less_or_equal_3);
  tcase_add_test(tc, test_is_less_or_equal_4);
  tcase_add_test(tc, test_is_less_or_equal_5);
  tcase_add_test(tc, test_is_less_or_equal_6);
  tcase_add_test(tc, test_is_less_or_equal_7);
  tcase_add_test(tc, test_is_less_or_equal_8);
  tcase_add_test(tc, test_is_less_or_equal_9);
  tcase_add_test(tc, test_is_less_or_equal_10);
  tcase_add_test(tc, test_is_less_or_equal_11);
  tcase_add_test(tc, test_is_less_or_equal_12);
  tcase_add_test(tc, test_is_less_or_equal_13);
  tcase_add_test(tc, test_is_less_or_equal_14);

  suite_add_tcase(s, tc);
  return s;
}
