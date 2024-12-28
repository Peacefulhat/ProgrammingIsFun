#!/bin/zsh

if [ "$1" -eq 1 ]; then
    echo "assembly and executable..."
    echo
    gcc -S $2
    gcc -o main $2
    ./main
    rm -rf main
fi

if [ "$1" -eq 0 ]; then
    echo "executable only..."
    echo
    gcc -o main $2
    ./main
    rm -rf main
fi
