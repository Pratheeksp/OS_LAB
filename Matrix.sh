#!/bin/bash

declare -A X
declare -A Y
declare -A Z

echo "Enter the size of the matrix: "
read m
read n

echo "Enter elements first matrix: "

for (( i=0;i<m;i++ ))
do
  for (( j=0;j<n;j++ ))
  do 
    read X[$i,$j]
  done
done

echo "Enter the elements of second matrix: "

for (( i=0;i<m;i++ ))
do
  for (( j=0;j<n;j++ ))
  do 
    read Y[$i,$j]
  done
done

echo "Matrix-1: "

for (( i=0;i<m;i++ ))
do
  for (( j=0;j<n;j++ ))
  do 
    echo -en "${X[$i,$j]}  "
  done
  echo
done

echo "Matrix-2: "

for (( i=0;i<m;i++ ))
do
  for (( j=0;j<n;j++ ))
  do 
    echo -en "${Y[$i,$j]}  "
  done
  echo
done

echo "The resultant Matrix:"

for (( i=0;i<m;i++ ))
do
  for (( j=0;j<n;j++ ))
  do 
    Z[$i,$j]=$((X[$i,$j]+Y[$i,$j]))
    echo -en "${Z[$i,$j]}  "
  done
  echo
done