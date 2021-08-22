//Program to find eulerian path in given graph
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack {
	int arr[100],top;
}s;

int OddEdgeVertexCount(int n,int A[][10]) {
	int count=0,temp=0,i,j;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(A[i][j]!=0)
				temp++;
		}
		if(temp%2!=0)
			count++;
		temp=0;
	}
	return count;
}

int FirstOddEdgeVertex(int n,int A[][10]) {
	int count=0,i,j;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(A[i][j]!=0)
				count++;
		}
		if(count%2!=0)
			return i;
		count=0;
	}
}

bool Neighbour(int n,int A[][10],int pos,int *i) {
		for(int j=0;j<n;j++)
			if(A[pos][j]!=0) {
				*i=j;
				return true;
			}
		return false;
}

void push(int pos) {
	s.arr[++s.top]=pos;
}

int pop() {
	return s.arr[s.top--];
}

bool Empty() {
	if(s.top==-1)
		return true;
	return false;
}

int Eulerian(int n,int A[][10],int Path[]) {
	int pos=OddEdgeVertexCount(n,A),p=0,i;
	if(pos==0||pos==2) {
		pos=FirstOddEdgeVertex(n,A);
		do {
			if(Neighbour(n,A,pos,&i)) {
				push(pos);
				A[pos][i]=0;
				A[i][pos]=0;
				pos=i;
			}
			else {
				Path[p++]=pos;
				pos=pop();
			}
		}while(!Empty());//&&Neighbour(n,A,pos,&i));
		Path[p++]=pos;
		return p;
	}
	return 0;
}

void main() {
	int A[10][10],Path[100],i,j,n;
	s.top=-1;
	printf("Enter n: ");
	scanf("%d",&n);
	printf("Enter adjacency matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&A[i][j]);
	n=Eulerian(n,A,Path);
	if(n) {
		printf("\nEulerian path is:\n");
		for(i=0;i<n;i++)
			printf("%d->",Path[i] );
		printf("\n");
	}
	else {
		printf("Eulerian path doesn't exist\n");
	}
}