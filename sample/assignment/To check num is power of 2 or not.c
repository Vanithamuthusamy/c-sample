#include<stdio.h>
int main(void)
{
int n,r,n1;
scanf("%d",&n);
while(n!=1)
{
n1=n/2;
r=n%2;
n=n1;
if(r==1)
goto LABEL;
}
LABEL:
if(r==0)
printf("Yes");
else
printf("no");
 return 0;
}
