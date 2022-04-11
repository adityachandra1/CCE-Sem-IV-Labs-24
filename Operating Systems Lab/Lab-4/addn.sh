read file
read start
read end
sed -n $start,$end\p $file | cat > new
cat new
