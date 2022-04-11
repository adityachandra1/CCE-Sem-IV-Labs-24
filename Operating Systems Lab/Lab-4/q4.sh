name=${1}
for i in ${@:2}
do
case "$i" in 
"1.Linecount" ) wc -l < $name
;;
"2.Wordcount" ) wc -w < $name
;;
"3.Charcount" ) wc -m < $name
;;
*) echo "Invalid Option"
;;
esac
done

