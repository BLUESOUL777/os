#!/bin/bash

echo "Top processes:"
ps -Ao pid,comm,%cpu | sort -k3 -nr | head -10

echo -e "\nMax memory process:"
ps -Ao pid,comm,%mem | sort -k3 -nr | head -1

echo -e "\nUser:"
whoami

echo -e "\nEnter file:"
read f
head -11 $f