#include<stdio.h>
int main()
{
int no,temp,arrival_time[100],burst_time[100],process[15]={1,2,3,4,5,6,7,8,9,10,11,12,12,13,14,15},x,y;
int minimum,k=1,bursttime=0,tot=0,tot1=0;
int turnaround[100],waitingtime[100];
float avg_waiting=0,avg_turnaround=0,turn_tot=0,waiting_tot=0;


printf("******************************************* ");
printf("\nEnter number of  processes you want to execute =");
scanf("%d",&no);
printf("\n******************************************* ");

 
for(x=0;x<no;x++)
{
printf("\nEnter the arrival time of %d process :",x+1);
scanf(" %d",&arrival_time[x]);
{
	if(arrival_time[x]==0)
	{
		printf("\n\t\t-----------ERROR-----------");
		exit(0);
	}
}
printf("\nEnter the burst time of %d process :",x+1);
scanf(" %d",&burst_time[x]);
printf("------------");
}


 
/*Sorting According to Arrival Time*/
 
for(x=0;x<no;x++)
{
      for(y=0;y<no;y++)
          {
              if(arrival_time[x]<arrival_time[y])
                  {
                                temp=process[y];//Sort all process according to arrival time
                                process[y]=process[x];
                                process[x]=temp;
                                
                                temp=arrival_time[y];
                                arrival_time[y]=arrival_time[x];
                                arrival_time[x]=temp;
      
	                            temp=burst_time[y];
                                burst_time[y]=burst_time[x];
                                burst_time[x]=temp;
                 }
           }
}
 
/*Arranging the table according to Burst time,
Execution time and Arrival Time
Arrival time <= Execution time
*/
 
for(y=0;y<no;y++)
       {
            bursttime=bursttime+burst_time[y];
            minimum=burst_time[k];
                 for(x=k;x<no;x++)
                    {
                               if (bursttime>=arrival_time[x] && burst_time[x]<minimum)
                                       {
                                          temp=process[k];
                                          process[k]=process[x];
                                          process[x]=temp;

                                          temp=arrival_time[k];
                                          arrival_time[k]=arrival_time[x];
                                          arrival_time[x]=temp;
                                          
                                          temp=burst_time[k];
                                          burst_time[k]=burst_time[x];
                                          burst_time[x]=temp;
                                       }
                   }
            k++;
       }
     waitingtime[0]=0;
            for(x=1;x<no;x++)
                {
                      tot=tot+burst_time[x-1];
                      waitingtime[x]=tot-arrival_time[x];
                      waiting_tot=waiting_tot+waitingtime[x];
                }
 
    avg_waiting=(waiting_tot/no);
           for(x=0;x<no;x++)
             {
                   tot1=tot1+burst_time[x];
                   turnaround[x]=tot1-arrival_time[x];
                   turn_tot=turn_tot+turnaround[x];
             }
    avg_turnaround=(turn_tot/no);
 
printf("\n************************************");
printf("\n GANTT CHART");
printf("\nprocess\t burst\t arrival\t waiting\t turn-around" );


     for(x=0;x<no;x++)
        {
            printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",process[x],burst_time[x],arrival_time[x],waitingtime[x],turnaround[x]);
        }
        
printf("\n Waiting time = %f",waiting_tot);
printf("\n Turn around time = %f",turn_tot);
printf("\n Average waiting time = %f",avg_waiting);
printf("\n Average turn around time = %f",avg_turnaround);
return 0;
}
