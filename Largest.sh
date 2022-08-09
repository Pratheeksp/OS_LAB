#!/bin/bash
#Shell script to find largest of N numbers (store nums in array)

echo "Enter array elements: "
read -a A
echo "Array elements: ${A[*]}"
max=0

for i in ${A[*]}
do
    if [ $i -gt $max ];then
        max=$i
    fi
done
echo "Largest Number: $max"
