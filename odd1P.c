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
#include<sys/wait.h>

int main(int argc,int *argv[]){
  int i;
  int k;
  int n1,n2,n3;
  pid_t pid;
  const int SIZE = 4096;
  int shm_fd;
  void *ptr;

  if(argc>1){
    sscanf(argv[1],"%d",&i);
    if(i<1){
      printf("Error input");
      exit(0);
    }
  }
  else{
    printf("Error not passing the command");
    exit(0);
  }

  pid = fork();

  if(pid == 0){
    execlp("./odd","odd",argv[1],NULL);
  }

  else if(pid > 0){
    wait(NULL);
    printf("Parent: Child completed\n");
    shm_fd = shm_open("OS1",O_RDONLY,0666);
    ptr = mmap(0,SIZE,PROT_READ,MAP_SHARED,shm_fd,0);
    printf("\nParent is printing:\n");
    printf("%s",(char *)ptr);
    shm_unlink("OS1");
  }
  return 0;
}