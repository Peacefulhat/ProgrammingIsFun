#! /usr/bin/bash

firstNumber=$1
secondNumber=$2
sum=`expr $firstNumber + $secondNumber`
sub=`expr $firstNumber - $secondNumber`
mul=`expr $firstNumber \* $secondNumber`
mod=`expr $firstNumber % $secondNumber`
div=`expr $firstNumber / $secondNumber`
echo $sum $sub $mul $mod $div
