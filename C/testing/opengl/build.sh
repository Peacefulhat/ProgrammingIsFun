#!/bin/zsh

LIBS="-lglfw -lGLEW -lGL"

gcc -o main $1 ${LIBS}

./main
