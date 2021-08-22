 //Prim's algorithm to find minumum spanning spanning tree
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool Full(int n,int mstSet[]) {
	for(int i=0;i<n;i++)
		if(mstSet[i]==-1)
			return false;
	return true;
}

int min(int n,int mstSet[],int key[]) {
	int i,min = 9999,u;
	for(i=0;i<n;i++) {
		if(mstSet[i]==-1&&key[i]<min) {
			min = key[i];
			u=i;
		}
	}
	return u;
}

void Prim(int n,int A[][10]) {
	int parent[10],B[10][10],mstSet[10],key[10],u,v,i,j,k;
	for(i=0;i<n;i++) {
		key[i]=9999;
		mstSet[i]=-1;
		for(j=0;j<n;j++) {
			B[i][j]=A[i][j];
			A[i][j]=0;
		}
	}
	key[0]=0;
	parent[0]=-1;
	while(!Full(n,mstSet)) {
		u=min(n,mstSet,key);
		mstSet[u]=u;
		for(v=0;v<n;v++) {
			if(B[u][v]!=0 && B[u][v]<key[v] && mstSet[v]==-1) {
				key[v]=B[u][v];
				parent[v]=u;
			}
		}
	}
	for(v=1;v<n;v++) {
		//printf("i-%d j-%d w-%d\n",parent[v],v,A[v][parent[v]] );
		A[v][parent[v]]=B[parent[v]][v];
		A[parent[v]][v]=B[parent[v]][v];
	}
}

void main() {
	int A[10][10], n, i, j;
	printf("Enter n: ");
	scanf("%d",&n);
	printf("Enter adjacency matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&A[i][j]);
	Prim(n,A);
	printf("\nMinumum spanning tree:\n");
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			printf("%d ",A[i][j] );
		}
		printf("\n");
	}
}