#include<stdio.h>
void main()
{
	int n,i,time,remain1,remain,TAT;
	int flag=0,wait_time=0;
	printf("\t\t\t\tEnter the number of process:");
	scanf("%d",&n);
	int process[n],burst_time[n],arrival_time[n],time_quantum,rt[n];
	printf("\t\t\t\tEnter arrival Time and Burst Time accordingly:\n");
	for(i=0;i<n;i++)
	{
		printf("\n\t\t\t\tFor P%d:",i+1);
		scanf("%d%d",&arrival_time[i],&burst_time[i]);
		rt[i]=burst_time[i];
	}
	printf("\n\t\t\t\tEnter the Time Quantum:");
	scanf("%d",&time_quantum);
	printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
	for(time=0,i=0;remain1!=0;)
	{
		if(rt[i]<=time_quantum && rt[i]>0)
		{
			time=time+rt[i];
			rt[i]=0;
			flag=1;
		}
		else if(rt[i]>0)
		{
			rt[i]=rt[i]-time_quantum;
			time=time+time_quantum;
		}
		if(rt[i]==0 && flag==1)
		{
			remain--;
			printf("P%d\t|\t%d\t|\t%d\n",i+1,time-arrival_time[i]-burst_time[i]);
			wait_time=wait_time+time-arrival_time[i]-burst_time[i];
			TAT=TAT+time-arrival_time[i];
			flag=0;
		}
		if(i==n-1)
		{
			i=0;
		}
		else if(arrival_time[i+1]<=time)
		{
			i++;
		}
		else
		{
			i=0;
		}
	}
	printf("Avg. Waiting Time=%f\n",wait_time*1.0/n);
	printf("Avg. TAT=%f",TAT*1.0/n);
}
