#! /usr/bin/bash

var=0
read var
factorial=1
while (($var >= 1)) do 
  factorial=$(($factorial * $var))
  var=`expr $var - 1`
done
echo "Factorial of given number is :" $factorial

for((z=0;z<10;z=`expr $z + 1`)) do 
  echo "GoodNight"
done
i=0
for i in 1 2 3 4; do 
  echo "world"
done
 
#for i in /etc/*; do 
 # echo $i 
#done
#some star patterns.
some=5
while(( $some != 0 )) do 
  vb=1
  ch=*
  while(( $vb < $some )) do 
    ch="* $ch"
    vb=`expr $vb + 1`
  done
  echo "$ch"
  some=`expr $some - 1` 
done
# some star patterns.
some=0
while(($some<5)) do 
  ch="*"
  vb=0
  while((vb<some)) do 
    ch="* $ch"
    vb=$(($vb + 1))
  done
  echo "$ch"
  some=$(($some + 1))
done
