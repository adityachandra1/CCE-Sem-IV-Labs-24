#!/bin/sh

echo "Q1: Check Directory"
echo "Enter the filename/path"
read file;
if [ -d "${file}" ] ; then
    echo "$file is a directory";
elif [ -f "${file}" ]; then
    echo "${file} is a file";
else
    echo "${file} is not valid";
fi
