#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main(){
  printf("Before the fork\n");
  fork();
  fork();
  fork();
  printf("After fork\n");
}