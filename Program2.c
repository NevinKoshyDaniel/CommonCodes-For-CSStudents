#include<stdio.h>
 struct process
 {
     int bursttime, arrivaltime, process, waitt,turnt;
 };
 int main()
{
    int bursttime, arrivaltime, process,waitt,turnt,i,j,n,totalw=0,totalt=0 ,pos,temp1,timeelapsed=0 ;
    float avg_waitt,avg_turnt;
    printf("Enter number of process:");
    scanf("%d",&n);
    struct process proc[n];
    struct process temp;
    printf("\n Enter Burst Time & Arrival Time:\n");
    for(i=0;i<n;i++)
    {
        printf("\np%d:",i+1);
        scanf("%d",&proc[i].bursttime);
        scanf("%d" ,&proc[i].arrivaltime);
        proc[i].process=i;   
    }
  
   //sorting of burst times
    for(i=0;i<n;i++) //fix the burst time sorting with arrival time, check if the lowest burst time is actually there
    {    
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(proc[j].bursttime < proc[pos].bursttime && proc[j].arrivaltime <= timeelapsed)
                pos=j;
        }
  
        temp=proc[i];
        proc[i]=proc[pos];
        proc[pos]=temp;

        timeelapsed+=proc[i].bursttime;
        printf("%d ",timeelapsed);                              
    }
   
    for(i=0;i<n;i++)
    {   
        turnt=waitt=0;

        for(j=0;j<i;j++)
        {  
            waitt+=proc[j].bursttime;
        }
        waitt-=proc[i].arrivaltime;
        proc[i].waitt= waitt;
        turnt=proc[i].bursttime+proc[i].waitt-proc[i].arrivaltime;
        proc[i].turnt = turnt;     
        totalw+=waitt;
        totalt+=turnt;
    }
  
    avg_waitt=(float)totalw/n;
    avg_turnt=(float)totalt/n;   
  
    printf("\nProcess\t    Burst Time    \t Arrival Time \t \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
        printf("\n p%d \t\t  %d \t\t    %d \t\t\t %d \t\t\t %d", proc[i].process, proc[i].bursttime, proc[i].arrivaltime, proc[i].waitt, proc[i].turnt);    
   
    printf("\nAverage Waiting Time=%f",avg_waitt);
    printf("\nAverage Turnaround Time=%f\n",avg_turnt);
}