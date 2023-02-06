#include "unit.h"

START_TEST(s21_strlen_test) {
  char *test_1 = "123456";
  char *test_2 = "      ";
  char *test_3 = "asdfg\1asdft";
  char *test_4 = "true\0fail";
  char *test_5 = "";
  char *test_6 = "ttt\0\0\0\0";
  char *test_7 = "\0";


  ck_assert_int_eq(s21_strlen(test_1), strlen(test_1));
  ck_assert_int_eq(s21_strlen(test_2), strlen(test_2));
  ck_assert_int_eq(s21_strlen(test_3), strlen(test_3));
  ck_assert_int_eq(s21_strlen(test_4), strlen(test_4));
  ck_assert_int_eq(s21_strlen(test_5), strlen(test_5));
  ck_assert_int_eq(s21_strlen(test_6), strlen(test_6));
  ck_assert_int_eq(s21_strlen(test_7), strlen(test_7));
}
END_TEST

Suite *suite_s21_strlen() {
  Suite *s = suite_create("s21_strlen");
  TCase *temp = tcase_create("test_strlen");

  suite_add_tcase(s, temp);

  tcase_add_test(temp, s21_strlen_test);

  return s;
}
