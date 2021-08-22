#include<stdio.h>
#include<stdlib.h>
struct node
{
	int co;
	int power;
	struct node *next;
};
struct node* insert(struct node *p)
{
	int n;
	
	printf("enter order and give inputs in descending order\n");
	scanf("%d",&n);
	int i=0;
	while(i!=n)
	{
	  struct node *newnode=(struct node*)malloc(sizeof(struct node));
	  newnode->next=NULL;
	  printf("enter co-effiecient\n");
	  scanf("%d",&newnode->co);
	  printf("enter power\n");
	  scanf("%d",&newnode->power);
	  if(p==NULL)
	  p=newnode;
	  else
	  {			
	  		struct node *temp=p;   	  		
	  		while(temp->next!=NULL)
	  		{
	  			temp=temp->next;
			}	
			temp->next=newnode;
      }
      
      i++;
	}
	return p;
}
void display(struct node *p)
{
	while(p!=NULL)
	{
		printf("%d x^",p->co);
		printf("%d+",p->power);
		p=p->next;
	}
	printf("\n");
	
}

struct node* add_one(struct node *head,int co,int power)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node)),*temp=head;
	newnode->next=NULL;
	newnode->co=co;
	newnode->power=power;
	if(head==NULL)
	head=newnode;
	else
	{
	while(temp->next)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	}
return head;
}
struct node* visual(struct node *p1,struct node *p2)
{
	struct node *head=NULL;
	while(1)
	{	if(p1==NULL && p2==NULL)
		break;
		if(p1->power==p2->power)
		{	
			printf("%d x^%d+",(p1->co)+(p2->co),p1->power);
			head=add_one(head,p1->co+p2->co,p1->power);
			p1=p1->next;
			p2=p2->next;
		}
		else if(p1->power > p2->power )
		{
			printf("%d x^%d+",p1->co,p1->power);
			head=add_one(head,p1->co,p1->power);
			p1=p1->next;
		}
		else
		{
			printf("%d x^%d+",p2->co,p2->power);
			head=add_one(head,p2->co,p2->power);
			p2=p2->next;
		}		
}
return head;
}

void main()
{
	int op;
	struct node *p1=NULL;
	struct node *p2=NULL;
	struct node *head=NULL;
	do{
		printf("\n1=p1 input\n2=p2 input\n3 display\n4 add\n5 visual output and sum\n");
		printf("\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:p1=insert(p1);
			break;
			case 3:printf("enter 1 to poly1 dispaly 2 to poly2 display 3 to sum dispaly\n");
					scanf("%d",&op);
					switch(op)
					{
						case 1:display(p1);
						break;
						case 2:display(p2);
						break;
						case 3:display(head);
						break;
					}
			break;
			case 2:p2=insert(p2);
			break;
			case 5:head=visual(p1,p2);
			break;
		}
	}while(op!=7);
}

