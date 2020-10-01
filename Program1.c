#include<stdio.h>
 
int main()
{
    int n,burstT[20],waitT[20],turnaroundT[20],waitavg=0,turnavg=0,i,j;
    printf("Enter total number of processes(maximum 20):");
    scanf("%d",&n);
 
    printf("\nEnter Process Burst Time\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&burstT[i]);
    }
 
    waitT[0]=0;    //waiting time for first process is 0
 
    //calculating waiting time
    for(i=1;i<n;i++)
    {
        waitT[i]=0;
        for(j=0;j<i;j++)
            waitT[i]+=burstT[j];
    }
 
    printf("\nProcess \t Burst Time \t Waiting Time \tTurnaround Time \n");
 
    //calculating turnaround time
    for(i=0;i<n;i++)
    {
        turnaroundT[i]=burstT[i]+waitT[i];
        waitavg+=waitT[i];
        turnavg+=turnaroundT[i];
        printf("\n P[%d] \t\t %d \t\t %d \t\t %d",i+1,burstT[i],waitT[i],turnaroundT[i]);
    }
 
    waitavg/=i;
    turnavg/=i;
    printf("\n\nAverage Waiting Time:%d",waitavg);
    printf("\nAverage Turnaround Time:%d \n",turnavg);
 
    return 0;
}