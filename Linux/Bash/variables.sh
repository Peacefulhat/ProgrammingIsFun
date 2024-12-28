#! /usr/bin/bash
set -vx # here set -vx is used check how your script is behaiving when it running
myname="peacefulhat" #string are store in double quotation marks.
mynumber=93423 # interger type
envvariables=$1 # here envvariables is global varibale that im takig as an positional argument.
state=True
echo $myname $mynumber $envvariables
