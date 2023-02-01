<<<<<<< HEAD
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
	rm -rf $(OBJECTS) $(EXECUTABLE) $(TESTS_OBJECTS) s21_string.a *.gcov *.gcno *.gcda *.info report test

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
=======
CFILES = $(wildcard s21*.c)
OBJ = $(patsubst %.c, %.o, $(CFILES))
TARGET = s21_math
CHECK:=$(shell pkg-config --cflags --libs check)
FLAG_COV = --coverage
CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11 $(DEBUG)
S21_MATH=-L. s21_math.a
DEBUG =-g
#LEAK=-fsanitize=address
CTESTFLAGS=-lcheck -lm -lpthread $(LEAK) 
TEST = tests_functions.c  
LIBRARY = s21_string.a
COMPILE = sprintf.c


all: clean $(LIBRARY) test

#$(TARGET): s21_math.o
#	$(CC) s21_math.o -o $(TARGET)

compile : $(COMPILE)
	$(CC) $(CFLAGS) $(LEAK) $(COMPILE)

$(LIBRARY): s21_string.h $(CFILES)
	$(CC) $(CFLAGS) -c $(CFILES)
	ar rc $(LIBRARY) $(OBJ)
	ranlib $(LIBRARY)
	rm -f $(OBJ)

clean:
	rm -rf *.o *.a test *.gcda *.gcno *.info coverage *.dSYM *.out

style:
	clang-format -style=google -i *.c
	clang-format -style=google -i *.h
	clang-format -style=google -n *.c
	clang-format -style=google -n *.h

checkstyle:
	clang-format -style=google -n *.c
	clang-format -style=google -n *.h

		
gcov_report: $(LIBRARY)
	$(CC) $(FLAG_COV) $(CFLAGS) $(CTESTFLAGS) $(TEST) -o test $(CHECK) $(S21_MATH)
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o coverage test.info
	open coverage/index.html 

test: $(LIBRARY)
	checkmk tests.check > tests_functions.c
	checkmk clean_mode=1 tests.check > tests_functions.c
	$(CC) $(CTESTFLAGS) $(TEST) $(LIBRARY) -o test
	./test

rebuild:
	make clean
	make
>>>>>>> arnoldrh
