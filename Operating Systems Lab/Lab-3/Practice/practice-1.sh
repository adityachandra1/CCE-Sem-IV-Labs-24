#!/bin/sh
echo "Hello World"
number=1
echo $number
echo $PATH
read x
echo x value is $x
x=$((x+1))
echo $x
echo enter a and b
read a b
result=$[ $a==$b ]
echo $result 
((a++))
result=$((a + b ))
echo $result
result=$((a*b))
echo $result
read char
if [ "$char"=="2" ]; then
	echo two entered
else 
	echo non-two
fi
read fileName
if [ -e $fileName ]; then 
	echo "$fileName exists"
fi
