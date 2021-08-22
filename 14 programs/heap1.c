#include<stdio.h>
int n;
int max(int a,int b)
{
	return (a>b)?a:b;
}
int heapify(int a[],int n)
{
	int i,j,flag=1;
	while(flag)
	{	flag=0;
		for(i=1;2*i<=n;i++)
		{
			if(2*i+1 > n)
			{
				
				if(a[i] < a[2*i])
				{
					
					a[i]=a[i]+a[2*i]-(a[2*i]=a[i]);
					flag=1;
				}
			}
			else if(a[i] < a[2*i] || a[i] < a[2*i+1])
			{	
				flag=1;
				if(max(a[2*i],a[(2*i)+1])==a[2*i])
				{
					a[i]=a[i]+a[2*i]-(a[2*i]=a[i]);
				}
				else
				{
					a[i]=a[i]+a[2*i+1]-(a[2*i+1]=a[i]);
				}
			}
		}
	}
}
int insert(int a[],int ele)
{
	n++;
	a[n]=ele;
	heapify(a,n);
}
void display(int a[],int n)
{	
	int i;
	for(i=1;i<=n;i++)
	printf("%d \t",a[i]);
	printf("\n");
}	
void swap(int a[],int n)
{
	a[1]=a[1]+a[n]-(a[n]=a[1]);
	n=n-1;
	heapify(a,n);
}
void delete(int a[])
{
	a[1]=a[1]+a[n]-(a[n]=a[1]);
	printf("removed=%d\n",a[n]);
	n--;
	if(n==0)
	printf("empty\n");
	else
	heapify(a,n);
}
void heap(int a[])
{
	int m;
	for(m=n;m>0;m--)
	{
		swap(a,m);
	}
}
int isheap(int a[],int n)
{
		int i;
	for ( i=1;2*i<=n;i++)
	{
		if(2*i+1 > n)
		{
			if(a[i] < a[2*i])
			return 0;
		}
		else if(a[i] < a[2*i] || a[i] < a[2*i+1])
		return 0;
		
	}
	return 1;
}
void heapsort(int a[])
{	
	int i=n;
	for(i;i>0;i--)
	{
		heapify(a,i);
		a[1]+=a[i]-(a[i]=a[1]);
	}
}
void main()
{
	int a[100],i,op,ele,m;
	printf("enter size\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{	printf("enter %d element\n",i);
		scanf("%d",&a[i]);
	}
	do{
		printf("1 heapify\n2 insert\n4 heap-sort\n6 display\n5 delete\n7 is heap?\n8 direct heap sort\n");
		printf("\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:heapify(a,n);
				for(i=1;i<=n;i++)
				printf("heapified=%d\n",a[i]);
			break;
			case 2:printf("enter element\n");
				scanf("%d",&ele);
				insert(a,ele);
			break;
			case 6:display(a,n);
			break;
			case 3:swap(a,n);
			break;
			case 4:heap(a);
				for(i=1;i<=n;i++)
				printf("heapified=%d\n",a[i]);
			break;
			case 5:delete(a);
			break;
			case 7: if(isheap(a,n))
				printf("heap\n");
				else
				printf("not\n");
			break;
			case 8:
						m=n;
					heapsort(a);
					for(i=1;i<=m;i++)
				printf("heap_sort=%d\n",a[i]);
			break;
		}
			
	}while(op!=9);
}
