#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int main()
{
int i,a[100000],n,j;
float t;
printf("enter size:\n");
scanf("%d",&n);

srand(time(0));

	for (i=0;i<n;i++)
	{	
		a[i]=rand();
	}
	
//for(j=0;j<n;j++)
//printf("%d ",a[j]);

printf("\n");	


t=clock();
printf("starting time=%f\n",t);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j< n-i-1;j++)
			{
				if(a[j] > a[j+1])
				{
					a[j]=a[j]+a[j+1]-(a[j+1]=a[j]);
				}
			}
	}
t=(clock()-t)/CLOCKS_PER_SEC;

printf("time taken to execute=%f \n",t);
}
