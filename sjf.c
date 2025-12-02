#include<stdio.h>

void main()
{
	int p[10],bt[10],ct[10],tat[10],wt[10],n,temp,min,i,j,pre_bt=0;
	float sum_tat=0.0,sum_wt=0.0;

	printf("Enter the no.of process:");
	scanf("%d",&n);

	printf("\nEnter the brust times:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
		p[i]=i+1;

	}


	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(bt[i]>bt[j])
			{
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;

				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}



	for(i=0;i<n;i++)
	{
		pre_bt+=bt[i];
		ct[i]=pre_bt;
		tat[i]=ct[i];
		wt[i]=tat[i]-bt[i];
	}

	
	printf("\n\nprocess		AT		BT		CT		TAT		WT");
	printf("\n-------		---		---		---		----		---");

	for(int i=0;i<n;i++)
	{


		printf("\n  P%d		%d		%d		%d		%d		 %d",p[i],0,bt[i],ct[i],tat[i],wt[i]);

		sum_tat+=tat[i];
		sum_wt+=wt[i];
	}
	printf("\n\nAvg turn around time:%f",(float)sum_tat/n);
	printf("\nAvg waiting time:%f\n",(float)sum_wt/n);
}
