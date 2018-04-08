#include<stdio.h>
#define MAX 50
int a[MAX];

int front=-1,rear=-1;
void enqueue( element)
{
int data;
if(rear==MAX-1)
{
    printf("queue overflow");
}
else{
if(front==-1)
front=0;
printf("enter data");
scanf("%d",&data);
rear=rear+1;
a[rear]=data;
}}
void dequeue()
{
 if(front==-1||front>rear)
 {

     printf("underflow");
 }
  else{
    printf("deleted element is %d",a[front]);
    front=front+1;
  }
}

void display()
{
  int i;
 printf("the elements are:\n");
 for(i=front;i<=rear;i++)

 {
   printf("%d\t",a[i]);
 }

}
int main()
{
int ch,data,n;
while(1)
{
printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
enqueue();
break;
case 2:
dequeue();
break;
case 3:
display();
break;
case 4:
exit(0);
}
}
return 0;
}
