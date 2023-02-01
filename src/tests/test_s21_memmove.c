#include "unit.h"

START_TEST(s21_memmove_test) {
	char *test_1 = "123456";
	char *test_2 = "      ";
	char *test_3 = "asdfg\1asdft";
	char *test_4 = "true\0fail";
	char *test_5 = "";

  char *res = (char *)malloc(20);
  char *res_2 = (char *)malloc(20);
  ck_assert_mem_eq(s21_memmove(res, test_1, 5), memmove(res_2, test_1, 5), 5);
  free(res);
  free(res_2);
  res = (char *)malloc(20);
  res_2 = (char *)malloc(20);

  ck_assert_mem_eq(s21_memmove(res, test_1, 1), memmove(res_2, test_1, 1), 1);

  free(res);
  free(res_2);
  res = (char *)malloc(20);
  res_2 = (char *)malloc(20);
  ck_assert_mem_eq(s21_memmove(res, test_2, 3), memmove(res_2, test_2, 3), 3);
  
  free(res);
  free(res_2);
  res = (char *)malloc(20);
  res_2 = (char *)malloc(20);
  ck_assert_mem_eq(s21_memmove(res, test_2, 4), memmove(res_2, test_2, 4), 4);
  
  free(res);
  free(res_2);
  res = (char *)malloc(20);
  res_2 = (char *)malloc(20);
  ck_assert_mem_eq(s21_memmove(res, test_3, 7), memmove(res_2, test_3, 7), 7);
  
  free(res);
  free(res_2);
  res = (char *)malloc(20);
  res_2 = (char *)malloc(20);
  ck_assert_mem_eq(s21_memmove(res, test_3, 2), memmove(res_2, test_3, 2), 2);
  
  free(res);
  free(res_2);
  res = (char *)malloc(20);
  res_2 = (char *)malloc(20);
  ck_assert_mem_eq(s21_memmove(res, test_4, 7), memmove(res_2, test_4, 7), 7);
  
  free(res);
  free(res_2);
  res = (char *)malloc(20);
  res_2 = (char *)malloc(20);
  ck_assert_mem_eq(s21_memmove(res, test_4, 3), memmove(res_2, test_4, 3), 3);
  
  free(res);
  free(res_2);
  res = (char *)malloc(20);
  res_2 = (char *)malloc(20);
  ck_assert_mem_eq(s21_memmove(res, test_5, 0), memmove(res_2, test_5, 0), 0);

  free(res);
  free(res_2);
}
END_TEST

Suite *suite_s21_memmove() {
  Suite *s = suite_create("s21_memmove");
  TCase *temp = tcase_create("test_memmove");

  suite_add_tcase(s, temp);

  tcase_add_test(temp, s21_memmove_test);

  return s;
}
