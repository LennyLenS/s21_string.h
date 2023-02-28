CFILES = $(wildcard s21*.c)
OBJ = $(patsubst %.c, %.o, $(CFILES))
#SPRINTF = s21_sprintf
TARGET = s21_string
CHECK:=$(shell pkg-config --cflags --libs check)
FLAG_COV = --coverage
CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11 $(DEBUG)
S21_MATH=-L. s21_math.a
#DEBUG =-g
TESTS_SOURCES=test_me.c $(wildcard tests/*.c)
TESTS_OBJECTS=$(TESTS_SOURCES:.c=.o)
#LEAK=-fsanitize=address
CTESTFLAGS=-lcheck -lm -lpthread $(LEAK) 
TEST = tests_me.c  
LIBRARY = s21_string.a
COMPILE = $(CFILES)


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

$(LIBRARY): $(CFILES)
	bash Obj_Files_String.sh
	$(CC) $(CFLAGS) -c $(CFILES)
	ar rc $(LIBRARY) $(OBJ) s21_strcat.o s21_strcpy.o s21_strlen.o
	ranlib $(LIBRARY)

clean:
	rm -rf *.o *.a test *.gcda *.gcno *.info coverage

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

test: $(TESTS_OBJECTS) $(LIBRARY)
	$(CC) $^ -o test $(CTESTFLAGS)
	./test



# test: $(LIBRARY)
# 	checkmk tests.check > tests_functions.c
# 	checkmk clean_mode=1 tests.check > tests_functions.c
# 	$(CC) $(CTESTFLAGS) $(TEST) $(LIBRARY) -o test
# 	./test

rebuild:
	make clean
	make
