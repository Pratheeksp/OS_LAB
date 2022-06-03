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
  
  shmid = shmget((key_t) 1234,1024,0666);
  printf("The shared memory id is %d\n",shmid);
  psm = shmat(shmid,NULL,0666);
  printf("Memory address is attached to the address %p\n",psm);
  printf("The Entered data is: \n");
  printf("%s",(char *)psm);
  shmctl(shmid,IPC_RMID,NULL);

  return 0;
}