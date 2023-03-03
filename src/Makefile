CC=gcc -std=c11 -D_GNU_SOURCE
CFLAGS=-c -Wall -Wextra -g
TEST_FLAGS=-lcheck -lm -lpthread
GCOV_FLAGS=--coverage -Wall -Wextra -Werror
SOURCES=$(wildcard s21_string_files/*.c)
OBJECTS=$(SOURCES:.c=.o)
TESTS_SOURCES=test_main.c $(wildcard tests/*.c)
TESTS_OBJECTS=$(TESTS_SOURCES:.c=.o)
SPRINTF_SOURCES=s21_sprintf.c s21_str_to_argc.c s21_read_format.c s21_flag_handler.c $(wildcard specificators/*.c)
SPRINTF_OBJECTS=$(SPRINTF_SOURCES:.c=.o)
EXECUTABLE=s21_string
TEST_SPRINTF=$(wildcard tests_not_our/*.c)
TEST_SPRINTF_OBJECTS=$(TEST_SPRINTF:.c=.o)


ifeq ($(shell uname -s),Linux)
	TEST_FLAGS += -lrt -lsubunit
endif

all: sprintf

$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

rebuild: clean all

s21_string.a: $(OBJECTS)
	ar -rc s21_string.a $(OBJECTS)
	ranlib s21_string.a

s21_sprintf.a: $(SPRINTF_OBJECTS)
	ar -rc s21_sprintf.a $(SPRINTF_OBJECTS)
	ranlib s21_sprintf.a
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
 
sprintf : $(SPRINTF_OBJECTS) s21_string.a test.c
	$(CC) $^ -o sprintf

sprintf_test: $(TEST_SPRINTF_OBJECTS) s21_sprintf.a s21_string.a
	$(CC) $^ -o test $(TEST_FLAGS)
	./test

gcov_report: $(TESTS_OBJECTS)
	$(CC) $(GCOV_FLAGS) $(TESTS_OBJECTS) $(SOURCES) $(TEST_FLAGS) -o test
	./test
	gcov *.gcno
	lcov -t "s21_string" -o s21_string.info -c -d . --rc lcov_branch_coverage=1
	genhtml -o report s21_string.info --rc lcov_branch_coverage=1
	open report/index.html
