#!/bin/bash
## Redundant
echo Running all scripts
## result=`find . -maxdepth 1 -name "*sh"`
#for i in $result
#do 
#	echo $i
#	bash $i
#done

for (( i = 1; i <= 5; i++))
do 
	echo $i  
	bash q$i.sh
	echo 
done
