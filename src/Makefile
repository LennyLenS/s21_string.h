FLAGS = -Wall -Werror -Wextra
all:

test:
	gcc $(FLAGS) -lcheck s21_test_string.c s21_string.c -o tests_string
	./tests_string
s21_string.a:

gcov_report: clean
	gcc --coverage s21_test_string.c s21_string.c $(FLAGS) -lcheck -o tests_string
	./tests_string
	lcov -t "tests_string" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html
clean:
	rm -rf *.o *.a a.out
	rm -rf tests_string
	rm -rf *.gcda *.gcno
	rm -rf test.info test report

rebuild: clean all
