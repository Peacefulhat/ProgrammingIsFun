#!/bin/zsh 

CFLAGS="-Wall"


clang $CFLAGS -o main main.c src/$1

./main



