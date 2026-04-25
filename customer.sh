#!/bin/bash

echo "201 Amit Mumbai 5000" > c1.txt
echo "202 Rahul Pune 7000" >> c1.txt

echo "203 Neha Delhi 6500" > c2.txt
echo "204 Kiran Chennai 8000" >> c2.txt

cat c1.txt c2.txt > c3.txt

echo "Combined:"
cat c3.txt

wc c3.txt