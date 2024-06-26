#include "tests.h"

int main(void) {
  tests_launcher();

  return 0;
}

void testcase_launcher(Suite *testcase) {
  static int counter = 1;

  if (counter > 1) putchar('\n');
  printf("%d ", counter);
  counter++;

  SRunner *sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
}

#ifdef FUNC_1
void tests_launcher(void) {
  Suite *tests_list[] = {suite_func_1(), NULL};

  for (Suite **current = tests_list; *current != NULL; current++) {
    testcase_launcher(*current);
  }
}
#elif FUNC_2
void tests_launcher(void) {
  Suite *tests_list[] = {suite_func_2(), NULL};

  for (Suite **current = tests_list; *current != NULL; current++) {
    testcase_launcher(*current);
  }
}
#else
void tests_launcher(void) {
  Suite *tests_list[] = {suite_add(),
                         suite_sub(),
                         suite_mul(),
                         suite_div(),
                         suite_floor(),
                         suite_round(),
                         suite_truncate(),
                         suite_negate(),
                         suite_is_equal(),
                         suite_is_not_equal(),
                         suite_is_greater(),
                         suite_is_greater_or_equal(),
                         suite_is_less(),
                         suite_is_less_or_equal(),
                         suite_from_int_to_decimal(),
                         suite_from_float_to_decimal(),
                         suite_from_decimal_to_int(),
                         suite_from_decimal_to_float(),
                         NULL};

  for (Suite **current = tests_list; *current != NULL; current++) {
    testcase_launcher(*current);
  }
}
#endif