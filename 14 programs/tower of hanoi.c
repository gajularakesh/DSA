#include<stdio.h>
void toh(int n,char s,char d,char i)
{
	if(n==1)
	printf("move from %c to %c\n",s,d);
	else
	{
		toh(n-1,s,i,d);
		toh(1,s,d,i);
		toh(n-1,i,d,s);
	}
}
void main()
{	int n;
	char a,b,c;
	printf("enter disk number\n");
	scanf("%d",&n);
	toh(n,'s','d','i');
}
