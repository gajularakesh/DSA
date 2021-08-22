//Program to find cycle in graph
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool Find(int n,int U[],int i) {
	for(int t=0;t<n;t++) {
		if(U[t]==i) {
			return true;
		}
	}
	return false;
}

void Union(int n,int U[],int i,int j) {
	for(int k=0;k<n;k++) {
		if((!Find(n,U,i))&&(U[k]==-1)) {
			U[k]=i;
			break;
		}
	}
	for(int k=0;k<n;k++) {
		if((!Find(n,U,j))&&(U[k]==-1)) {
			U[k]=j;
			break;
		}
	}
}

bool UnionFind(int n, int A[][10]) {
	int U[10],i,j;
	for(i=0;i<n;i++)
		U[i]=-1;
	for(i=0;i<n;i++) {
		for(j=i;j<n;j++) {
			if(A[i][j]!=0) {
				if(Find(n,U,i)&&Find(n,U,j))
					return true;
				else
					Union(n,U,i,j);
			}
		}
	}
	return false;
}

void main() {
	int A[10][10], n, i, j;
	printf("Enter n: ");
	scanf("%d",&n);
	printf("Enter adjacency matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&A[i][j]);
	if(UnionFind(n,A))
		printf("Cycle found\n");
	else
		printf("Cycle not found\n");
}