#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>

int main(int argc,int *argv[]){
  int shm_fd,i;
  void *ptr;
  int n1,n2,n3,k=2;

  shm_fd = shmget((key_t) 1234,4096,0666 | IPC_CREAT);
  ptr = shmat(shm_fd,NULL,0666);

  i = atoi(argv[1]);

  n1 = 0;
  sprintf(ptr,"%d ",n1);
  ptr += strlen(ptr);

  n2 = 1;
  sprintf(ptr,"%d ",n2);
  ptr += strlen(ptr);

  while(k<i){
    n3 = n1+n2;
    sprintf(ptr,"%d ",n3);
    n1 = n2;
    n2 = n3;
    k++;
    ptr += strlen(ptr);
  }
  //shmctl(shm_fd,IPC_RMID,NULL);
  return 0;
}