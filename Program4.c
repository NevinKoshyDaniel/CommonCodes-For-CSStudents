#include<stdio.h>
 struct process
 {
     int bursttime, arrivaltime, process, waitt,turnt, execTimeL,finished;
 };
 int main()
{
    int bursttime, arrivaltime, process,waitt,turnt,i,j,n,totalw=0,totalt=0,extratime=0 ,pos,temp1,timeelapsed=0, runtime=0, timeq ;
    float avg_waitt,avg_turnt;
    printf("Enter number of process:");
    scanf("%d",&n);
    //int finished[n];
    printf("\nEnter the time quantum:");
    scanf("%d",&timeq);
    struct process proc[n];
    struct process temp;

    //input block

    printf("\n Enter Burst Time, Arrival Time :\n");
    for(i=0;i<n;i++)
    {
        printf("\np%d:",i+1);
        scanf("%d",&proc[i].bursttime);
        scanf("%d" ,&proc[i].arrivaltime);
        proc[i].process=i;   
        proc[i].execTimeL=proc[i].bursttime;
        proc[i].finished=0;
    }

    printf(" Process Execution Time:  ");

    //sort by arrival time
     for(i=0;i<n-1;i++) 
    {    
        pos=i;
        for(j=i;j<n;j++)
        {
            if(proc[pos].arrivaltime >proc[j].arrivaltime)
                pos=j;
        }
        if(pos!=i)
        {
        temp=proc[i];
        proc[i]=proc[pos];
        proc[pos]=temp;
        }
        timeelapsed+=proc[i].bursttime;
        printf("%d ",timeelapsed);                              
    }
    timeelapsed+=proc[i].bursttime;
    printf("%d \n \n",timeelapsed);

    //repeatedly traverse the content while it has any unfinished job
    i=0;
   
    while(runtime<=timeelapsed)
    {   

        extratime=0;
        if (proc[i].arrivaltime <= runtime && proc[i].execTimeL>0)
        {   
            if(proc[i].execTimeL<= timeq)
            {   
                extratime=proc[i].execTimeL;
                proc[i].execTimeL=0;
                proc[i].finished=1;
                printf("Entered: %d %d \n",proc[i].execTimeL,proc[i].bursttime);
                proc[i].turnt=runtime+extratime-proc[i].arrivaltime; //turn around time calculation
                proc[i].waitt=proc[i].turnt-proc[i].bursttime; // burst time calculation
            }
            else
                proc[i].execTimeL-=timeq;
        }
        //variable updation
        for(j=0;j<n;j++)
        {   
            pos=(i+j+1)%n;
            if(proc[pos].finished!=1)
                break;
        }
        i=pos;
        //debugging section starts
        //error check
        printf("%d %d ",i,pos-1);
        if(pos==0)
             printf("%d \t\t",proc[n-1].finished); 
        else
             printf("%d \t\t",proc[pos-1].finished);

        //display section
        for(j=0;j<n;j++)
        {            
            printf("%d %d \t",proc[j].bursttime,proc[j].execTimeL);
        }
        printf("\n");
        //debugging section ends.
        runtime+=timeq-extratime;
    }
    
    //computing average turn around and waiting times 
    for(i=0;i<n;i++)
    {   
        totalw+=proc[i].waitt;
        totalt+=proc[i].turnt;
    }
    
    avg_waitt=(float)totalw/n;
    avg_turnt=(float)totalt/n;   
  
    printf("\nProcess\t    Burst Time    \t Arrival Time \t \t Waiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
        printf("\n p%d \t\t  %d \t\t    %d \t\t\t %d \t\t %d\t\t\t", proc[i].process, proc[i].bursttime, proc[i].arrivaltime, proc[i].waitt, proc[i].turnt);    
   
    printf("\nAverage Waiting Time=%f",avg_waitt);
    printf("\nAverage Turnaround Time=%f\n",avg_turnt);
}