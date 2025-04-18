#!/bin/zsh

gcc -o main $1 -lGL -lglfw -lGLEW -lX11 -lpthread
