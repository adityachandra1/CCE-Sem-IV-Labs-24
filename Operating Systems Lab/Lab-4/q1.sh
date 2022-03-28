#!/bin/bash

echo Q1: Make Duplicate File
echo "Enter the name of the file to be copied:"
read file
touch $file
cp $file copy-$file
