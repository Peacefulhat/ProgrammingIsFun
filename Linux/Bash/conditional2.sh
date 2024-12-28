#! /usr/bin/bash
var=3
var2=4
if(($var == $var2)) then 
  echo "True"
else
  echo "False"
fi
read var 

if(($var&1)) then
  echo "odd"
else
  echo "even"
fi

