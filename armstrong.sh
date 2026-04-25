#!/bin/bash

echo "Enter number:"
read num

temp=$num
sum=0

while [ $num -gt 0 ]
do
    d=$((num % 10))
    sum=$((sum + d*d*d))
    num=$((num / 10))
done

if [ $sum -eq $temp ]
then
    echo "Armstrong"
else
    echo "Not Armstrong"
fi