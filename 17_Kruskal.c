//Kruskal's algorithm to find minumum spanning spanning tree
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

void Kruskal(int n,int A[][10]) {
	int T[10][3],i,j,k=0;
	for(i=0;i<n;i++) {
		for(j=i;j<n;j++) {
			if(A[i][j]!=0) {
				T[k][0]=i;
				T[k][1]=j;
				T[k][2]=A[i][j];
				k++;
			}
			A[i][j]=0;
		}
	}
	int pos,min0,min1,min2;
	for(i=0;i<k-1;i++) {//Selection sort
		pos=i;
		min0=T[i][0];
		min1=T[i][1];
		min2=T[i][2];
		for(j=i+1;j<k;j++) {
			if(min2>T[j][2]) {
				min0=T[j][0];
				min1=T[j][1];
				min2=T[j][2];
				pos=j;
			}
		}
		T[pos][0]=T[i][0];
		T[i][0]=min0;
		T[pos][1]=T[i][1];
		T[i][1]=min1;
		T[pos][2]=T[i][2];
		T[i][2]=min2;
	}
	//for(i=0;i<k;i++)
		//printf("i-%d j-%d w-%d\n",T[i][0],T[i][1],T[i][2] );
	for(i=0;i<k;i++) {
		A[T[i][0]][T[i][1]]=T[i][2];
		A[T[i][1]][T[i][0]]=T[i][2];
		if(UnionFind(n,A)) {
			A[T[i][0]][T[i][1]]=A[T[i][1]][T[i][0]]=0;
		}
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
	Kruskal(n,A);
	printf("\nMinumum spanning tree:\n");
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			printf("%d ",A[i][j] );
		}
		printf("\n");
	}
}