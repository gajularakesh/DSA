  //Dijkstras algorithm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool empty(int n,int visit[])
 {
 	
 	int i;
	for(i=0;i<n;i++)
		if(visit[i]!=-1)
			return false;
	return true;
}

int small_dist(int n,int visit[],int active,int distance[]) {
	int min=9999,near_node=active,i;
	for(i=0;i<n;i++) {
		if(visit[i]!=-1 && distance[i]<min) {
			min=distance[i];
			near_node=i;
		}
	}
	return near_node;
}

void Dijkstras(int n,int A[][10],int near_node,int distance[10],int parent[10]) {
	int visit[10],i,dist;
	for(i=0;i<n;i++) {
		distance[i]=9999;
		visit[i]=i;
		parent[i]=-1;
	}
	distance[near_node]=0;
	while(!empty(n,visit)) {
		near_node=small_dist(n,visit,near_node,distance);
		for(i=0;i<n;i++) {
			if(A[near_node][i]!=0 && visit[i]!=-1) {
				dist=distance[near_node]+A[near_node][i];
				if(dist<distance[i]) {
					distance[i]=dist;
					parent[i]=near_node;
				}
			}
		}
		visit[near_node]=-1;
	}
}

void main() {
	int A[10][10],n,start_node, distance[10], parent[10], i, j;
	printf("Enter n: ");
	scanf("%d",&n);
	printf("Enter adjacency matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&A[i][j]);
	printf("Enter start node:");
	scanf("%d",&start_node);
	Dijkstras(n,A,start_node,distance,parent);
	printf("Node\tDistance\tParent\n");
	for(i=0;i<n;i++)
		printf("%d\t%d\t\t%d\n",i,distance[i],parent[i]);
}
