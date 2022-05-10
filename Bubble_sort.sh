#!/bin/bash

echo -en "Enter a size of the array: "
read n

echo "Enter the elements of array"

for (( i = 0; i < n; i++ ))
do
  read arr[$i]
done

echo -en "The Entered elemnts are : "

for ((i=0;i<n;i++))
do
  echo -en "${arr[ $i ]}  "
done

echo
echo

for ((i=0;i<n-1;i++))
do
  for ((j=0;j<n-i-1;j++))
  do
    if [ ${arr[$j]} -gt ${arr[$j+1]} ]
    then  
        temp=${arr[$j]}
        arr[$j]=${arr[$j+1]}
        arr[$j+1]=$temp
    fi
  done
done

echo -en "The sorted array is: "

for (( i = 0; i < n; i++ ))
do
  echo  -en "${arr[$i]}  "
done