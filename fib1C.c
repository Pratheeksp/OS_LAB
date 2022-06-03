#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,int *argv[]){
  int k=2,n1,n2,n3;
  void *ptr;
  int shm_fd = shm_open("OS",O_CREAT | O_RDWR,0666);
  ftruncate(shm_fd,4096);
  ptr = mmap(0,4096,PROT_WRITE,MAP_SHARED,shm_fd,0);
  printf("child:\n");
  int i = atoi(argv[1]);
  n1 = 0;
  n2 = 1;

  if(i == 1){
    sprintf(ptr,"%d  ",n1);
    ptr += strlen(ptr);
    printf("%d  ",n1);
  }

  if(i == 2){
    sprintf(ptr,"%d  ",n2);
    ptr += strlen(ptr);
    printf("%d  ",n2);
  }

  while(k<i){
    n3 = n1+n2;
    sprintf(ptr,"%d  ",n3);
    printf("%d  ",n3);
    n1 = n2;
    n2 = n3;
    ptr+=strlen(ptr);
    k++;
  }
}