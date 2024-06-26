#include "tests.h"

START_TEST(test_negate_1) {
  s21_decimal src, orig, res;
  // src = 0.0;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int s21_out = s21_negate(src, &res);
  int expected = 0;
  // orig = -0.0;
  orig.bits[0] = 0b00000000000000000000000000000000;
  orig.bits[1] = 0b00000000000000000000000000000000;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b10000000000000010000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_negate_2) {
  s21_decimal src, orig, res;
  // src = -0.0;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000010000000000000000;
  int s21_out = s21_negate(src, &res);
  int expected = 0;
  // orig = 0.0;
  orig.bits[0] = 0b00000000000000000000000000000000;
  orig.bits[1] = 0b00000000000000000000000000000000;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b00000000000000010000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_negate_3) {
  s21_decimal src, orig, res;
  // src = 7.0;
  src.bits[0] = 0b00000000000000000000000001000110;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int s21_out = s21_negate(src, &res);
  int expected = 0;
  // orig = -7.0;
  orig.bits[0] = 0b00000000000000000000000001000110;
  orig.bits[1] = 0b00000000000000000000000000000000;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b10000000000000010000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_negate_4) {
  s21_decimal src, orig, res;
  // src = 6.4;
  src.bits[0] = 0b00000000000000000000000001000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int s21_out = s21_negate(src, &res);
  int expected = 0;
  // orig = -6.4;
  orig.bits[0] = 0b00000000000000000000000001000000;
  orig.bits[1] = 0b00000000000000000000000000000000;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b10000000000000010000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_negate_5) {
  s21_decimal src, orig, res;
  // src = -3.3181564;
  src.bits[0] = 0b00000001111110100100111101111100;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000001110000000000000000;
  int s21_out = s21_negate(src, &res);
  int expected = 0;
  // orig = 3.3181564;
  orig.bits[0] = 0b00000001111110100100111101111100;
  orig.bits[1] = 0b00000000000000000000000000000000;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b00000000000001110000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_negate_6) {
  s21_decimal src, orig, res;
  // src = -1.46;
  src.bits[0] = 0b00000000000000000000000010010010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000100000000000000000;
  int s21_out = s21_negate(src, &res);
  int expected = 0;
  // orig = 1.46;
  orig.bits[0] = 0b00000000000000000000000010010010;
  orig.bits[1] = 0b00000000000000000000000000000000;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b00000000000000100000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_negate_7) {
  s21_decimal src, orig, res;
  // src = 467.35463;
  src.bits[0] = 0b00000010110010010010000001100111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001010000000000000000;
  int s21_out = s21_negate(src, &res);
  int expected = 0;
  // orig = -467.35463;
  orig.bits[0] = 0b00000010110010010010000001100111;
  orig.bits[1] = 0b00000000000000000000000000000000;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b10000000000001010000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_negate_8) {
  s21_decimal src, orig, res;
  // src = 3.98416343;
  src.bits[0] = 0b00010111101111110101100111010111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000010000000000000000000;
  int s21_out = s21_negate(src, &res);
  int expected = 0;
  // orig = -3.98416343;
  orig.bits[0] = 0b00010111101111110101100111010111;
  orig.bits[1] = 0b00000000000000000000000000000000;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b10000000000010000000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_negate_9) {
  s21_decimal src, orig, res;
  // src = 74767565.61;
  src.bits[0] = 0b10111101101001100100000001010001;
  src.bits[1] = 0b00000000000000000000000000000001;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000100000000000000000;
  int s21_out = s21_negate(src, &res);
  int expected = 0;
  // orig = -74767565.61;
  orig.bits[0] = 0b10111101101001100100000001010001;
  orig.bits[1] = 0b00000000000000000000000000000001;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b10000000000000100000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_negate_10) {
  s21_decimal src, orig, res;
  // src = -463683.240;
  src.bits[0] = 0b00011011101000110011111010101000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000110000000000000000;
  int s21_out = s21_negate(src, &res);
  int expected = 0;
  // orig = 463683.240;
  orig.bits[0] = 0b00011011101000110011111010101000;
  orig.bits[1] = 0b00000000000000000000000000000000;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b00000000000000110000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_negate_11) {
  s21_decimal src, orig, res;
  // src = 2.9786545573243;
  src.bits[0] = 0b00111000011101111100110101111011;
  src.bits[1] = 0b00000000000000000001101100010111;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000011010000000000000000;
  int s21_out = s21_negate(src, &res);
  int expected = 0;
  // orig = -2.9786545573243;
  orig.bits[0] = 0b00111000011101111100110101111011;
  orig.bits[1] = 0b00000000000000000001101100010111;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b10000000000011010000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_negate_12) {
  s21_decimal src, orig, res;
  // src = -298.87897898413;
  src.bits[0] = 0b11010001100010011000110110101101;
  src.bits[1] = 0b00000000000000000001101100101110;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000010110000000000000000;
  int s21_out = s21_negate(src, &res);
  int expected = 0;
  // orig = 298.87897898413;
  orig.bits[0] = 0b11010001100010011000110110101101;
  orig.bits[1] = 0b00000000000000000001101100101110;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b00000000000010110000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_negate_13) {
  s21_decimal src, orig, res;
  // src = 99999999999999999911.357745765;
  src.bits[0] = 0b01101100100000101000101001100101;
  src.bits[1] = 0b00111110001001010000001001001100;
  src.bits[2] = 0b00100000010011111100111001011110;
  src.bits[3] = 0b00000000000010010000000000000000;
  int s21_out = s21_negate(src, &res);
  int expected = 0;
  // orig = -99999999999999999911.357745765;
  orig.bits[0] = 0b01101100100000101000101001100101;
  orig.bits[1] = 0b00111110001001010000001001001100;
  orig.bits[2] = 0b00100000010011111100111001011110;
  orig.bits[3] = 0b10000000000010010000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_negate_14) {
  s21_decimal src, orig, res;
  // src = -456765623565656.46376565656756;
  src.bits[0] = 0b01011101111111101100110010110100;
  src.bits[1] = 0b11101110110100101101000011001011;
  src.bits[2] = 0b10010011100101101100010001001110;
  src.bits[3] = 0b10000000000011100000000000000000;
  int s21_out = s21_negate(src, &res);
  int expected = 0;
  // orig = 456765623565656.46376565656756;
  orig.bits[0] = 0b01011101111111101100110010110100;
  orig.bits[1] = 0b11101110110100101101000011001011;
  orig.bits[2] = 0b10010011100101101100010001001110;
  orig.bits[3] = 0b00000000000011100000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_negate_15) {
  s21_decimal src, orig, res;
  // src = 456765623565656.46376565656756;
  src.bits[0] = 0b01011101111111101100110010110100;
  src.bits[1] = 0b11101110110100101101000011001011;
  src.bits[2] = 0b10010011100101101100010001001110;
  src.bits[3] = 0b00000000000011100000000000000000;
  int s21_out = s21_negate(src, &res);
  int expected = 0;
  // orig = -456765623565656.46376565656756;
  orig.bits[0] = 0b01011101111111101100110010110100;
  orig.bits[1] = 0b11101110110100101101000011001011;
  orig.bits[2] = 0b10010011100101101100010001001110;
  orig.bits[3] = 0b10000000000011100000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_negate_16) {
  s21_decimal src, orig, res;
  // src = 79228162514264337593543950335;
  src.bits[0] = 0b11111111111111111111111111111111;
  src.bits[1] = 0b11111111111111111111111111111111;
  src.bits[2] = 0b11111111111111111111111111111111;
  src.bits[3] = 0b00000000000000000000000000000000;
  int s21_out = s21_negate(src, &res);
  int expected = 0;
  // orig = -79228162514264337593543950335;
  orig.bits[0] = 0b11111111111111111111111111111111;
  orig.bits[1] = 0b11111111111111111111111111111111;
  orig.bits[2] = 0b11111111111111111111111111111111;
  orig.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_negate_17) {
  s21_decimal src, orig, res;
  // src = -79228162514264337593543950335;
  src.bits[0] = 0b11111111111111111111111111111111;
  src.bits[1] = 0b11111111111111111111111111111111;
  src.bits[2] = 0b11111111111111111111111111111111;
  src.bits[3] = 0b10000000000000000000000000000000;
  int s21_out = s21_negate(src, &res);
  int expected = 0;
  // orig = 79228162514264337593543950335;
  orig.bits[0] = 0b11111111111111111111111111111111;
  orig.bits[1] = 0b11111111111111111111111111111111;
  orig.bits[2] = 0b11111111111111111111111111111111;
  orig.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

Suite *suite_negate(void) {
  Suite *s = suite_create("s21_negate");
  TCase *tc = tcase_create("s21_negate_tc");

  tcase_add_test(tc, test_negate_1);
  tcase_add_test(tc, test_negate_2);
  tcase_add_test(tc, test_negate_3);
  tcase_add_test(tc, test_negate_4);
  tcase_add_test(tc, test_negate_5);
  tcase_add_test(tc, test_negate_6);
  tcase_add_test(tc, test_negate_7);
  tcase_add_test(tc, test_negate_8);
  tcase_add_test(tc, test_negate_9);
  tcase_add_test(tc, test_negate_10);
  tcase_add_test(tc, test_negate_11);
  tcase_add_test(tc, test_negate_12);
  tcase_add_test(tc, test_negate_13);
  tcase_add_test(tc, test_negate_14);
  tcase_add_test(tc, test_negate_15);
  tcase_add_test(tc, test_negate_16);
  tcase_add_test(tc, test_negate_17);

  suite_add_tcase(s, tc);
  return s;
}