#!/usr/bin/bash
gcc -o out $1
./out
rm -rf out
echo
