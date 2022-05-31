#include<stdio.h>
#include<unistd.h>

void main(){
  printf("Before fork\n");
  fork();
  printf("After first fork\n");
  fork();
  printf("After second fork\n");
  fork();
  printf("After third fork\n");
}