#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>

int main(){
  void *psm;
  int shmid;
  char buf[10];
  
  shmid = shmget((key_t) 1122,1024,0666|IPC_CREAT);
  printf("The shared memory id is %d\n",shmid);
  psm = shmat(shmid,NULL,0666);
  printf("Memory address is attached to the address %p\n",psm);
  printf("Enter some data to write into the shared memory: \n");
  read(0,buf,10);
  sprintf(psm,"%s",buf);
  shmdt(psm);

  return 0;
}