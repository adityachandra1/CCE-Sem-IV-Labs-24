#!/bin/bash

echo Q7: Delete all even numbered lines in txt file 
echo "Enter the file:"
read file
echo Before Deletion
cat $file
sed -i '0~2d' $file
echo After Deletion
cat $file
