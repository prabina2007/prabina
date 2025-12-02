#include<stdio.h>

void main()
{
	int bt[10],rm_bt[10],ct[10],tat[10],wt[10],n,total_time=0,i,j,tq,count=0;
	float sum_tat=0.0,sum_wt=0.0;

	printf("Enter no.of processes:");
	scanf("%d",&n);

	printf("\nEnter brust times:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
		rm_bt[i]=bt[i];
	}

	printf("\nEnter the time quantum:");
	scanf("%d",&tq);

	i=0;

	while(1)
	{
		if(i==n)
		    i=0;

		if(rm_bt[i]>tq)
		{
			total_time+=tq;
			rm_bt[i]=rm_bt[i]-tq;
		}
		else if( rm_bt[i]<=tq && rm_bt[i]!=0 )
		{
			total_time+=rm_bt[i];
			rm_bt[i]=0;
			ct[i]=total_time;
			count++;
		}


		if(count==n)
			break;

		i++;

	}

	for(int i=0;i<n;i++)
	{
		tat[i]=ct[i];
		wt[i]=tat[i]-bt[i];
	}

	printf("\n\nprocess		AT		BT		CT		TAT		WT");
	printf("\n-------		---		---		---		----		---");

	for(int i=0;i<n;i++)
	{


		printf("\n  P%d		%d		%d		%d		%d		 %d",i+1,0,bt[i],ct[i],tat[i],wt[i]);

		sum_tat+=tat[i];
		sum_wt+=wt[i];
	}

	printf("\n\nAvg turn around time:%f",(float)sum_tat/n);
	printf("\nAvg waiting time:%f\n",(float)sum_wt/n);


}
