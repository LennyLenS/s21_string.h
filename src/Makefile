CC=gcc -std=c11 -D_GNU_SOURCE
CFLAGS=-c -Wall -Wextra -Werror
TEST_FLAGS=-lcheck -lm -lpthread
GCOV_FLAGS=--coverage -Wall -Wextra -Werror
SOURCES=s21_strlen.c s21_memmove.c s21_memcmp.c s21_memchr.c s21_memset.c
OBJECTS=$(SOURCES:.c=.o)
TESTS_SOURCES=test_main.c $(wildcard tests/*.c)
TESTS_OBJECTS=$(TESTS_SOURCES:.c=.o)
EXECUTABLE=s21_string

ifeq ($(shell uname -s),Linux)
	TEST_FLAGS += -lrt -lsubunit
endif

all: test

$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

rebuild: clean all

s21_string.a: $(OBJECTS)
	ar -rc s21_string.a $(OBJECTS)
	ranlib s21_string.a

style:
	clang-format -style=google -n s21_*.c ./tests/*.c
	clang-format -style=google -n s21_*.h ./tests/*.h

make_style:
	clang-format -style=google -i s21_*.c ./tests/*.c
	clang-format -style=google -i s21_*.h ./tests/*.h

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) $(TESTS_OBJECTS) s21_string.a *.gcov *.gcno *.gcda *.info report test *.o


test: $(TESTS_OBJECTS) s21_string.a
	$(CC) $^ -o test $(TEST_FLAGS)
	./test

gcov_report: $(TESTS_OBJECTS)
	$(CC) $(GCOV_FLAGS) $(TESTS_OBJECTS) $(SOURCES) $(TEST_FLAGS) -o test
	./test
	gcov *.gcno
	lcov -t "s21_string" -o s21_string.info -c -d . --rc lcov_branch_coverage=1
	genhtml -o report s21_string.info --rc lcov_branch_coverage=1
	open report/index.html
