#!/bin/bash

echo "Enter n:"
read n

a=0
b=1

i=1
while [ $i -le $n ]
do
    echo -n "$a "
    c=$((a + b))
    a=$b
    b=$c
    i=$((i+1))
done
echo