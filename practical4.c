#include<stdio.h>

typedef struct
{
int id;
int bt;
int wt;
}
process;

void fcfs(process p[],int n);

int main()
{
int n,i;
printf("enter the number of processes:");
scanf("%d",&n);

process p[n];

printf("enter burst time for each process:\n");
for(i=0;i<n;i++)
{
p[i].id=i+1;
printf("process %d:\n",p[i].id);
printf("burst time:");
scanf("%d",&p[i].bt);
}

fcfs(p,n);

return 0;

}
 
 void fcfs(process p[],int n)
 {
 int i;
 float avg_wt=0;
 
 printf("first come first serve (FCFS);\n");
 p[0].wt=0;
 for(i=1;i<n;i++)
 {
 p[i].wt=p[i-1].wt+p[i-1].bt;
 avg_wt=avg_wt+p[i].wt;
 }
 printf("process\t brust time\t waiting time\n");
 for(i=0;i<n;i++)
 {
 printf("%d\t\t %d\t\t %d\n", p[i].id, p[i].bt, p[i].wt);
 }
 avg_wt=avg_wt/n;
 printf("average waiting time : %.2f\n",avg_wt);
 }
 
