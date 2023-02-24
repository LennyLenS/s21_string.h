#include "unit.h"

START_TEST(s21_strrchr_test) {
  char *test_1 = "123456";
  char *test_2 = "      ";
  char *test_3 = "asdfg\1asdft";
  char *test_4 = "true\0fail";
  char *test_5 = "";
  char *test_6 = "ttt\0\0\0\0";
  char *test_7 = "\0";

  ck_assert_pstr_eq(s21_strrchr(test_1, '1'), strrchr(test_1, '1'));
  ck_assert_pstr_eq(s21_strrchr(test_1, '0'), strrchr(test_1, '0'));
  ck_assert_pstr_eq(s21_strrchr(test_1, '6'), strrchr(test_1, '6'));
  ck_assert_pstr_eq(s21_strrchr(test_1, '4'), strrchr(test_1, '4'));


  ck_assert_pstr_eq(s21_strrchr(test_2, ' '), strrchr(test_2, ' '));
  ck_assert_pstr_eq(s21_strrchr(test_2, 't'), strrchr(test_2, 't'));
  ck_assert_pstr_eq(s21_strrchr(test_2, '\t'), strrchr(test_2, '\t'));
  ck_assert_pstr_eq(s21_strrchr(test_2, '\0'), strrchr(test_2, '\0'));

  ck_assert_pstr_eq(s21_strrchr(test_3, 'f'), strrchr(test_3, 'f'));
  ck_assert_pstr_eq(s21_strrchr(test_3, 't'), strrchr(test_3, 't'));
  ck_assert_pstr_eq(s21_strrchr(test_3, 'a'), strrchr(test_3, 'a'));
  ck_assert_pstr_eq(s21_strrchr(test_3, '1'), strrchr(test_3, '1'));

  ck_assert_pstr_eq(s21_strrchr(test_4, 't'), strrchr(test_4, 't'));
  ck_assert_pstr_eq(s21_strrchr(test_4, 'f'), strrchr(test_4, 'f'));
  ck_assert_pstr_eq(s21_strrchr(test_4, '\0'), strrchr(test_4, '\0'));
  ck_assert_pstr_eq(s21_strrchr(test_4, 'i'), strrchr(test_4, 'i'));

  ck_assert_pstr_eq(s21_strrchr(test_5, '1'), strrchr(test_5, '1'));
  ck_assert_pstr_eq(s21_strrchr(test_5, ' '), strrchr(test_5, ' '));
  ck_assert_pstr_eq(s21_strrchr(test_5, '\0'), strrchr(test_5, '\0'));
  ck_assert_pstr_eq(s21_strrchr(test_5, '8'), strrchr(test_5, '8'));

  ck_assert_pstr_eq(s21_strrchr(test_6, 't'), strrchr(test_6, 't'));
  ck_assert_pstr_eq(s21_strrchr(test_6, '\t'), strrchr(test_6, '\t'));
  ck_assert_pstr_eq(s21_strrchr(test_6, 'e'), strrchr(test_6, 'e'));
  ck_assert_pstr_eq(s21_strrchr(test_6, 'r'), strrchr(test_6, 'r'));

  ck_assert_pstr_eq(s21_strrchr(test_7, '1'), strrchr(test_7, '1'));
  ck_assert_pstr_eq(s21_strrchr(test_7, '\0'), strrchr(test_7, '\0'));
  ck_assert_pstr_eq(s21_strrchr(test_7, '0'), strrchr(test_7, '0'));
  ck_assert_pstr_eq(s21_strrchr(test_7, '4'), strrchr(test_7, '4'));
}
END_TEST

Suite *suite_s21_strrchr() {
  Suite *s = suite_create("s21_strrchr");
  TCase *temp = tcase_create("test_strrchr");

  suite_add_tcase(s, temp);

  tcase_add_test(temp, s21_strrchr_test);

  return s;
}
