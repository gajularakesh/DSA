//infix to postfix
#include<stdio.h>
#include<string.h>
struct stack
{
	char a[10];
	int top,n;
};
int pre(char c)
{
	if (c=='*'|| c=='/')
		return 3;
	else if(c=='+'||c=='-')
		return 2;
	else
		return -1;
}
void push(struct stack *s,char c)
{
	s->top++;
	s->a[s->top]=c;	
}
char pop( struct stack *s)
{
	s->top--;
	return s->a[(s->top)+1];	
}	

void main()
{	
	struct stack s;
    int i,k;
	s.top=-1;
	char a[10];
	printf("Enter string\n");
	gets(a);
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]>='a'&& a[i]<='z'|| a[i]>='A'&& a[i]<='Z')
		printf("%c",a[i]);
		else if(a[i]=='(')
		push(&s,a[i]); 
		else if(a[i]==')')
		{
			while(s.a[s.top]!='(')
			{
				printf("%c",pop(&s));
			}
			k=pop(&s);
		}
		else 
			{
				
					while(pre(a[i])<=pre(s.a[s.top]) && s.top!=-1)
					{
						printf("%c",pop(&s));
					}
					push(&s,a[i]);	
				
			}
	}
while(s.top!=-1)
	printf("%c",pop(&s));
}



















