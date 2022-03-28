#!/bin/bash

echo Q6: Find and Replace ex: with Example:

sed -i -e 's/^ex:/Example:/' *.txt       
sed -i -e 's/\. ex:/\. Example:/' *.txt  

cat f1.txt

