#include "test_me.h"

int main(void) {
  int failed = 0;
  Suite *s21_string_test[] = {
                              test_sscanf_empty(),
                              test_sscanf_c(),
                              test_sscanf_d(),
                              test_sscanf_pr(),
                              test_sscanf_n(),

                              // test_sscanf_i(),
                              // test_sscanf_o(),
                              // test_sscanf_x(),
                              // test_sscanf_real(),
                              NULL};

  for (int i = 0; s21_string_test[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *sr = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}