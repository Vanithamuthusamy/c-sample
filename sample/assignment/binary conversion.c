#include <stdio.h>
#include<string.h>
void bin(unsigned n)
{
int a;
if(n>1)
{
a=n/2;
bin(a);
}
printf("%d",n%2);
}
int main(void) {
	char str[10];
	int l,i,num,flag=0;
	scanf("%s",str);
	l=strlen(str);
	for(i=l-1;i>=0;i--)
	{
		if(str[i]=='.')
		{
		flag=1;
		break;
		}
	}
	if(flag==1)
	printf("ERROR");
	else
	{
	num=atoi(str);
	bin(num);
	}
	return 0;
}
