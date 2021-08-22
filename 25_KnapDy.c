//Fractional knapsack program using dynamic programming
#include <stdio.h>
#include <stdlib.h>

void knapsack(int n,int W[],int P[],int *v,int S[],int tw) {
	int i,j,V[10][10],m,w;
	(n<tw)?(m=tw):(m=n);
	for(i=0;i<=m;i++) 
		V[0][i]=V[i][0]=0;
	for(i=1;i<=n;i++)
		for(w=1;w<=tw;w++)
			if(W[i]>w)
				V[i][w]=V[i-1][w];
			else if(W[i]<=w)
				(V[i-1][w]>P[i]+V[i-1][w-W[i]])?(V[i][w]=V[i-1][w]):(V[i][w]=P[i]+V[i-1][w-W[i]]);
	*v=V[n][tw];
	for(i=n,w=tw,j=0;i>0&&w>0;i--)
		if(V[i][w]!=V[i-1][w]) {
			S[j++]=i;
			w-=W[i];
		}
}

void main() {
	int W[100],P[100],v,w,S[100],n,i;
	for(i=0;i<100;i++)
		S[i]=-1;n
	printf("Enter knapsack capacity: ");
	scanf("%d",&w);
	printf("Enter no. of Items: ");
	scanf("%d",&n);
	printf("Enter V,W: ");
	for(i=1;i<=n;i++)
		scanf("%d %d",&P[i],&W[i]);
	knapsack(n,W,P,&v,S,w);
	printf("\nValue: %d\nItems selected: ",v );
	for(i=0;S[i]!=-1;i++)
		printf("%d ",S[i] );
	printf("\n");
}
