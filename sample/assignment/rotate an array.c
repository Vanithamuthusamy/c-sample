#include <stdio.h>
int main(void) {
	int i,temp[10],rot,a[10],n;
	scanf("%d",&rot);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
	}
	for(i=0;i<rot;i++)
	{
	temp[i]=a[i];
	}
	for(i=0;i<n-rot;i++)
	{
	a[i]=a[i+rot];
	}
	for(i=0;i<n;i++)
	{
	a[n-rot+i]=temp[i];
	}
	for(i=0;i<n;i++)
	{
	printf("%d",a[i]);
	}
	return 0;
}
