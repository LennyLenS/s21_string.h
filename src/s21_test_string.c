// Подключаем заголовочный файл библиотеки.
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

// Функция тестирования какой-либо задачи.
START_TEST(strlen1) {
  char *str = "123456789";
  ck_assert_int_eq(s21_strlen(str), strlen(str));

  str = "qwerty";
  ck_assert_int_eq(s21_strlen(str), strlen(str));

  str = "";
  ck_assert_int_eq(s21_strlen(str), strlen(str));

  str = "qwe rty";
  ck_assert_int_eq(s21_strlen(str), strlen(str));


  str = " qwe rty ";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strcat1) {
  char str1[50] = "World is fun!";
  char str2[50] = "World is fun!";
  char *str3 = "";
  ck_assert_pstr_eq(s21_strcat(str1, str3), strcat(str2, str3));
}
END_TEST

START_TEST(strcat2) {
  char str1[50] = "World is fun!";
  char str2[50] = "World is fun!";
  char *str3 = "Good";
  ck_assert_pstr_eq(s21_strcat(str1, str3), strcat(str2, str3));
}
END_TEST

START_TEST(strcat3) {
  char str1[50] = "World ";
  char str2[50] = "World ";
  char *str3 = "3243242348909284370";
  ck_assert_pstr_eq(s21_strcat(str1, str3), strcat(str2, str3));
}
END_TEST

START_TEST(strcat4) {
  char str1[50] = "World is fun! rowituoiuhguhtiuhgoooeritj";
  char str2[50] = "World is fun! rowituoiuhguhtiuhgoooeritj";
  char *str3 = "ad";
  ck_assert_pstr_eq(s21_strcat(str1, str3), strcat(str2, str3));
}
END_TEST

START_TEST(strcat5) {
  char str1[50] = "   ";
  char str2[50] = "   ";
  char *str3 = "  ";
  ck_assert_pstr_eq(s21_strcat(str1, str3), strcat(str2, str3));
}
END_TEST

START_TEST(strcat6) {
  char str1[50] = "";
  char str2[50] = "";
  char *str3 = "123";
  ck_assert_pstr_eq(s21_strcat(str1, str3), strcat(str2, str3));
}
END_TEST

START_TEST(strcat7) {
  char str1[50] = "";
  char str2[50] = "";
  char *str3 = "";
  ck_assert_pstr_eq(s21_strcat(str1, str3), strcat(str2, str3));
}
END_TEST

START_TEST(strstr0) {
  char str1[50] = "abcdefghijklmnopqrstuvwxyz";
  char str2[50] = "bcd";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr1) {
  char str1[50] = "abcdefghijklmnopqrstuvwxyz";
  char str2[50] = "fvg";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr2) {
  char str1[50] = "abcdefghijklmnopqrstuvwxyz";
  char str2[50] = "abcdefghijklmnopqrstuvwxyz";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr3) {
  char str1[50] = "abcdefghijklmnopqrstuvwxyz";
  char str2[50] = "";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr4) {
  char str1[50] = "abcdefghijklmnopqrstuvwxyz";
  char str2[50] = "3456";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr5) {
  char str1[50] = "";
  char str2[50] = "";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr6) {
  char str1[50] = "abcdefghijklmnopqrstuvwxyz";
  char str2[50] = "";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr7) {
  char str1[50] = "";
  char str2[50] = "abcdefghijklmnopqrstuvwxyz";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr8) {
  char str1[50] = "abcdefghijklmnopqrstuvwxyz";
  char str2[50] = "\0";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr9) {
  char str1[50] = "abcdefghijklmnopqrstuvwxyz";
  char str2[50] = "z";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr10) {
  char str1[50] = "3%2566#7658/";
  char str2[50] = "%25";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr11) {
  char str1[50] = "32566#7658/";
  char str2[50] = "/";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strtok1) {
  char str1[50] = "";
  char str2[50] = "";
  char *sep = "";
  ck_assert_pstr_eq(s21_strtok(str1, sep), strtok(str2, sep));
}
END_TEST

START_TEST(strtok2) {
  char str1[50] = "//$/test1//te@st2/test3//sd";
  char str2[50] = "//$/test1//te@st2/test3//sd";
  char *sep = "@2";
  ck_assert_pstr_eq(s21_strtok(str1, sep), strtok(str2, sep));
}
END_TEST

START_TEST(strtok3) {
  char str1[50] = "//$/test1//te@st2/test3//sd";
  char str2[50] = "//$/test1//te@st2/test3//sd";
  char *sep = "";
  ck_assert_pstr_eq(s21_strtok(str1, sep), strtok(str2, sep));
}
END_TEST

START_TEST(strtok4) {
  char str1[50] = "";
  char str2[50] = "";
  char *sep = "@2";
  ck_assert_pstr_eq(s21_strtok(str1, sep), strtok(str2, sep));
}
END_TEST

START_TEST(strtok5) {
  char str1[50] = "//$/test1//te@st2/test3//sd";
  char str2[50] = "//$/test1//te@st2/test3//sd";
  char *sep = "q.w";
  ck_assert_pstr_eq(s21_strtok(str1, sep), strtok(str2, sep));
}
END_TEST

START_TEST(strtok6) {
  char str1[50] = "//$/test1//te@st2/test3//sd";
  char str2[50] = "//$/test1//te@st2/test3//sd";
  char *sep = "//";
  ck_assert_pstr_eq(s21_strtok(str1, sep), strtok(str2, sep));
}
END_TEST

START_TEST(strtok7) {
  char str1[50] = "//$/test1//te@st2/test3//sd";
  char str2[50] = "//$/test1//te@st2/test3//sd";
  char *sep = "/";
  ck_assert_pstr_eq(s21_strtok(str1, sep), strtok(str2, sep));
  for(int i = 0; i < 5; i++){
    ck_assert_pstr_eq(s21_strtok(NULL, sep), strtok(NULL, sep));
  };
}
END_TEST

START_TEST(strtok8) {
  char *str1 = S21_NULL;
  char *str2 = S21_NULL;
  char *sep = "";
  ck_assert_pstr_eq(s21_strtok(str1, sep), strtok(str2, sep));
}
END_TEST

START_TEST(memcpy1) {
  char str1[50] = "";
  char str2[50] = "";
  char *str3 = "Hello!";
  ck_assert_mem_eq(s21_memcpy(str1, str3, 7), memcpy(str2, str3, 7), 7);
}
END_TEST

START_TEST(memcpy2) {
  char str1[50] = "Hello";
  char str2[50] = "Hello";
  char *str3 = "world";
  ck_assert_mem_eq(s21_memcpy(str1, str3, 6), memcpy(str2, str3, 6), 6);
}
END_TEST

START_TEST(memcpy3) {
  char str1[50] = "";
  char str2[50] = "";
  char *str3 = "";
  ck_assert_mem_eq(s21_memcpy(str1, str3, 1), memcpy(str2, str3, 1), 1);
}
END_TEST

START_TEST(memcpy4) {
  char str1[50] = "werfgwrg";
  char str2[50] = "werfgwrg";
  char *str3 = "Hel\0lo!";
  ck_assert_mem_eq(s21_memcpy(str1, str3, 7), memcpy(str2, str3, 7), 7);
}
END_TEST

START_TEST(memcpy5) {
  char str1[50] = "";
  char str2[50] = "";
  char *str3 = "";
  ck_assert_mem_eq(s21_memcpy(str1, str3, 1), memcpy(str2, str3, 1), 1);
}
END_TEST

START_TEST(memcpy6) {
  char str1[50] = "oreijgoie";
  char str2[50] = "oreijgoie";
  char *str3 = "934875770928357009284579";
  ck_assert_mem_eq(s21_memcpy(str1, str3, 16), memcpy(str2, str3, 16), 16);

}
END_TEST

START_TEST(strspn1) {
  char str1[50] = "oreijgoie";
  char str2[50] = "ore";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(strspn2) {
  char str1[50] = "oreijgoie";
  char str2[50] = "ero";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(strspn3) {
  char str1[50] = "oreijgoie";
  char str2[50] = "";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(strspn4) {
  char str1[50] = "";
  char str2[50] = "ore";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(strspn5) {
  char str1[50] = "oreijgoie";
  char str2[50] = "jgo";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(strspn6) {
  char str1[50] = "ore ijgoie";
  char str2[50] = "ore ";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(strspn7) {
  char str1[50] = "/ oreijgoie";
  char str2[50] = "/ or";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(strspn8) {
  char str1[50] = "24634673658346";
  char str2[50] = "246346";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(strspn9) {
  char str1[50] = "24634673658346";
  char str2[50] = "0000";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(to_upper1) {
  char *str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz 01234567890 *-+/=";
  char *str2 = s21_to_upper(str);
  ck_assert_str_eq(str2, "ABCDEFGHIJKLMNOPQRSTUVWXYZ ABCDEFGHIJKLMNOPQRSTUVWXYZ 01234567890 *-+/=");
  free(str2);
}
END_TEST

START_TEST(to_lower1) {
  char *str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz 01234567890 *-+/=";
  char *str2 = s21_to_lower(str);
  ck_assert_str_eq(str2, "abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz 01234567890 *-+/=");
  free(str2);
}
END_TEST

START_TEST(insert1) {
  char *src = "abcdef";
  char *str = "8888";
  char *str2 = NULL;
  char *src2 = NULL;
  char *src3 = "";
  char *str3 = "";

  char *res = s21_insert(src, str, 3);
  ck_assert_str_eq(res, "abc8888def");
  free(res);

  res = s21_insert(src, str, 6);
  ck_assert_str_eq(res, "abcdef8888");
  free(res);

  res = s21_insert(src, str, 0);
  ck_assert_str_eq(res, "8888abcdef");
  free(res);

  res = s21_insert(src3, str, 0);
  ck_assert_str_eq(res, "8888");
  free(res);

  res = s21_insert(src, str3, 3);
  ck_assert_str_eq(res, "abcdef");
  free(res);

  res = s21_insert(src, str2, 3);
  ck_assert_ptr_null(res);
  free(res);

  res = s21_insert(src2, str, 3);
  ck_assert_ptr_null(res);
  free(res);

  res = s21_insert(src, str, -3);
  ck_assert_ptr_null(res);
  free(res);

  res = s21_insert(src, str, 23);
  ck_assert_ptr_null(res);
  free(res);

  res = s21_insert(src2, str, 3);
  ck_assert_ptr_null(res);
  free(res);

}
END_TEST

START_TEST(test_trim_1) {
  char s1[30] = "-?hello, world!";
  char s3[] = "!?-";
  char s4[] = "hello, world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  free(s2);
}
END_TEST

START_TEST(test_trim_2) {
  char s1[30] = "";
  char s3[] = "";
  char *s4 = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  free(s2);
}
END_TEST

START_TEST(test_trim_3) {
  char *s1 = S21_NULL;
  char s3[] = "";
  char *s4 = S21_NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  free(s2);
}
END_TEST

START_TEST(test_trim_4) {
  char s1[30] = "!!!abcdefghij!?!";
  char s3[] = "!?";
  char s4[] = "abcdefghij";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  free(s2);
}
END_TEST

START_TEST(test_trim_5) {
  char s1[30] = "abc";
  char s3[] = "333";
  char *s4 = "abc";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  free(s2);
}
END_TEST

START_TEST(test_trim_6) {
  char s1[30] = "hello, world!";
  char s3[] = "?h !";
  char *s4 = "ello, world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  free(s2);
}
END_TEST

START_TEST(test_trim_7) {
  char *s1 = S21_NULL;
  char *s3 = S21_NULL;
  char *s4 = S21_NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  free(s2);
}
END_TEST

START_TEST(test_trim_8) {
  char s1[30] = "";
  char s3[] = "";
  char s4[] = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  free(s2);
}
END_TEST

START_TEST(test_trim_9) {
  char s1[] = " wtf ";
  char *s3 = S21_NULL;
  char *s4 = "wtf";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  free(s2);
}
END_TEST

START_TEST(test_trim_10) {
  char s1[] = " wtf ";
  char *s3 = "";
  char *s4 = "wtf";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  free(s2);
}
END_TEST

START_TEST(test_trim_11) {
  char s1[30] = "abcdefghij!?!";
  char s3[] = "!?j";
  char s4[] = "abcdefghi";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  free(s2);
}
END_TEST



// Функция создания набора тестов.
Suite *example_suite_create(void)
{
    Suite *suite = suite_create("Main_suite");
    // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
    TCase *tcase_core = tcase_create("Main_case");
    
    // Добавление теста в группу тестов.
    tcase_add_test(tcase_core, strlen1);

    tcase_add_test(tcase_core, strcat1);
    tcase_add_test(tcase_core, strcat2);
    tcase_add_test(tcase_core, strcat3);
    tcase_add_test(tcase_core, strcat4);
    tcase_add_test(tcase_core, strcat5);
    tcase_add_test(tcase_core, strcat6);
    tcase_add_test(tcase_core, strcat7);

    tcase_add_test(tcase_core, strstr0);
    tcase_add_test(tcase_core, strstr1);
    tcase_add_test(tcase_core, strstr2);
    tcase_add_test(tcase_core, strstr3);
    tcase_add_test(tcase_core, strstr4);
    tcase_add_test(tcase_core, strstr5);
    tcase_add_test(tcase_core, strstr6);
    tcase_add_test(tcase_core, strstr7);
    tcase_add_test(tcase_core, strstr8);
    tcase_add_test(tcase_core, strstr9);
    tcase_add_test(tcase_core, strstr10);
    tcase_add_test(tcase_core, strstr11);

    tcase_add_test(tcase_core, strtok1);
    tcase_add_test(tcase_core, strtok2);
    tcase_add_test(tcase_core, strtok3);
    tcase_add_test(tcase_core, strtok4);
    tcase_add_test(tcase_core, strtok5);
    tcase_add_test(tcase_core, strtok6);
    tcase_add_test(tcase_core, strtok7);
    tcase_add_test(tcase_core, strtok8);

    tcase_add_test(tcase_core, memcpy1);
    tcase_add_test(tcase_core, memcpy2);
    tcase_add_test(tcase_core, memcpy3);
    tcase_add_test(tcase_core, memcpy4);
    tcase_add_test(tcase_core, memcpy5);
    tcase_add_test(tcase_core, memcpy6);

    tcase_add_test(tcase_core, strspn1);
    tcase_add_test(tcase_core, strspn2);
    tcase_add_test(tcase_core, strspn3);
    tcase_add_test(tcase_core, strspn4);
    tcase_add_test(tcase_core, strspn5);
    tcase_add_test(tcase_core, strspn6);
    tcase_add_test(tcase_core, strspn7);
    tcase_add_test(tcase_core, strspn8);
    tcase_add_test(tcase_core, strspn9);

    tcase_add_test(tcase_core, to_upper1);

    tcase_add_test(tcase_core, to_lower1);

    tcase_add_test(tcase_core, insert1);

    tcase_add_test(tcase_core, test_trim_1);
    tcase_add_test(tcase_core, test_trim_2);
    tcase_add_test(tcase_core, test_trim_3);
    tcase_add_test(tcase_core, test_trim_4);
    tcase_add_test(tcase_core, test_trim_5);
    tcase_add_test(tcase_core, test_trim_6);
    tcase_add_test(tcase_core, test_trim_7);
    tcase_add_test(tcase_core, test_trim_8);
    tcase_add_test(tcase_core, test_trim_9);
    tcase_add_test(tcase_core, test_trim_10);
    tcase_add_test(tcase_core, test_trim_11);
    
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
