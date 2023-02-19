#include "unit.h"

START_TEST(s21_strchr_test) {
  char *test_1 = "123456";
  char *test_2 = "      ";
  char *test_3 = "asdfg\1asdft";
  char *test_4 = "true\0fail";
  char *test_5 = "";
  char *test_6 = "ttt\0\0\0\0";
  char *test_7 = "\0";

  ck_assert_str_eq(s21_strchr(test_1, '5'), strchr(test_1, '5'));
  ck_assert_str_eq(s21_strchr(test_2, ' '), strchr(test_2, ' '));
  ck_assert_str_eq(s21_strchr(test_3, 'a'), strchr(test_3, 'a'));
  ck_assert_str_eq(s21_strchr(test_4, 'u'), strchr(test_4, 'u'));
  ck_assert_str_eq(s21_strchr(test_5, '\0'), strchr(test_5, '\0'));
  ck_assert_str_eq(s21_strchr(test_6, 't'), strchr(test_6, 't'));
  ck_assert_str_eq(s21_strchr(test_7, '\0'), strchr(test_7, '\0'));

  ck_assert_pstr_eq(s21_strchr(test_1, '8'), strchr(test_1, '8'));
  ck_assert_pstr_eq(s21_strchr(test_2, '2'), strchr(test_2, '2'));
  ck_assert_pstr_eq(s21_strchr(test_3, '\1'), strchr(test_3, '\1'));
  ck_assert_pstr_eq(s21_strchr(test_4, 'f'), strchr(test_4, 'f'));
  ck_assert_pstr_eq(s21_strchr(test_5, 'y'), strchr(test_5, 'y'));
  ck_assert_pstr_eq(s21_strchr(test_6, 'r'), strchr(test_6, 'r'));
  ck_assert_pstr_eq(s21_strchr(test_7, 'e'), strchr(test_7, 'e'));
}
END_TEST

Suite *suite_s21_strchr() {
  Suite *s = suite_create("s21_strchr");
  TCase *temp = tcase_create("test_strchr");

  suite_add_tcase(s, temp);

  tcase_add_test(temp, s21_strchr_test);

  return s;
}
