//Program to find fibonacci number by dynamic programming
#include <stdio.h>
int fib(int n,int arr[]) {
	int i;
	if(n<=1)
		return n;
	else {
		arr[0]=0;
		arr[1]=1;
		for(i=2;i<=n;i++)
			arr[i]=arr[i-1]+arr[i-2];
		return arr[i];
	}
}
void main() {
	int arr[100],i,n;
	printf("Enter n:");
	scanf("%d",&n);
	printf("fib(%d)=%d\n",n,fib(n,arr) );
}
