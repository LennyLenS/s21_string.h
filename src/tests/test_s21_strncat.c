#include "unit.h"

START_TEST(s21_strncat_test) {
  char *test_1 = "123456";
  char *test_2 = "      ";
  char *test_3 = "asdfg\1asdft";
  char *test_4 = "true\0fail";
  char *test_5 = "";
  char *test_6 = "ttt\0\0\0\0";
  char *test_7 = "\0";

  char buff[1024], buff2[1024];
  buff[0] = '\0';
  buff2[0] = '\0';
  ck_assert_str_eq(s21_strncat(buff, test_1, 1), strncat(buff2, test_1, 1));
  ck_assert_str_eq(s21_strncat(buff, test_2, 1), strncat(buff2, test_2, 1));
  ck_assert_str_eq(s21_strncat(buff, test_3, 1), strncat(buff2, test_3, 1));
  ck_assert_str_eq(s21_strncat(buff, test_4, 1), strncat(buff2, test_4, 1));
  ck_assert_str_eq(s21_strncat(buff, test_5, 1), strncat(buff2, test_5, 1));
  ck_assert_str_eq(s21_strncat(buff, test_6, 1), strncat(buff2, test_6, 1));
  ck_assert_str_eq(s21_strncat(buff, test_7, 1), strncat(buff2, test_7, 1));

  ck_assert_str_eq(s21_strncat(buff, test_1, 5), strncat(buff2, test_1, 5));
  ck_assert_str_eq(s21_strncat(buff, test_2, 5), strncat(buff2, test_2, 5));
  ck_assert_str_eq(s21_strncat(buff, test_3, 5), strncat(buff2, test_3, 5));
  ck_assert_str_eq(s21_strncat(buff, test_4, 5), strncat(buff2, test_4, 5));
  ck_assert_str_eq(s21_strncat(buff, test_5, 5), strncat(buff2, test_5, 5));
  ck_assert_str_eq(s21_strncat(buff, test_6, 5), strncat(buff2, test_6, 5));
  ck_assert_str_eq(s21_strncat(buff, test_7, 5), strncat(buff2, test_7, 5));

  ck_assert_str_eq(s21_strncat(buff, test_1, 9), strncat(buff2, test_1, 9));
  ck_assert_str_eq(s21_strncat(buff, test_2, 9), strncat(buff2, test_2, 9));
  ck_assert_str_eq(s21_strncat(buff, test_3, 9), strncat(buff2, test_3, 9));
  ck_assert_str_eq(s21_strncat(buff, test_4, 9), strncat(buff2, test_4, 9));
  ck_assert_str_eq(s21_strncat(buff, test_5, 9), strncat(buff2, test_5, 9));
  ck_assert_str_eq(s21_strncat(buff, test_6, 9), strncat(buff2, test_6, 9));
  ck_assert_str_eq(s21_strncat(buff, test_7, 9), strncat(buff2, test_7, 9));
}
END_TEST

Suite *suite_s21_strncat() {
  Suite *s = suite_create("s21_sttncat");
  TCase *temp = tcase_create("test_strncat");

  suite_add_tcase(s, temp);

  tcase_add_test(temp, s21_strncat_test);

  return s;
}
