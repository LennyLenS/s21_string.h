#ifndef SRC_TESTS_UNIT_H
#define SRC_TESTS_UNIT_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string_files/s21_string.h"

Suite *suite_s21_memchr();
Suite *suite_s21_memcmp();
Suite *suite_s21_memmove();
Suite *suite_s21_memset();
Suite *suite_s21_strlen();
Suite *suite_s21_strncat();
Suite *suite_s21_strchr();
Suite *suite_s21_strpbrk();
Suite *example_suite_create();
Suite *arn_test();
#endif  //  SRC_TESTS_UNIT_H
