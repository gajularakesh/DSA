#include <stdio.h>
int matA[100][100],matB[100][100],matC[100][100];

void mult(int Arow,int Acol,int Brow,int Bcol,int n){
  if(n==1)
    matC[Arow][Bcol] += matA[Arow][Acol]*matB[Brow][Bcol];
  else{
    mult(Arow,Acol,Brow,Bcol,n/2);
    mult(Arow,Acol+n/2,Brow+n/2,Bcol,n/2);
    mult(Arow,Acol,Brow,Bcol+n/2,n/2);
    mult(Arow,Acol+n/2,Brow+n/2,Bcol+n/2,n/2);
    mult(Arow+n/2,Acol,Brow,Bcol,n/2);
    mult(Arow+n/2,Acol+n/2,Brow+n/2,Bcol,n/2);
    mult(Arow+n/2,Acol,Brow,Bcol+n/2,n/2);
    mult(Arow+n/2,Acol+n/2,Brow+n/2,Bcol+n/2,n/2);}
	}
int main(){
int n,i,j;
printf("Enter the order: ");
scanf("%d",&n);
printf("Enter the elements mat1:\n ");
for(i = 0; i < n; i++)
{
for(j = 0; j < n; j++)
     {
         scanf("%d",&matA[i][j]);
     }
 }
 printf("Enter the elements mat2: \n");
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
