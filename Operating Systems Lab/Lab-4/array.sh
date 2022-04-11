echo -n "Enter values of array: "
read -a arr

echo -n "Entered values are: "
for num in ${arr[@]}
do
	echo -n "$num "
done