#include<stdio.h>

typedef struct
{
int id;
int bt;
int prior;
int wt;
}
process;

void priority(process p[],int n);

int main()
{
int n,i;
printf("enter the number of processes:");
scanf("%d",&n);

process p[n];

printf("enter burst time  and priority for each process:\n");
for(i=0;i<n;i++)
{
p[i].id=i+1;
printf("process %d:\n",p[i].id);
printf("burst time:");
scanf("%d",&p[i].bt);
printf("priority:");
scanf("%d",&p[i].prior);
}
priority(p,n);

return 0;

}
 
 void priority(process p[],int n)
 {
 int i,j;
 float avg_wt=0;
 
 printf("priority scheduling:\n");
 for(i=0;i<n-1;i++)
 {
 for( int j=0;j<n-i-1;j++)
 {
 if(p[j].prior>p[j+1].prior)
 {
 process temp=p[j];
 p[j]=p[j+1];
 p[j+1]=temp;
 }
 }
 }
 p[0].wt=0;
 for(i=1;i<n;i++)
 {
 p[i].wt=p[i-1].wt+p[i-1].bt;
 avg_wt=avg_wt+p[i].wt;
 }
 printf("process\t brust time\t priority\t waiting time\n");
 for(i=0;i<n;i++)
 {
 printf("%d\t\t %d\t\t  %d\t\t %d\n", p[i].id, p[i].bt, p[i].prior, p[i].wt);
 }
 avg_wt=avg_wt/n;
 printf("average waiting time : %.2f\n",avg_wt);
 }
 
