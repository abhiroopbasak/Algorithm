#include<stdio.h>

int main()
{
	int arr[6];
	for(int k=0;k<6;k++)
	{
		scanf("%d",&arr[k]);
	}
	int temp=0;
	for(int i=0;i<6;i++)
	{
		for (int j=0;j<6;j++)
		{
			if(arr[j]>arr[i])
			{
				temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;	
			}	
		}
	}
	for(int m=0;m<6;m++)
	{
		printf("%d",arr[m]);
	}
	return 0;
}
