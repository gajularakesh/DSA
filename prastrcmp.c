#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int str(char a[50],char b[50])
{
	int i,j,n,k,c=0;
	for(i=0;i<strlen(a)-strlen(b);i++)
	{
		for(j=0,k=i,c=0;j<(strlen(b));j++,c++)
		{
			if(a[k]==b[j])
			{
				c++;
			}
			else
			break;
		}
		if(c==strlen(b))
		return i;
	}
}
int main()
{
	char a[50],b[50];
	int i;
	printf("enter the main string\n");
	scanf("%s",a);
	printf("enter the sub string\n");
	scanf("%s",b);
	i=str(a,b);
	printf("sub string index is found at : %d",i);
	return 0;
}
