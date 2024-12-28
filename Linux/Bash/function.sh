#!/usr/bin/bash
set -vx
var=5
factorial(){
  local result=1
  for((dir=5;dir >=1 ; dir=`expr $dir - 1`)) do 
  result=$(($result * dir ))
  echo
done
return $result
}
factorial
res=$?
echo $res

# passing arrguments to bash functions

iseven () {
if [ $(($1 % 2)) -eq 0 ]; then
echo "$1 is even."
else
echo "$1 is odd."
fi
}

iseven 3
isevne 4
iseven 0


# recursive function.

fib(){
  if(())
}
