echo loops
IFS=$'\n'

x=`ls -l | cut -c 1`
for i in $x;do
if [ $i = "d" ] ; then
echo "This is the directory"
fi
done
