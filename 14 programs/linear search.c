#include<stdio.h>
int main()
{
	int i,n,key,a[10];
	printf("enter size\n");
	scanf("%d",&n);
	printf("enter elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	printf("enter key to search\n");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			printf("element found in %d position\n",i);
			break;
		}
	}
	if(i==n)
	printf("element not found\n");
}
