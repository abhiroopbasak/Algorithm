# include <stdio.h>


int min(int a,int b)
{
	if(a<b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

void jobsequence(int profit[5],int duration[5],int jobid[5])
{

	int temp;
	int max=0;
	
	for(int i=0;i<5;i++)
	{
		if(max<duration[i])
		{
			max=duration[i];
		}
	}
	
	int jseq[max];
	int seq[max];
	for(int i=0;i<max;i++)
	{
		seq[i]=-1;
	}
	
	
	for(int i=0;i<5;i++)
	{
		for(int j=4;j>=0;j--)
		{
			if(profit[j]<profit[j+1])
			{
				temp=profit[j];
				profit[j]=profit[j+1];
				profit[j+1]=temp;
				
				temp=duration[j];
				duration[j]=duration[j+1];
				duration[j+1]=temp;
				
				temp=jobid[j];
				jobid[j]=jobid[j+1];
				jobid[j+1]=temp;
			}
		}
	}
	

	for(int i=0;i<5;i++)
	{
		for(int j=duration[i]-1;j>=0;j--)
		{
			
			if (seq[j]==-1)
			{
				seq[j]=0;
				jseq[j]=i;
				break;
			}
		}
	}	
	

	
	printf("Job sequence: ");
	for(int i=0;i<5;i++)
	{
		if(seq[i]==0)
		{
			printf("j%d ",jobid[jseq[i]]);
		}
	}
}


int main()
{
	int profit[5],duration[5],jobid[5]={1,2,3,4,5};
	printf("Enter the profits\n");
	for(int i=0;i<5;i++)
	{
		scanf("%d",&profit[i]);
	}
	printf("Enter the duration\n");
	for(int j=0;j<5;j++)
	{
		scanf("%d",&duration[j]);
	}
	
	jobsequence(profit,duration,jobid);
}
