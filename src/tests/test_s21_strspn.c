#include "unit.h"

START_TEST(s21_strspn_test) {
  char *test_1 = "123456";
  char *test_2 = "      ";
  char *test_3 = "asdfg\1asdft";
  char *test_4 = "true\0fail";
  char *test_5 = "";
  char *test_6 = "ttt\0\0\0\0";
  char *test_7 = "\0";

  ck_assert_int_eq(s21_strspn(test_1, "123"), strspn(test_1, "123"));
  ck_assert_int_eq(s21_strspn(test_1, "456"), strspn(test_1, "456"));
  ck_assert_int_eq(s21_strspn(test_1, "321"), strspn(test_1, "321"));
  ck_assert_int_eq(s21_strspn(test_1, "dfsfdsf"), strspn(test_1, "dfsfdsf"));

  ck_assert_int_eq(s21_strspn(test_2, "123"), strspn(test_2, "123"));
  ck_assert_int_eq(s21_strspn(test_2, "    "), strspn(test_2, "    "));
  ck_assert_int_eq(s21_strspn(test_2, "asdf"), strspn(test_2, "asdf"));
  ck_assert_int_eq(s21_strspn(test_2, " \0"), strspn(test_2, " \0"));

  ck_assert_int_eq(s21_strspn(test_3, "asdfg\1asdft"), strspn(test_3, "asdfg\1asdft"));
  ck_assert_int_eq(s21_strspn(test_3, "a\1"), strspn(test_3, "a\1"));
  ck_assert_int_eq(s21_strspn(test_3, "asdf\1"), strspn(test_3, "asdf\1"));
  ck_assert_int_eq(s21_strspn(test_3, " \0"), strspn(test_3, " \0"));

  ck_assert_int_eq(s21_strspn(test_4, "urte"), strspn(test_4, "urte"));
  ck_assert_int_eq(s21_strspn(test_4, "a\1"), strspn(test_4, "a\1"));
  ck_assert_int_eq(s21_strspn(test_4, "fail"), strspn(test_4, "fail"));
  ck_assert_int_eq(s21_strspn(test_4, "true\0fa"), strspn(test_4, "true\0fa"));

  ck_assert_int_eq(s21_strspn(test_5, "asdfg\1asdft"), strspn(test_5, "asdf\1asdft"));
  ck_assert_int_eq(s21_strspn(test_5, " "), strspn(test_5, " "));
  ck_assert_int_eq(s21_strspn(test_5, " \0"), strspn(test_5, " \0"));

  ck_assert_int_eq(s21_strspn(test_6, "asdfg\1asdft"), strspn(test_6, "asdf\1asdft"));
  ck_assert_int_eq(s21_strspn(test_6, "ttt"), strspn(test_6, "ttt"));
  ck_assert_int_eq(s21_strspn(test_6, "t\0"), strspn(test_6, "t\0"));
  ck_assert_int_eq(s21_strspn(test_6, "t"), strspn(test_6, "t"));

  ck_assert_int_eq(s21_strspn(test_7, "asdfg\1asdft"), strspn(test_7, "asdf\1asdft"));
  ck_assert_int_eq(s21_strspn(test_7, " "), strspn(test_7, " "));
  ck_assert_int_eq(s21_strspn(test_7, "\0"), strspn(test_7, "\0"));
}
END_TEST

Suite *suite_s21_strspn() {
  Suite *s = suite_create("s21_strspn");
  TCase *temp = tcase_create("test_strspn");

  suite_add_tcase(s, temp);

  tcase_add_test(temp, s21_strspn_test);

  return s;
}
