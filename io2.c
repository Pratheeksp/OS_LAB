#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#define size 40

int main(){
  int n,fd;
  char buffer[size];

  fd = open("m6.c",O_RDWR);

  if(fd == -1){
    printf("Cannot open the file\n");
    exit(0);
  }

  printf("Reading first charchers from file: \n");
  n = read(fd,buffer,10);
  write(1,buffer,n);

  printf("\nSkipping next 5 characters from current position:\n");
  lseek(fd,5,SEEK_CUR);
  n = read(fd,buffer,10);
  write(1,buffer,n);

  printf("\nGoing back 10 back from current position:\n");
  lseek(fd,-10,SEEK_CUR);
  n = read(fd,buffer,10);
  write(1,buffer,n);

  printf("\nMoving to last 5th characters in file:\n");
  lseek(fd,-5,SEEK_END);
  n = read(fd,buffer,7);
  write(1,buffer,n);

   printf("\nGoing to 3rd character in the file:\n");
  lseek(fd,3,SEEK_SET);
  n = read(fd,buffer,10);
  write(1,buffer,n);

  return 0;
}