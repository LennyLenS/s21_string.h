#ifndef SRC_TESTS_ME_H
#define SRC_TESTS_ME_H

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "../s21_sscanf.h"


Suite *test_sscanf_c(void);
Suite *test_sscanf_d(void);
Suite *test_sscanf_pr(void);
Suite *test_sscanf_n(void);
Suite *test_sscanf_empty(void);

// Suite *test_sscanf_i(void);
// Suite *test_sscanf_o(void);
// Suite *test_sscanf_x(void);
// Suite *test_sscanf_real(void);


#endif  // SRC_TESTS_ME_H
