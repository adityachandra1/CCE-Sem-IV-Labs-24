echo "Menu"
echo "1. Search"
echo "2. Delete"
echo "3. Exit"
file=$1 
op=$3 
patt=$2
case $op in
1) grep -E "$patt" $file;;
2) sed -i "s/$patt//g" $file;;
3) exit ;;
esac
echo "Done"

