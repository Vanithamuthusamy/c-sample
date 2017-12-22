#include<stdio.h>
int main()
{
char s1[100];
int i,l,ch=0,num=0,sym=0;
scanf("%[^\n]s",s1);
l=strlen(s1);
for(i=0;i<l;i++)
{
if((s1[i]>='a'&&s1[i]<='z')||(s1[i]>='A'&&s1[i]<='Z'))
   ch++;
else if(s1[i]>='0'&&s1[i]<='9')
  num++;
else
  sym++ ;
}
printf("character:%d\nnumber:%d\nsymbol:%d",ch,num,sym);
}
