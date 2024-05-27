#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define Max 20
int a[Max][Max],b[Max][Max],c[Max][Max];
int row1,col1,row2,col2,td_num=0;
typedef struct
{
int i;
int j;
}
threaddata;
void *mul(void *para);
void display(int x[Max][Max],int row,int col);
int main()
{
int rCount,cCount;

printf("enter number of rows for Matrix 1:");
scanf("%d",&row1);
printf("enter number of column for Matrix 1:");
scanf("%d",&col1);
for(rCount=0;rCount<row1;rCount++)
{
for(cCount=0;cCount<col1;cCount++)
{
printf("enter Matrix1[%d][%d]:",rCount,cCount);
scanf("%d",&a[rCount][cCount]);
}
}

printf("enter number of rows for matrix 2:");
scanf("%d",&row2);
printf("enter number of column for matrix 2:");
scanf("%d",&col2);
for(rCount=0;rCount<row2;rCount++)
{
for(cCount=0;cCount<col2;cCount++)
{
printf("enter matrix2[%d][%d]:",rCount,cCount);
scanf("%d",&b[rCount][cCount]);
}
}

if(col1 !=row2)
{
printf("multiplication of matrix not possible(column of matrix1 !=row of matrix2)!!!\n\n");
exit(0);
}
for(int i=0;i<row1;i++)
{
for(int j=0;j<col2;j++)
{
threaddata *data=(threaddata *)malloc(sizeof(threaddata));
data->i=i;
data->j=j;
pthread_t td;
pthread_create(&td,NULL,mul,data);
pthread_join(td,NULL);
}
}
printf("\n\n matrix1 is:\n");
display(a,row1,col1);

printf("\n\n matrix2 is:\n");
display(b,row2,col2);

printf("\n\n Resultant matrix is:\n");
display(c,row1,col2);

printf("\n\n total number of thread created by process=%d\n\n",td_num);
return 0;
}
void *mul(void *para)
{
threaddata *data1=(threaddata *)para;
int sum=0;
td_num +=1;
for(int n=0;n<col1;n++)
{
sum +=  a[data1->i][n] * b[n][data1->j];
}
c[data1->i][data1->j]=sum;
printf("\n thread %d finished..!!![%d][%d] value of resultant matrix calculated ",td_num,data1->i,data1->j);
pthread_exit(NULL);
}
void display(int x[Max][Max],int row, int col)
{
for(int i=0;i<row;i++)
{
printf("\n");
for(int j=0;j<col;j++)
{
printf("\t%d",x[i][j]);
}
printf("\n");
}
}




