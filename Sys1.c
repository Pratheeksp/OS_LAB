#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

void main(){
  pid_t child, parent ,my;
  int i=10;

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
    printf("C -- i =  %d\n",--i);
    printf("C -- Now child is going to execute the another file using execlp\n");
    execlp("/bin/pwd","pwd",NULL);
  }

  else{
     my = getpid();
    parent = getppid();

    printf("P -- My pid is %d\n",my);
    printf("P -- Parents pid is %d\n",parent);
    printf("P -- i = %d\n",++i);
    printf("P -- Now Parent is going to wait for the child to terminate\n");
    wait(NULL);
    printf("P -- Resumng after termination\n");
    printf("P -- The childs pid is %d\n",child);
  }
}