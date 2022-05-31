#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

void main(){
  pid_t child, parent ,my;

  child = fork();

  if(child < 0){
    printf("Failed to create the new process");
    exit(0);
  }

  if(child == 0){
    my = getpid();
    parent = getppid();

    printf("C -- Childs pid is %d\n",my);
    printf("C -- Parents pid is %d\n",parent);
    printf("C -- Child is sleeping for 10 sec\n");
    sleep(10);
    printf("C -- My parent has terminated so i am orphan adopted by init process\n");
  }

  else{
     my = getpid();
    parent = getppid();

    printf("P -- My pid is %d\n",my);
    printf("P -- Parents pid is %d\n",parent);
    printf("P -- The childs pid is %d\n",child);
    printf("P -- Exiting\n");
    exit(0);
  }
}