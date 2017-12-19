
int main()
{
int a[10],b[10],c[10],m,n,i,j;
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i];
}
scanf("%d",&m);
for(j=0;j<m;i++)
{
scanf("%d",&b[i];
}
for(i=0;i<n;i++)
{
c[i]=a[i];
}
for(j=0;j<m;i++)
{
c[j+n]=b[j];
}
for(i=0;i<n+m;i++)
{
printf("%d\t",c[i]);
}
}
