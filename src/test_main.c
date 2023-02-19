#include <stdio.h>
#include <stdlib.h>

#include "tests/unit.h"

void run_test_case(Suite *testcase);
void run_all_tests();

int main() {
  run_all_tests();
  return 0;
}

void run_test_case(Suite *testcase) {
  static int count = 1;
  printf("TEST CASE №%d\n", count++);

  SRunner *sr;
  sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}

void run_all_tests() {
  Suite *list_cases[] = {
      suite_s21_memchr(), suite_s21_memcmp(), suite_s21_memmove(), suite_s21_memset(), suite_s21_strlen(), example_suite_create(), arn_test(),
      suite_s21_strncat(), suite_s21_strchr(), suite_s21_strpbrk(), 
  };
  for (int i = 0; i < (int)(sizeof(list_cases) / sizeof(Suite *)); i++)
    run_test_case(list_cases[i]);
}
