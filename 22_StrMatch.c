//Bruteforce string match algorithm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int BruteforceStringMatch(char str[],char key[]) {
	int i,j,k,c;
	for(i=0;i<=strlen(str)-strlen(key);i++) {
		for(c=0,j=0,k=i;j<strlen(key);j++,k++)
		 {
			if(key[j]==str[k])
				c++;
			else
				break;
		}
		if(c==strlen(key))
		printf("%d\n",i);
	}
	return -1;
}

void main() {
	char str[100],key[100];
	int pos;
	printf("Enter String:");
	scanf("%s",str);
	printf("Enter Key:");
	scanf("%s",key);
	pos=BruteforceStringMatch(str,key);
//	if(pos!=-1)
//		printf("Key found from index-%d\n",pos );
//	else
//		printf("Key not found\n");
}
