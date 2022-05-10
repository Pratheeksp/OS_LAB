#!/bin/bash

echo "Enter a number 1: "
read num1
echo "Enter a number 2"
read num2
echo "Enter a number 3"
read num3

if [ $num1 -gt $num2 ]
then
    if [ $num1 -gt $num3 ]
    then
        echo "$num1 is greatest number"
    else
        echo "$num3 is greatest number"
    fi
else
    if [ $num2 -gt $num3]
    then
        echo "$num2 is greatest number"
    else 
        echo "$num3 is greatest number"
    fi
fi