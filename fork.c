#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

int main()
{
pid_t pid;
pid=fork();
if(pid==-1)
{
perror("invalide choice");
return(1);
}
if(pid>0)
{
printf("\n this is parent process:");
printf("\nPID of parent process is:%d",getpid());
printf("\n\n");
wait(NULL);
}
else
{
printf("\nthis is child process:");
printf("\nPID of child process is:%d",getpid());
printf("\nPID of parent process is:%d",getppid());
printf("\n\n");
}
return 0;
}

