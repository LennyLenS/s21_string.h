OS = $(shell uname)

ifeq ($(OS), Darwin)
	TEST_LIBS=-lcheck
else
	TEST_LIBS=-lcheck -pthread -lrt -lm -lsubunit
endif


FLAGS = -Wall -Werror -Wextra -g
all:

test:
	gcc $(FLAGS) -lcheck test_me.c test_strtok.c strtok.c -o tests_string
	#gcc $(FLAGS) $(TEST_LIBS) test_me.c strtok.c -o tests_string
	#gcc $(FLAGS) test_strtok.c s21_string.c -o tests_string $(TEST_LIBS)
	./tests_string
s21_string.a:

gcov_report: clean
	gcc --coverage s21_test_string.c s21_string.c $(FLAGS) -lcheck -o tests_string
	./tests_string
	lcov -t "tests_string" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

check: clean
	gcc $(FLAGS) -g s21_test_string.c s21_string.c -o tests_string $(TEST_LIBS)
	valgrind --leak-check=full --show-leak-kinds=definite,possible -s ./tests_string 

clean:
	rm -rf *.o *.a a.out
	rm -rf tests_string
	rm -rf *.gcda *.gcno
	rm -rf test.info test report

rebuild: clean all


# gcc -Wall -Werror -Wextra s21_test_string.c s21_string.c -o tests_string -lcheck -pthread -lrt -lm -lsubunit 
# valgrind --tool=memcheck --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./tests_string
# valgrind --leak-check=full --show-leak-kinds=all ./tests_string 

# -lsubunit -lrt -lm -lpthread