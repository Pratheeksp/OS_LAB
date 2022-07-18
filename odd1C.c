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
  int k = 0,n = 1;
  void *ptr1;
  int shm_fd = shm_open("OS1",O_CREAT | O_RDWR,0666);
  ftruncate(shm_fd,4096);
  ptr1 = mmap(0,4096,PROT_WRITE,MAP_SHARED,shm_fd,0);
  printf("child:\n");
  int i = atoi(argv[1]);

  while(k<i){
    sprintf(ptr1,"%d  ",n);
    printf("%d  ",n);
    ptr1+=strlen(ptr1);
    k++;    
    n = n+2;
  }
  printf("\n");
}