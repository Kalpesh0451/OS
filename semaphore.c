//TITLE=
//NAME=MANAS SHIRUDE
//BATCH=S1
//ROLL NO.=16
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

#define BUFFER_SIZE 5
#define NUM_ITEMS 10

sem_t mutex;
sem_t full;
sem_t empty;

int buffer[BUFFER_SIZE];
int in=0;
int out=0;

void *producer(void *arg)
{
int item;

for(int i=0;i<10;i++)
{
item=rand() % 100;
sem_wait(&empty);
sem_wait(&mutex);
buffer[in]=item;
printf("PRODUCED BY THREAD %ld=%d\n",(long)pthread_self(),item);
in = (in + 1) % BUFFER_SIZE;
sem_post(&mutex);
sem_post(&full);
sleep(rand() % 2);
}
pthread_exit(NULL);
}
//TITLE=
//NAME=MANAS SHIRUDE
//BATCH=S1
//ROLL NO.=16

void *consumer(void *arg)
{
int item;

for(int i=0;i<10;i++)
{
sem_wait(&full);
sem_wait(&mutex);
item = buffer[out];
printf("CONSUMED BY THREADS %ld=%d\n",(long)pthread_self(),item);
out=(out+1) % BUFFER_SIZE;
sem_post(&mutex);
sem_post(&empty);
sleep(rand()%2);
}
pthread_exit(NULL);
}
//TITLE=IMPLEMENTATION OF SYNCRONISATION
//NAME=MANAS SHIRUDE
//BATCH=S1
//ROLL NO.=16

int main()
{
pthread_t producer_thread,consumer_thread;

sem_init(&empty,0,BUFFER_SIZE);
sem_init(&full,0,0);
sem_init(&mutex,0,1);

pthread_create(&producer_thread, NULL, producer, NULL);
pthread_create(&consumer_thread, NULL, consumer, NULL);

pthread_join(producer_thread, NULL);
pthread_join(consumer_thread, NULL);

sem_destroy(&empty);
sem_destroy(&full);
sem_destroy(&mutex);

return 0;
}

//TITLE=
//NAME=MANAS SHIRUDE
//BATCH=S1
//ROLL NO.=16

