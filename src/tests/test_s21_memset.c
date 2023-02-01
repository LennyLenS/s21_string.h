#include "unit.h"

START_TEST(s21_memset_test) {
  char *res = (char *)malloc(20);
  char *res_2 = (char *)malloc(20);
  ck_assert_mem_eq(s21_memset(res, '0', 2), memset(res_2, '0', 2), 2);
  free(res);
  free(res_2);

  res = (char *)malloc(20);
  res_2 = (char *)malloc(20);
  ck_assert_mem_eq(s21_memset(res, '\0', 2), memset(res_2, '\0', 2), 2);
  free(res);
  free(res_2);

  res = (char *)malloc(20);
  res_2 = (char *)malloc(20);
  ck_assert_mem_eq(s21_memset(res, 'w', 15), memset(res_2, 'w', 15), 15);
  free(res);
  free(res_2);

  res = (char *)malloc(20);
  res_2 = (char *)malloc(20);
  ck_assert_mem_eq(s21_memset(res, 'D', 1), memset(res_2, 'D', 1), 1);
  free(res);
  free(res_2);

  res = (char *)malloc(20);
  res_2 = (char *)malloc(20);
  ck_assert_mem_eq(s21_memset(res, '5', 2), memset(res_2, '5', 2), 2);
  free(res);
  free(res_2);
}
END_TEST

Suite *suite_s21_memset() {
  Suite *s = suite_create("s21_memset");
  TCase *temp = tcase_create("test_memset");

  suite_add_tcase(s, temp);

  tcase_add_test(temp, s21_memset_test);

  return s;
}
