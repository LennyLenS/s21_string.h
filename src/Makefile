CFILES = $(wildcard s21*.c)
OBJ = $(patsubst %.c, %.o, $(CFILES))
TARGET = s21_math
CHECK:=$(shell pkg-config --cflags --libs check)
FLAG_COV = --coverage
CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11 $(DEBUG)
S21_MATH=-L. s21_math.a
DEBUG =-g
LEAK=-fsanitize=address
CTESTFLAGS=-lcheck -lm -lpthread $(LEAK) 
TEST = tests_functions.c
LIBRARY = s21_string.a
COMPILE = s21_strcmp.c


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
	rm -rf *.o *.a test *.gcda *.gcno *.info coverage *.dSYM tests_functions.c

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
