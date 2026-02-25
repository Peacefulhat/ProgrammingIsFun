#!/bin/zsh
gcc -o main main.c -lm $(pkg-config --libs raylib)
./main
rm -rf main
   
