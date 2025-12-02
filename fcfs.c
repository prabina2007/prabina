#include<stdio.h>

void main()
{
	int p[20],bt[20],ct[20],tat[20],wt[20],n,prev_bt=0;
	float sum_tat=0.0,sum_wt=0.0;

	printf("Enter the no.of process:");
	scanf("%d",&n);

	printf("\nEnter the brust time:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
		prev_bt += bt[i];
		ct[i]=prev_bt;
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
