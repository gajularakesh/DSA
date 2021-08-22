#include<stdio.h>
#include<stdlib.h>
int max(int a,int b)
{
	return (a>b)?a:b;
}
int kns(int val[10],int wt[10],int W,int n)
{
	int i,w;
	int k[n+1][W+1];
	for(i=0;i<=n;i++)
	{
		for(w=0;w<=W;w++)
		{
			if(i==0 || w==0)
				k[i][w]=0;
			else if(wt[i-1]<=w)
			{
				k[i][w]=max(val[i-1]+k[i-1][w-wt[i-1]],k[i-1][w]);
			}
			else{
				k[i][w]=k[i-1][w];
			}
		}
	}
	printf("%d",k[n][W]);
	return k[n][W];
	
}
int main()
{
	int n,val[10],wt[10],w,i;
	printf("enter the no of nodes\n");
	scanf("%d",&n);
	printf("enter the val and weights of the items\n");
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&val[i],&wt[i]);
	}
	printf("enter the weight\n");
	scanf("%d",&w);
	i=kns(val,wt,w,n);
	printf("Total profit is::\n%d",i);
}
