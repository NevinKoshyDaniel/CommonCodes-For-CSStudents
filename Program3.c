#include<stdio.h>
 struct process
 {
     int bursttime, arrivaltime, priority, process, waitt,turnt;
 };
 int main()
{
    int bursttime, arrivaltime, process,waitt,turnt,i,j,n,totalw=0,totalt=0 ,pos,temp1,timeelapsed=0 ;
    float avg_waitt,avg_turnt;
    printf("Enter number of process:");
    scanf("%d",&n);
    struct process proc[n];
    struct process temp;

    //input block

    printf("\n Enter Burst Time, Arrival Time, Priority [Lower value for higher priority]:\n");
    for(i=0;i<n;i++)
    {
        printf("\np%d:",i+1);
        scanf("%d",&proc[i].bursttime);
        scanf("%d" ,&proc[i].arrivaltime);
        scanf("%d", &proc[i].priority );
        proc[i].process=i;   
    }

    printf(" Process Execution Time:  ");

    //sorting priorities ,as well as respecting the arrival times
    for(i=0;i<n;i++) 
    {    
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(proc[j].arrivaltime <=timeelapsed && proc[j].priority < proc[pos].priority )
                pos=j;
        }
  
        temp=proc[i];
        proc[i]=proc[pos];
        proc[pos]=temp;

        timeelapsed+=proc[i].bursttime;
        printf("%d ",timeelapsed);                              
    }
   

    //cpmputing turn around and waiting times for each process
    for(i=0;i<n;i++)
    {   
        turnt=waitt=0;

        for(j=0;j<i;j++)
        {  
            waitt+=proc[j].bursttime;
        }
        waitt-=proc[i].arrivaltime;
        proc[i].waitt= waitt;
        turnt=proc[i].bursttime+proc[i].waitt;
        proc[i].turnt = turnt;     
        totalw+=waitt;
        totalt+=turnt;
    }
    
    avg_waitt=(float)totalw/n;
    avg_turnt=(float)totalt/n;   
  
    printf("\nProcess\t    Burst Time    \t Arrival Time \t \tPriority \t Waiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
        printf("\n p%d \t\t  %d \t\t    %d \t\t\t %d \t\t %d\t\t\t %d", proc[i].process, proc[i].bursttime, proc[i].arrivaltime,proc[i].priority, proc[i].waitt, proc[i].turnt);    
   
    printf("\nAverage Waiting Time=%f",avg_waitt);
    printf("\nAverage Turnaround Time=%f\n",avg_turnt);
}