#include<stdio.h>
int binary(int a[],int l,int h,int k)
{		
	int mid;
	if(l<=h)
	{	
		mid=(l+h)/2;
		if(k==a[mid])
		return 1;
		else if(k < a[mid])
		return binary(a,l,mid-1,k);

		return	binary(a,mid+1,h,k);
	}
	return -1;
	
}
int main()
{
	int a[10],n,k,i;
	printf("enter size\n");
	scanf("%d",&n);
	printf("enter the elements in sorting order\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("enter the element to search\n");
	scanf("%d",&k);
	k=binary(a,0,n-1,k);
	(k==1)?printf("element found\n"):printf("not found\n");
}
