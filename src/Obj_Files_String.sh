#!/bin/bash

cd functions/
gcc -Wall -Werror -Wextra -std=c11 -g -c s21*.c
mv s21*.o ../
cd ../
