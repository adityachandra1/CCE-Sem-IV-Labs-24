#!/bin/bash

#Creating the directory
rm -rf OS
mkdir OS
cd ./OS
touch a.txt b.txt c.txt
cd ..
#

echo "Q3: Replacing .txt with .text"
result=`find . -depth -name *.txt`
for i in $result 
do
	echo renaming $i 
    mv $i ${i%.txt}.text
done
echo "All files renamed!"

