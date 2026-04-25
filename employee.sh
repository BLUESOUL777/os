#!/bin/bash

echo "101 Amit 30000" > e1.txt
echo "102 Rahul 25000" >> e1.txt

echo "103 Neha 28000" > e2.txt

cat e1.txt e2.txt > e3.txt

echo "Combined:"
cat e3.txt

echo "Count:"
wc e3.txt