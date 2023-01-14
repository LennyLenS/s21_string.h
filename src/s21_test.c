// Подключаем заголовочный файл библиотеки.
#include "s21_string.h"

// Функция тестирования какой-либо задачи.
START_TEST(exp1) {
  ck_assert_float_eq_tol(exp(0.), s21_exp(0.), 1E-6);
END_TEST


// Функция создания набора тестов.
Suite *example_suite_create(void)
{
    Suite *suite = suite_create("Main_suite");
    // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
    TCase *tcase_core = tcase_create("Main_case");
    
    // Добавление теста в группу тестов.
    tcase_add_test(tcase_core, exp1);
    
    // Добавление теста в тестовый набор.
    suite_add_tcase(suite, tcase_core);
    
    return suite;
}

int main(void)
{
    Suite *suite = example_suite_create();
    SRunner *suite_runner = srunner_create(suite);
    
    srunner_run_all(suite_runner, CK_NORMAL);
    // Получаем количество проваленных тестов.
    int failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);
    
    // Сигнализируем о том, что тестирование прошло удачно или неудачно.
    return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
