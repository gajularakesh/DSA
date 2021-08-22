//Longest increasing subsequence problem
#include <stdio.h>
#include <stdlib.h>

int LIS(int arr[],int n) {
	int lis[100],i,j,max;
	for(i=0;i<n;i++)
		lis[i]=1;
	for(i=1;i<n;i++)
		for(j=0;j<i;j++)
			if(arr[i]>arr[j]&&lis[i]<lis[j]+1)
				lis[i]=lis[j]+1;
	max=lis[0];
	for(i=1;i<n;i++)
		if(max<lis[i])
			max=lis[i];
	return max;
}

void main() {
	int arr[100],n,i;
	printf("Enter n: ");
	scanf("%d",&n);
	printf("Enter sequence:\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("\nLength of LIS: %d\n",LIS(arr,n));
}