#include<stdio.h>
//#include<time.h>
void mergesort(int [],int,int,int);
void main()
{
	int a[1000],n,i;
	//float t;
	printf("enter size\n");
	scanf("%d",&n);
	
	//srand(time(0));
	printf("enter the elements\n");
	for(i=0;i<n;i++)
	{
		//	a[i]=rand();
		scanf("%d",&a[i]);
		
	}
	//t=clock();
	merge(a,0,n-1);
	//t=(clock()-t)/CLOCKS_PER_SEC;
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	
//	printf("\n%f",t);
}
void merge(int a[],int start,int end)
{	
	int mid;
	if(start<end)
	{	
		mid=(start+end)/2;
		merge(a,start,mid);
		merge(a,mid+1,end);
		mergesort(a,start,mid,end);
	}
}
void mergesort(int a[],int start,int mid,int end)
{
	int i,j,b[100000],k=0;
	if(start<end)
	{
		i=start;
		j=mid+1;
		while(i<=mid && j<=end)
		{
			if(a[i]<a[j])
			{
				b[k]=a[i];
				k++;	
				i++;
			}
			else
			{
				b[k]=a[j];
				j++;
				k++;
			}
		}
		while(i<=mid)
		{
			b[k]=a[i];
			k++;
			i++;
		}
		while(j<=end)
		{
			b[k]=a[j];
			j++;
			k++;
		}
		k=0;
		for(i=start;i<=end;i++)
		{
			a[i]=b[k];
			k++;
		}
		
	}
}
