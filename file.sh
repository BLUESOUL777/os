#!/bin/bash

# Create files
echo "Amit Rahul Neha" > f1.txt
echo "Zoya Ankit Meera" > f2.txt

# Concatenate
echo "Concatenated:"
cat f1.txt f2.txt

# Sort ascending
echo -e "\nAscending:"
cat f1.txt f2.txt | tr ' ' '\n' | sort

# Sort descending
echo -e "\nDescending:"
cat f1.txt f2.txt | tr ' ' '\n' | sort -r