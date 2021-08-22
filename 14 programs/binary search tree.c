#include<stdio.h>
#include<stdlib.h>
struct node
{
	int ele;
	struct node *left;
	struct node *right;
};
struct node * create()
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter element to insert\n");
	scanf("%d",&newnode->ele);
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
struct node * insert(struct node *root)
{
	struct node *newnode;
	newnode=create();
	if(root==NULL)
	root=newnode;
	else
	{
		while(1)
		{
			if(newnode->left < root->left)
			{
				if(root->left==NULL)
				{
					root->left=newnode;
					break;
				}
				else
				root=root->left;
			}
			else
			{
				if(root->right==NULL)
				{
					root->right=newnode;
					break;
				}
				else
				root=root->right;
			}
		}
	}
return root;
}
void display(struct node *root)
{
	if(root)
	{
		display(root->left);
		printf("%d",root->ele);
		display(root->right);
	}
}
void main()
{
	struct node *root=NULL;
	int op;
	do{
		printf("1 insert\n2 display\n3 inorder\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				root=insert(root);
			break;
			case 2:display(root);
			break;
		}
	}while(op!=3);
}
