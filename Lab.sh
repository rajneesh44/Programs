#!/bin/sh
echo "Enter the max number you want to see in the pattern"
read num1
num2=2
ans=$((num1*num2))
ans=`expr $ans + 1`
a=0
echo "Printing the pattern ..."
while [ "$a" -lt "$ans" ]
do
if [ "$a" -le "$num1" ]
    then
        b="$a"
        while [ "$b" -ge 0 ]
        do
        echo -n "$b "
        b=`expr $b - 1`
        done
        echo
    fi
if [ "$a" -gt "$num1" ]
    then
        b=`expr $ans - $a - 1`
        while [ "$b" -ge 0 ]
        do
        echo -n "$b "
        b=`expr $b - 1`
        done
        echo
    fi
a=`expr $a + 1`
done
