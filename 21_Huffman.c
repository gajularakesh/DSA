//Program for Huffman algorithm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct tree {
	char C;
	int F;
	struct tree *left,*right;
}temp,*h1,*h2,*h3;

void heapify(struct tree *tree[],int n) {
	int i,f=1;
	while(f) {
		f=0;
		for(i=1;2*i<=n;i++) {
			if(2*i+1>n) {
				if(tree[i]->F>tree[2*i]->F) {
					f=1;
					temp=*tree[i];
					*tree[i]=*tree[2*i];
					*tree[2*i]=temp;
				}
			}
			else {
				if(tree[i]->F>tree[2*i]->F||tree[i]->F>tree[2*i+1]->F) {
					f=1;
					if(tree[2*i]->F<tree[2*i+1]->F) {
						temp=*tree[i];
						*tree[i]=*tree[2*i];
						*tree[2*i]=temp;
					}
					else {
						temp=*tree[i];
						*tree[i]=*tree[2*i+1];
						*tree[2*i+1]=temp;
					}
				}
			}
		}
	}
}

void add(struct tree *tree[],struct tree *ele,int *n) {
	(*n)++;
	tree[*n]=(struct tree*)malloc(sizeof(struct tree));
	*tree[*n]=*ele;
	heapify(tree,*n);
}

struct tree* del(struct tree *tree[],int *m) {
	//tree[1]+=tree[m]-(tree[m]=tree[1]);
	temp=*tree[1];
	*tree[1]=*tree[*m];
	*tree[*m]=temp;
	(*m)--;
	heapify(tree,*m);
	return tree[(*m)+1];
}

void inorder(struct tree *root,int i,int Code[],char Char[],int k) {
	if(root!=NULL) {

		if(root->left==NULL&&root->right==NULL) {
			for(int j=0;j<k;j++) {
				if(Char[j]==root->C) {
					Code[j]=i;
					break;
				}
			}
		}

		inorder(root->left,10*i+1,Code,Char,k);
		//printf("%d ",root->F );
		inorder(root->right,10*i,Code,Char,k);
	}
}

void Huffman(char Char[],int Freq[],int Code[],int k) {
	int i,j=k;
	struct tree *h[100];
	for(i=1;i<=k;i++) {
		h[i]=(struct tree*)malloc(sizeof(struct tree));
		h[i]->left=h[i]->right=NULL;
		h[i]->C=Char[i-1];
		h[i]->F=Freq[i-1];
	}
	heapify(h,k);
	while(k!=1) {
		h1=del(h,&k);
		h2=del(h,&k);
		h3=(struct tree*)malloc(sizeof(struct tree));
		h3->left=h1;
		h3->right=h2;
		h3->F=h1->F+h2->F;
		add(h,h3,&k);
	}
	inorder(h[1],1,Code,Char,j);
//	printf("\n");
}

void main() {
	char str[100],Char[100],CODE[100][10];
	int Freq[100],i,j,k,c,Code[100];
	printf("\nEnter string:");
	scanf("%s",str);
	c=k=0;
	for(i=0;i<strlen(str);i++) {
		c=0;
		for(j=0;j<i;j++) {
			if(str[i]==str[j])
				c++;
		}
		if(c==0)
			Char[k++]=str[i];
	}
	for(i=0;i<strlen(Char);i++) {
		c=0;
		for(j=0;j<strlen(str);j++) {
			if(Char[i]==str[j])
				c++;
		}
		Freq[i]=c;
	}
	Huffman(Char,Freq,Code,k);
	for(i=0;i<k;i++) {
		sprintf(CODE[i],"%d",Code[i]);
	for(j=0;j<strlen(CODE[i]);j++)
		CODE[i][j]=CODE[i][j+1];
	}
	printf("\nChar\tFreq\tCode\n");
	for(i=0;i<k;i++)
		printf("%c\t%d\t%s\n",Char[i],Freq[i],CODE[i] );
	printf("\nEncoded string:");
	for(i=0;i<strlen(str);i++) {
		for(j=0;j<k;j++) {
			if(str[i]==Char[j]) {
				printf("%s ",CODE[j] );
				break;
			}
		}
	}
	printf("\n");
}