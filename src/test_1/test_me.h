#ifndef SRC_TESTS_ME_H
#define SRC_TESTS_ME_H

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "../s21_string_files/s21_string.h"

Suite *test_memchr(void);
Suite *test_memcmp(void);
Suite *test_memcpy(void);
Suite *test_memmove(void);
Suite *test_memset(void);
Suite *test_strcat(void);
Suite *test_strncat(void);
Suite *test_strchr(void);
Suite *test_strcmp(void);
Suite *test_strncmp(void);
Suite *test_strcpy(void);
Suite *test_strncpy(void);
Suite *test_strcspn(void);
Suite *test_strerror(void);
Suite *test_strlen(void);
Suite *test_strpbrk(void);
Suite *test_strrchr(void);
Suite *test_strspn(void);
Suite *test_strstr(void);
Suite *test_strtok(void);

#endif  // SRC_TESTS_ME_H