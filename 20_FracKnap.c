//Program for Fractional Knapsack Algorithm
#include <stdio.h>
#include <stdlib.h>

float FracKnap(int n,int capacity,int P[],int W[]) {
	float R[100],K=0,Profit=0;
	int i,j;
	for(i=0;i<n;i++)
		R[i]=P[i]/W[i];
	int pos,min0,min1;
	float min2;
	for(i=0;i<n-1;i++) {//Selection sort
		pos=i;
		min0=P[i];
		min1=W[i];
		min2=R[i];
		for(j=i+1;j<n;j++) {
			if(min2<R[j]) {
				min0=P[j];
				min1=W[j];
				min2=R[j];
				pos=j;
			}
		}
		P[pos]=P[i];
		P[i]=min0;
		W[pos]=W[i];
		W[i]=min1;
		R[pos]=R[i];
		R[i]=min2;
	}
	i=0;
	while(i<n && K<=capacity) {
		if(K+W[i]<=capacity) {
			K+=W[i];
			Profit+=P[i];
			i++;
		}
		else {
			Profit+=((capacity-K)*P[i])/W[i];
			break;
		}
	}
	return Profit;
}

void main() {
	int i,n,P[100],W[100],capacity;
	printf("Enter no. of items:");
	scanf("%d",&n);
	printf("Enter Knapsack capacity:");
	scanf("%d",&capacity);
	for(i=0;i<n;i++) {
		printf("Enter W(%d) P(%d):",i,i );
		scanf("%d %d",&W[i],&P[i]);
	}
	printf("Profit: %f\n", FracKnap(n,capacity,P,W));
}