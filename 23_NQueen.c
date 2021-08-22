//Brute force approach to solve N-Queen problem

#include <stdio.h>
#include <stdlib.h>

void print(int A[][10],int n) {
	int i,jW;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			printf("%d ",A[i][j] );
		}
		printf("\n");
	}
	printf("\n");
}

void NQueen(int n,int A[][10][10]) {
	int i,j,k,p;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			for(k=0;k<n;k++)
				A[i][j][k]=2;
	for(i=0;i<1;i++) {
		for(j=0;j<n;j++) {
			for(k=0;k<n;k++) {
				if(A[i][j][k]==2) {
					A[i][j][k]=1;
					for(p=0;(j+p<n+j)||(k+p<n+k);p++) {//
						if(j+p<n) {
							if(A[i][j+p][k]!=1) {
								A[i][j+p][k]=0;
							}
						}
						else {
							if(A[i][j+p-n][k]!=1) {
								A[i][j+p-n][k]=0;
							}
						}
						if(k+p<n) {
							if(A[i][j][k+p]!=1) {
								A[i][j][k+p]=0;
							}
						}
						else {
							if(A[i][j][k+p-n]!=1) {
								A[i][j][k+p-n]=0;
							}
						}
						if(j+p<n&&j+p<n) {
							if(A[i][j+p][k+p]!=1) {
								A[i][j+p][k+p]=0;
							}
						}
						else {
							if(A[i][j+p-n][k+p-n]!=1) {
								A[i][j+p-n][k+p-n]=0;
							}
						}
						if(j+p<n&&j+p<n) {
							if(A[i][j+p][k-p]!=1) {
								A[i][j+p][k-p]=0;
							}
						}
						else {
							if(A[i][j-p-n][k+p-n]!=1) {
								A[i][j-p-n][k+p-n]=0;
							}
						}
					}//
				}
			}
		}
		printf("\nSolution is:\n\n");
		//for(i=0;i<n;i++)
			print(A[0],n);
	}
}

void main() {
	int A[10][10][10],n,i,j,k;
	printf("Enter order:");
	scanf("%d",&n);
	NQueen(n,A);
}
