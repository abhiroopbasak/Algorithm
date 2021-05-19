#include<stdio.h>

int main()
{
	int arr[6];
	int temp=0;
	for(int i=0;i<6;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(int j=6;j>=0;j--)
	{
		for(int k=j;k<6;k++)
		{
			if(arr[k]>arr[k+1])
			{
				temp=arr[k];
				arr[k]=arr[k+1];
				arr[k+1]=temp;
			}
		}
	}
	for(int m=0;m<6;m++)
	{
		printf("%d ",arr[m]);
	}
	return 0;
}
