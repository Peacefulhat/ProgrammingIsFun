#!/bin/zsh
filename="$1"
nasm -f elf64 $filename
output="${filename%.*}"
ld -o $output $output.o
echo
echo "Do you want to run the program(y/n):"
read character
echo
if [[ "$character" == "y" ]]; then
    ./$output
    echo
fi

echo "Do you want to delete the object files and output? (y/n):"

read character

if [[ "$character" == "y" ]]; then
    rm -rf *.o $output
fi
