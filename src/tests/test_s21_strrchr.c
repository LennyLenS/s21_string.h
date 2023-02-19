#include "unit.h"

START_TEST(s21_strpbrk_test) {
  char *test_1 = "123456";
  char *test_2 = "      ";
  char *test_3 = "asdfg\1asdft";
  char *test_4 = "true\0fail";
  char *test_5 = "";
  char *test_6 = "ttt\0\0\0\0";
  char *test_7 = "\0";

  ck_assert_pstr_eq(s21_strpbrk(test_1, "123"), strpbrk(test_1, "123"));
  ck_assert_pstr_eq(s21_strpbrk(test_2, "232"), strpbrk(test_2, "232"));
  ck_assert_pstr_eq(s21_strpbrk(test_3, "\1"), strpbrk(test_3, "\1"));
  ck_assert_pstr_eq(s21_strpbrk(test_4, "fail"), strpbrk(test_4, "fail"));
  ck_assert_pstr_eq(s21_strpbrk(test_5, ""), strpbrk(test_5, ""));
  ck_assert_pstr_eq(s21_strpbrk(test_6, "\0"), strpbrk(test_6, "\0"));
  ck_assert_pstr_eq(s21_strpbrk(test_7, "\0"), strpbrk(test_7, "\0"));

  ck_assert_pstr_eq(s21_strpbrk(test_1, "987654"), strpbrk(test_1, "987654"));
  ck_assert_pstr_eq(s21_strpbrk(test_2, "33 "), strpbrk(test_2, "33 "));
  ck_assert_pstr_eq(s21_strpbrk(test_3, "rrfrr"), strpbrk(test_3, "rrfrr"));
  ck_assert_pstr_eq(s21_strpbrk(test_4, "rue"), strpbrk(test_4, "rue"));
  ck_assert_pstr_eq(s21_strpbrk(test_5, "456"), strpbrk(test_5, "456"));
  ck_assert_pstr_eq(s21_strpbrk(test_6, "8"), strpbrk(test_6, "8"));
  ck_assert_pstr_eq(s21_strpbrk(test_7, "7\0"), strpbrk(test_7, "7\0"));
}
END_TEST

Suite *suite_s21_strpbrk() {
  Suite *s = suite_create("s21_strpbrk");
  TCase *temp = tcase_create("test_strpbrk");

  suite_add_tcase(s, temp);

  tcase_add_test(temp, s21_strpbrk_test);

  return s;
}
