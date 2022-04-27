#!/bin/sh

echo "enter filename";
read file;
cat $file;
j=1;
res=`cut -f 2 $file`;

sum=0;
for i in $res; do 
	((sum += i));
done

echo average;
echo $[$sum/7];

for i in $res; do 
	if((i>=80));then
		echo $j;
	fi
	((j++));
done;




