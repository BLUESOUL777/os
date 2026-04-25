#!/bin/bash

read num
sum=0

while [ $num -gt 0 ]
do
    d=$((num%10))
    sum=$((sum+d))
    num=$((num/10))
done

echo $sum