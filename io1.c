#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define size 40

int main(){
  char buffer[size];

  printf("Enter the characters to be print: \n");
  int n = read(0,buffer,size);

  printf("Number of characters read is: %d\n",n);
  write(1,buffer,n);
}