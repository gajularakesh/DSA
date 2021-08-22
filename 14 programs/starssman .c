#include<stdio.h>
int matA[100][100],matB[100][100],matC[100][100];
int main(){
 int n,i,j;
 printf("Enter the order: ");
 scanf("%d",&n);
 printf("Enter the elements 1: ");
 for(i = 0; i < n; i++)
 {
     for(j = 0; j < n; j++)
     {
         scanf("%d",&matA[i][j]);
     }
 }
 printf("Enter the elements 1: ");
 for(i = 0; i < n; i++)
 {
     for(j = 0; j < n; j++)
     {
         scanf("%d",&matB[i][j]);
     }
 }
 mult(0,0,0,0,n);

 printf("\nAfter multiplication: \n");

 for(i = 0; i < n; i++)
 {
     for(j = 0; j < n; j++)
     {
         printf("%d ",matC[i][j]);
     }
     printf("\n");
 }
}
