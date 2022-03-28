#!/bin/bash

echo "Q5: Move files to a given directory"
echo "Enter the file extension to be moved:"
read extension
echo "Enter the folder where the files will be moved to:"
read folder

##For execution check 
touch a1.$extension a2.$extension a3.$extension
rm -rf $folder
##

result=`find . -maxdepth 1 -name "*$extension"`
mkdir $folder
for i in $result
do
    mv $i $folder
done
echo all files moved

ls ./$folder -n
