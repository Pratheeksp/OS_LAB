#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<time.h>
#define max 5
#define size 5

sem_t full;
sem_t emty;
int buffer[max];
int in=0,out=0;
pthread_mutex_t mutex;

void *producer(void *pno){
  int item;
  
  for(int i=0;i<max;i++){
    item = rand()%100;
    sem_wait(&emty);
    pthread_mutex_lock(&mutex);
    buffer[in] = item;
    printf("Producre[%d] inserted %d at %d\n",*((int *)pno),item,in);
    in = (in+1)%size;
    sem_post(&full);
    pthread_mutex_unlock(&mutex);
  }
}

void *consumer(void *cno){
  for(int i=0;i<max;i++){
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    int item = buffer[out];
    printf("Consumer[%d] removed item %d from %d\n",*((int *)cno),item,out);
    out = (out+1)%size;
    sem_post(&emty);
    pthread_mutex_unlock(&mutex);
    
  }
}

int main(){
  pthread_t p[5],c[5];
  
  sem_init(&full,0,0);
  sem_init(&emty,0,size);
  pthread_mutex_init(&mutex,NULL);

  int a[5] = {1,2,3,4,5};

  for(int i=0;i<5;i++)
    pthread_create(&p[i],NULL,(void *)producer,(void *)&a[i]);

  for(int i=0;i<5;i++)
    pthread_create(&c[i],NULL,(void *)consumer,(void *)&a[i]);

  for(int i=0;i<5;i++)
    pthread_join(p[i],NULL);

  for(int i=0;i<5;i++)
    pthread_join(c[i],NULL);

  sem_destroy(&emty);
  sem_destroy(&full);
  pthread_mutex_destroy(&mutex);
}