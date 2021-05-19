#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);
		return binarySearch(arr, mid + 1, r, x);
	}
	return -1;
}



int main(void)
{
	int arr[10],x,n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter elements of array:");
	for (int j=0;j<n;j++)
	{
	    scanf("%d",&arr[j]);
	}
    
	printf("Enter the number to find:");
	scanf("%d",&x);
	int result = binarySearch(arr, 0, n - 1, x);
	if (result == -1)
	{
	    printf("Element is not present");
	}
	else
	{
	    printf("Element is present at index: %d",result);
	}
	return 0;
}

