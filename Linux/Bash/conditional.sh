#! /usr/bin/bash

#basic conditional statements.
if [ 1 == 1 ]; then
  echo "GoodNight,World!"
fi

hello="GoodNight"
set=0
world=",World!"
if [ $set != 0 ]; then
  echo $hello$world
fi

if [ $set != 0 ]; then
  echo $hello$world
else
  echo $world$hello
fi

# Relational operators :(intergers)
firstnumber=23
secondnumber=32

if [ $firstnumber -eq $secondnumber ]; then
    echo "True"
else
  echo "False"
fi


if [ $firstnumber -ne $secondnumber ]; then
  echo "True"
else
 echo "False"
fi

if [ $firstnumber -gt $secondnumber ]; then
  echo "True"
else
 echo "False"
fi

if [ $firstnumber -lt $secondnumber ]; then
  echo "True"
else
 echo "False"
fi

if [ $firstnumber -lt $secondnumber ]; then
  echo "True"
else
 echo "False"
fi

if [ $firstnumber -ge $secondnumber ]; then
  echo "True"
else
 echo "False"
fi

# String operators:
sfirst="peacefulhat "
ssecond="like peanuts"

if [ "$sfirst" = "$ssecond" ]; then
  echo "True"
else
  echo $sfirst$ssecond
fi 

if [ "$sfirst" != "$ssecond" ]; then
  echo "True"
else
  echo $sfirst$ssecond
fi 

if [ -z "$sfirst" ]; then
  echo "True"
else
  echo $sfirst$ssecond -z "$sfirst"
fi 

if [ $sfirst ]; then
  echo "True"
else
  echo "False"
fi

#File operators
file=/home/peacefulhat/Dev/Bash/conditional.sh
file2=/etc/passwd
if [ -r $file ]; then 
  echo "True File has read access "
else 
  echo "Fales File does not have read access"
fi

if [ -w $file ]; then 
  echo "True File has write access"
else
 echo "False File doesn't have write access"
fi

if [ -x $file ]; then
  echo "True File has executable access"
else
  echo "False File doesn't have executable access"
fi

if [ -f $file2 ]; then
  echo "True File exits and its a regular file"
else
  echo "False File may exits or it not a regular file"
fi

if [ -e $file2 ]; then
  echo "True File exits";
fi

dir=/etc
if [ -d $file ]; then
  echo "True directory exit and its avilable"
else 
  echo "False Not a directory or its not avilable"
fi


if [ -s $file2 ]; then 
  echo "True"
else
 echo "False"
fi

# nested if statements.

if [ -f $file ]; then
  if [ -d $dir ]; then
    echo "Its a directory "
  fi 
else
 echo "Some thing different"
fi

if [ -f $dir ]; then
  echo "Not a file"
elif [ -d $dir ]; then
  echo " Its is a directory"
else
  echo "Something different"
fi

# switch case ;
var=3

case $var in
  1) echo 1
  ;;
  2|3) echo 2 or 3
  ;;
  *) echo default
  ;;
esac

#read var
#echo $var
if [ $var -gt 100 -a $var -eq 120 ]; then
  echo "True"
else
  echo "False"
fi

var=30
if [ $var -eq 30 -o $var -lt 30 ]; then
  echo "True"
else 
  echo "False"
fi

left=$((var<<1))
echo $left
