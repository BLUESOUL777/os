#!/bin/bash

read n
sum=0
odd=1

for ((i=1;i<=n;i++))
do
    sum=$((sum+odd))
    odd=$((odd+2))
done

echo "Sum = $sum"