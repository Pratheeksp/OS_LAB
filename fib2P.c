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
  int i;
  pid_t pid;

  if(argc>1){
    sscanf(argv[1],"%d",&i);
    if(i < 1){
      printf("ERROR input");
      exit(0);
    }
  }

  else{
    printf("Insufficient input");
    exit(0);
  }

  pid = fork();

  if(pid == 0){
    execlp("./fib","fib",argv[1],NULL);
  }

  else if(pid>0){
    wait(NULL);
    int shm_fd = shmget((key_t) 1234,4096,0666);
    void *ptr = shmat(shm_fd,NULL,0666);
    printf("Parenting printing fibonacci number till %d\n",i);
    printf("%s",(char *)ptr);
    shmdt(ptr);
  }
  return 0;
}
