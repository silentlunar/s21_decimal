#include "tests.h"

START_TEST(test_round_1) {
  s21_decimal src, orig, res;
  // src = 0.0;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int s21_out = s21_round(src, &res);
  int expected = 0;
  // orig = 0;
  orig.bits[0] = 0b00000000000000000000000000000000;
  orig.bits[1] = 0b00000000000000000000000000000000;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_round_2) {
  s21_decimal src, orig, res;
  // src = -0.0;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000010000000000000000;
  int s21_out = s21_round(src, &res);
  int expected = 0;
  // orig = 0;
  orig.bits[0] = 0b00000000000000000000000000000000;
  orig.bits[1] = 0b00000000000000000000000000000000;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_round_3) {
  s21_decimal src, orig, res;
  // src = 7.0;
  src.bits[0] = 0b00000000000000000000000001000110;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int s21_out = s21_round(src, &res);
  int expected = 0;
  // orig = 7;
  orig.bits[0] = 0b00000000000000000000000000000111;
  orig.bits[1] = 0b00000000000000000000000000000000;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_round_4) {
  s21_decimal src, orig, res;
  // src = 6.4;
  src.bits[0] = 0b00000000000000000000000001000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int s21_out = s21_round(src, &res);
  int expected = 0;
  // orig = 6;
  orig.bits[0] = 0b00000000000000000000000000000110;
  orig.bits[1] = 0b00000000000000000000000000000000;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_round_5) {
  s21_decimal src, orig, res;
  // src = -3.3181564;
  src.bits[0] = 0b00000001111110100100111101111100;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000001110000000000000000;
  int s21_out = s21_round(src, &res);
  int expected = 0;
  // orig = -3;
  orig.bits[0] = 0b00000000000000000000000000000011;
  orig.bits[1] = 0b00000000000000000000000000000000;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_round_6) {
  s21_decimal src, orig, res;
  // src = -0.46;
  src.bits[0] = 0b00000000000000000000000000101110;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000100000000000000000;
  int s21_out = s21_round(src, &res);
  int expected = 0;
  // orig = 0;
  orig.bits[0] = 0b00000000000000000000000000000000;
  orig.bits[1] = 0b00000000000000000000000000000000;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_round_7) {
  s21_decimal src, orig, res;
  // src = 467.35463;
  src.bits[0] = 0b00000010110010010010000001100111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001010000000000000000;
  int s21_out = s21_round(src, &res);
  int expected = 0;
  // orig = 467;
  orig.bits[0] = 0b00000000000000000000000111010011;
  orig.bits[1] = 0b00000000000000000000000000000000;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_round_8) {
  s21_decimal src, orig, res;
  // src = 3.98416343;
  src.bits[0] = 0b00010111101111110101100111010111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000010000000000000000000;
  int s21_out = s21_round(src, &res);
  int expected = 0;
  // orig = 4;
  orig.bits[0] = 0b00000000000000000000000000000100;
  orig.bits[1] = 0b00000000000000000000000000000000;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_round_9) {
  s21_decimal src, orig, res;
  // src = 74767565.61;
  src.bits[0] = 0b10111101101001100100000001010001;
  src.bits[1] = 0b00000000000000000000000000000001;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000100000000000000000;
  int s21_out = s21_round(src, &res);
  int expected = 0;
  // orig = 74767566;
  orig.bits[0] = 0b00000100011101001101110011001110;
  orig.bits[1] = 0b00000000000000000000000000000000;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_round_10) {
  s21_decimal src, orig, res;
  // src = -463683.240;
  src.bits[0] = 0b00011011101000110011111010101000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000110000000000000000;
  int s21_out = s21_round(src, &res);
  int expected = 0;
  // orig = -463683;
  orig.bits[0] = 0b00000000000001110001001101000011;
  orig.bits[1] = 0b00000000000000000000000000000000;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_round_11) {
  s21_decimal src, orig, res;
  // src = 2.9786545573243;
  src.bits[0] = 0b00111000011101111100110101111011;
  src.bits[1] = 0b00000000000000000001101100010111;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000011010000000000000000;
  int s21_out = s21_round(src, &res);
  int expected = 0;
  // orig = 3;
  orig.bits[0] = 0b00000000000000000000000000000011;
  orig.bits[1] = 0b00000000000000000000000000000000;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_round_12) {
  s21_decimal src, orig, res;
  // src = -298.87897898413;
  src.bits[0] = 0b11010001100010011000110110101101;
  src.bits[1] = 0b00000000000000000001101100101110;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000010110000000000000000;
  int s21_out = s21_round(src, &res);
  int expected = 0;
  // orig = -299;
  orig.bits[0] = 0b00000000000000000000000100101011;
  orig.bits[1] = 0b00000000000000000000000000000000;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_round_13) {
  s21_decimal src, orig, res;
  // src = 99999999999999999911.357745765;
  src.bits[0] = 0b01101100100000101000101001100101;
  src.bits[1] = 0b00111110001001010000001001001100;
  src.bits[2] = 0b00100000010011111100111001011110;
  src.bits[3] = 0b00000000000010010000000000000000;
  int s21_out = s21_round(src, &res);
  int expected = 0;
  // orig = 9999999999999999911;
  orig.bits[0] = 0b10001001111001111111111110100111;
  orig.bits[1] = 0b10001010110001110010001100000100;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_round_14) {
  s21_decimal src, orig, res;
  // src = -456765623565656.46376565656756;
  src.bits[0] = 0b01011101111111101100110010110100;
  src.bits[1] = 0b11101110110100101101000011001011;
  src.bits[2] = 0b10010011100101101100010001001110;
  src.bits[3] = 0b10000000000011100000000000000000;
  int s21_out = s21_round(src, &res);
  int expected = 0;
  // orig = -456765623565656;
  orig.bits[0] = 0b00001000101111001111110101011000;
  orig.bits[1] = 0b00000000000000011001111101101101;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_round_15) {
  s21_decimal src, orig, res;
  // src = 456765623565656.46376565656756;
  src.bits[0] = 0b01011101111111101100110010110100;
  src.bits[1] = 0b11101110110100101101000011001011;
  src.bits[2] = 0b10010011100101101100010001001110;
  src.bits[3] = 0b00000000000011100000000000000000;
  int s21_out = s21_round(src, &res);
  int expected = 0;
  // orig = 456765623565657;
  orig.bits[0] = 0b00001000101111001111110101011000;
  orig.bits[1] = 0b00000000000000011001111101101101;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_round_16) {
  s21_decimal src, orig, res;
  ;
  // src = 12345677.987654321234567898765;
  src.bits[0] = 0b10010001000010101111010011001010;
  src.bits[1] = 0b11000000010001011101010111110010;
  src.bits[2] = 0b00100111111001000001101100000000;
  src.bits[3] = 0b00000000000101010000000000000000;
  int s21_out = s21_round(src, &res);
  int expected = 0;
  // orig = 12345678;
  orig.bits[0] = 0b00000000101111000110000101001110;
  orig.bits[1] = 0b00000000000000000000000000000000;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_round_17) {
  s21_decimal src, orig, res;
  // src = -12345677.987654345678987654346;
  src.bits[0] = 0b10010001000010101111010011001010;
  src.bits[1] = 0b11000000010001011101010111110010;
  src.bits[2] = 0b00100111111001000001101100000000;
  src.bits[3] = 0b10000000000101010000000000000000;
  int s21_out = s21_round(src, &res);
  int expected = 0;
  // orig = -12345678;
  orig.bits[0] = 0b00000000101111000110000101001110;
  orig.bits[1] = 0b00000000000000000000000000000000;
  orig.bits[2] = 0b00000000000000000000000000000000;
  orig.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(orig.bits[3], res.bits[3]);
  ck_assert_int_eq(orig.bits[2], res.bits[2]);
  ck_assert_int_eq(orig.bits[1], res.bits[1]);
  ck_assert_int_eq(orig.bits[0], res.bits[0]);
  ck_assert_int_eq(s21_out, expected);
}
END_TEST

START_TEST(test_round_18) {
  s21_decimal src, orig, res;
  // src = 79228162514264337593543950335;
  src.bits[0] = 0b11111111111111111111111111111111;
  src.bits[1] = 0b11111111111111111111111111111111;
  src.bits[2] = 0b11111111111111111111111111111111;
  src.bits[3] = 0b00000000000000000000000000000000;
  int s21_out = s21_round(src, &res);
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

START_TEST(test_round_19) {
  s21_decimal src, orig, res;
  // src = 79228162514264337593543950335;
  src.bits[0] = 0b11111111111111111111111111111111;
  src.bits[1] = 0b11111111111111111111111111111111;
  src.bits[2] = 0b11111111111111111111111111111111;
  src.bits[3] = 0b10000000000000000000000000000000;
  int s21_out = s21_round(src, &res);
  int expected = 0;
  // orig = 79228162514264337593543950335;
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

Suite *suite_round(void) {
  Suite *s = suite_create("s21_round");
  TCase *tc = tcase_create("s21_round_tc");

  tcase_add_test(tc, test_round_1);
  tcase_add_test(tc, test_round_2);
  tcase_add_test(tc, test_round_3);
  tcase_add_test(tc, test_round_4);
  tcase_add_test(tc, test_round_5);
  tcase_add_test(tc, test_round_6);
  tcase_add_test(tc, test_round_7);
  tcase_add_test(tc, test_round_8);
  tcase_add_test(tc, test_round_9);
  tcase_add_test(tc, test_round_10);
  tcase_add_test(tc, test_round_11);
  tcase_add_test(tc, test_round_12);
  tcase_add_test(tc, test_round_13);
  tcase_add_test(tc, test_round_14);
  tcase_add_test(tc, test_round_15);
  tcase_add_test(tc, test_round_16);
  tcase_add_test(tc, test_round_17);
  tcase_add_test(tc, test_round_18);
  tcase_add_test(tc, test_round_19);

  suite_add_tcase(s, tc);
  return s;
}
