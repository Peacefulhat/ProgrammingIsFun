#!/usr/bin/bash
# Get string length.
distro="Arch arch2"
res=${#distro} #{#distro} returns string length.
#echo $res

#substring.

for ((i=0;i<4;i=`expr $i + 1`)); 
do
  echo ${distro:i:((4 - i))} # ${distro:startingindex:endingindex}
done

# Repalcacing substring.

distro=${distro/arch2/Arch2}

echo $distro

