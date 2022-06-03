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

int main(){
  void *psm;
  int shmid ;
  
  shmid = shm_open("OS",O_RDONLY,0666);
  ftruncate(shmid,1024);
  psm = mmap(0,1024,PROT_READ,MAP_SHARED,shmid,0);
  printf("Key/ID/fd of the shared memory: %d\n",shmid);
  printf("Shared memory is attached to %p\n",psm);
  printf("%s",(char *)psm);
  printf("\n");
  shm_unlink("OS");
  return 0;
}

