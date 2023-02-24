<<<<<<< HEAD
CC=gcc -std=c11 -D_GNU_SOURCE
CFLAGS=-c -Wall -Wextra -Werror
TEST_FLAGS=-lcheck -lm -lpthread
GCOV_FLAGS=--coverage -Wall -Wextra -Werror
SOURCES=s21_string_files/*.c
OBJECTS=*.o
TESTS_SOURCES=test_me.c $(wildcard test_1/*.c)
TESTS_OBJECTS=$(TESTS_SOURCES:.c=.o)
EXECUTABLE=s21_string
LIBRARY = s21_string.a
=======
CFILES = $(wildcard s21*.c)
OBJ = $(patsubst %.c, %.o, $(CFILES))
#SPRINTF = s21_sprintf
TARGET = s21_string
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
COMPILE = $(CFILES)
>>>>>>> origin/arnoldrh

ifeq ($(shell uname -s),Linux)
	TEST_FLAGS += -lrt -lsubunit
endif

<<<<<<< HEAD
all: test

$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
=======
all: clean compile

compile : $(COMPILE)
	bash Obj_Files_String.sh
	$(CC) $(CFLAGS) $(LEAK) -c $(CFILES)
	$(CC) $(CFLAGS) $(LEAK) s21*.o -o $(TARGET)
	./$(TARGET)
# compile : $(COMPILE)
# 	$(CC) $(CFLAGS) $(LEAK) -c $(COMPILE)
# 	$(CC) $(OBJ) -o $(TARGET)
# 	./$(TARGET)
>>>>>>> origin/arnoldrh

rebuild: clean all

<<<<<<< HEAD

$(LIBRARY): s21_string_files/s21_string.h $(SOURCES)
	$(CC) $(CFLAGS) -c $(SOURCES)
	ar -rc s21_string.a $(OBJECTS)
	ranlib s21_string.a
=======
clean:
	rm -rf *.o *.a test *.gcda *.gcno *.info coverage
>>>>>>> origin/arnoldrh

style:
	clang-format -style=google -n s21_*.c ./tests/*.c ./s21_string_files/*.c
	clang-format -style=google -n s21_*.h ./tests/*.h ./s21_string_files/*.h

make_style:
	clang-format -style=google -i s21_*.c ./tests/*.c ./s21_string_files/*.c
	clang-format -style=google -i s21_*.h ./tests/*.h ./s21_string_files/*.h


clean : 
	rm -rf *.o *.a test *.gcda *.gcno *.info coverage *.dSYM *.out report tests/*.o *.gcov

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
