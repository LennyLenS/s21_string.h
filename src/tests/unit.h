#ifndef SRC_TESTS_UNIT_H
#define SRC_TESTS_UNIT_H

#include <check.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_string_files/s21_string.h"

Suite *suite_s21_memchr();
Suite *suite_s21_memcmp();
Suite *suite_s21_memmove();
Suite *suite_s21_memset();
#endif  //  SRC_TESTS_UNIT_H
