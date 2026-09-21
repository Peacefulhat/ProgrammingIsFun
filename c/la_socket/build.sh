#!/usr/bin/zsh

rm=$0

gcc -o main c1.c
gcc -o main2 c2.c

if [[ "$rm" == "-y" ]]; then
  rm main
  rm main2
fi

