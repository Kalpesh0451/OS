#include<stdio.h>
#include<pthread.h>

void *thread_function(void *arg)
{
printf("hello from this thread!\n");
pthread_exit(NULL);
}
int main()
{
pthread_t thread_id;
int rc;
printf("create pthread....\n");
rc=pthread_create(&thread_id,NULL,thread_function,NULL);
if(rc)
{
printf("ERROR:return code from pththread_create() is:%d",rc);
return 1;
}
pthread_join(thread_id,NULL);
printf("pthread is completed its execution");
return 0;
}
