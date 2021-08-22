#include<stdio.h>
int  merge(int [],int,int);
int  mergesort(int [],int,int,int);
 int main()
 {
 	int n,i,a[100];
 	printf("enter the size of the array\n");
 	scanf("%d",&n);
 	printf("entre the elements in the array\n");
 	for(i=0;i<n;i++)
 	{
 		scanf("%d",&a[i]);
 	}
 	merge(a,0,n-1);
 	for(i=0;i<n;i++)
 	{
 		printf(" %d ",a[i]);
 	}
 }
 int merge(int a[100],int start,int end)
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
int mergesort(int a[100],int start,int mid,int end)
 {
 	int  i,j,k=0,b[100];
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
 				k++;
 				j++;
 			}
 		}
 			while(i<=mid)
 			{
 				b[k]=a[i];
 				i++; 
 				k++;
 			}
 			while(j<=end)
 			{
 				b[k]=a[j];
 				k++;
 				j++;
 			}
 			
 			k=0;
 			for(i=start;i<=end;i++)
 			{
 				a[i]=b[k];
 				k++;
 			}
 		}
 }
 			
 							
