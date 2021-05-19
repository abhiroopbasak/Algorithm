#include<stdio.h>


void merge(int arr[],int start,int middle,int end)
{
	int n1=middle-start+1;
	int n2=end-middle;
	int S[n1],E[n2];
	for(int i=0;i<n1;i++)
	{
		S[i]=arr[start+i];
	}
	for(int j=0;j<n2;j++)
	{
		E[j]=arr[middle+1+j];
	}
	int i=0;
	int j=0;
	int k=start;
	while(i<n1 && j<n2)
	{
		if(S[i]<=E[j])
		{
			arr[k]=S[j];
			j++;
		}
		else
		{
			arr[k]=E[i];
			i++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k]=S[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=E[j];
		j++;
		k++;
	}
}


void mergesort(int arr[],int start,int end)
{
	if(start<end)
	{
		int middle=(start+(end-start))/2;
		mergesort(arr,start,middle);
		mergesort(arr,middle+1,end);
		merge(arr,start,middle,end);
	}
}


int main()
{
	int arr[6];
	for(int i=0;i<6;i++)
	{
		scanf("%d",&arr[i]);
	}
	mergesort(arr,0,5);
	printf("\nSorted Array:");
	for(int j=0;j<6;j++)
	{
		printf("%d",&arr[j]);
	}
	return 0;
}
