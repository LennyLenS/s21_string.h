#include "unit.h"

START_TEST(s21_memcmp_test) {
  char *test_1 = "123456";
  char *test_2 = "      ";
  char *test_3 = "ASDF";
  char *test_4 = "true\0fail";

  ck_assert_int_gt(s21_memcmp(test_1, "5", 1) * memcmp(test_1, "5", 1), 0);
  ck_assert_int_gt(s21_memcmp(test_1, "111", 3) * memcmp(test_1, "111", 3), 0);
  ck_assert_int_eq(s21_memcmp(test_1, "123456", 6) * memcmp(test_1, "123456", 6), 0);
  ck_assert_int_eq(s21_memcmp(test_1, "12345", 5) * memcmp(test_1, "12345", 5), 0);

  ck_assert_int_eq(s21_memcmp(test_2, " ", 1) * memcmp(test_2, " ", 1), 0);
  ck_assert_int_gt(s21_memcmp(test_2, " ", 2) * memcmp(test_2, " ", 2), 0);
  ck_assert_int_gt(s21_memcmp(test_2, "1234", 3)*memcmp(test_2, "1234", 3), 0);

  ck_assert_int_eq(s21_memcmp(test_3, "ASDF", 4)* memcmp(test_3, "ASDF", 4), 0);
  ck_assert_int_gt(s21_memcmp(test_3, "asdf", 4) * memcmp(test_3, "asdf", 4), 0);
  ck_assert_int_gt(s21_memcmp(test_3, "aaaaaa", 6) * memcmp(test_3, "aaaaaa", 6), 0);

  ck_assert_int_gt(s21_memcmp(test_4, "\0", 1) * memcmp(test_4, "\0", 1), 0);
  ck_assert_int_eq(s21_memcmp(test_4, "true\0", 5) * memcmp(test_4, "true\0", 5), 0);
}
END_TEST

Suite *suite_s21_memcmp() {
  Suite *s = suite_create("s21_memcmp");
  TCase *temp = tcase_create("test_memcmp");

  suite_add_tcase(s, temp);

  tcase_add_test(temp, s21_memcmp_test);

  return s;
}
