#include "unit.h"

START_TEST(s21_memchr_test) {
  char *test_1 = "123456";
  char *test_2 = "      ";
  char *test_3 = "asdfg\1asdft";
  char *test_4 = "true\0fail";
  char *test_5 = "";

  ck_assert_str_eq(s21_memchr(test_1, '3', 5), memchr(test_1, '3', 5));
  ck_assert_pstr_eq(s21_memchr(test_1, '1', 2), memchr(test_1, '1', 2));
  ck_assert_pstr_eq(s21_memchr(test_1, 'e', 5), memchr(test_1, 'e', 5));

  ck_assert_str_eq(s21_memchr(test_2, ' ', 2), memchr(test_2, ' ', 2));
  ck_assert_pstr_eq(s21_memchr(test_2, 'k', 5), memchr(test_2, 'k', 5));

  ck_assert_str_eq(s21_memchr(test_3, 'a', 5), memchr(test_3, 'a', 5));
  ck_assert_pstr_eq(s21_memchr(test_3, 'g', 2), memchr(test_3, 'g', 2));
  ck_assert_pstr_eq(s21_memchr(test_3, 't', 5), memchr(test_3, 't', 5));

  ck_assert_pstr_eq(s21_memchr(test_4, '\0', 2), memchr(test_4, '\0', 2));
  ck_assert_str_eq(s21_memchr(test_4, '\0', 6), memchr(test_4, '\0', 6));
  ck_assert_str_eq(s21_memchr(test_4, 'i', 8), memchr(test_4, 'i', 8));
  ck_assert_pstr_eq(s21_memchr(test_4, 'y', 5), memchr(test_4, 'y', 5));

  ck_assert_pstr_eq(s21_memchr(test_5, '3', 5), memchr(test_5, '3', 5));
  ck_assert_pstr_eq(s21_memchr(test_5, '1', 2), memchr(test_5, '1', 2));
  ck_assert_pstr_eq(s21_memchr(test_5, 'e', 5), memchr(test_5, 'e', 5));
}
END_TEST

Suite *suite_s21_memchr() {
  Suite *s = suite_create("s21_memchr");
  TCase *temp = tcase_create("test_memchr");

  suite_add_tcase(s, temp);

  tcase_add_test(temp, s21_memchr_test);

  return s;
}
