#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *front=NULL,*rear=NULL,*temp=NULL;
int count=0,size=3;
void enqueue()
{int data;
temp=(struct node*)malloc(sizeof(struct node));
if(count!=size)
{
printf("enter data");
scanf("%d",&data);
temp->data=data;
temp->next=NULL;
if(front==NULL)
{
	rear=front=temp;
}
else
{
	rear=rear->next;
	rear=temp;
}}
else{
	printf("queue overflow");
}
}
void dequeue()
{
	struct node*temp=front;
	if(front!=NULL)
	{
		front =front->next;
		free(temp);
	}
	else{
		printf("underflow");
	}
	
}
void display()
{
	struct node*head=front;
	while(head!=NULL)
	{
	printf("%d",head->data);
	head=head->next;
	}
}
int main(void) {
	// your code goes here
	int ch;
	while(1)
	{
		printf("enter your choice:\n1.enqueue\n2.dequeue\n3.display");
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
		default:
		exit(0);
	}
	}
	return 0;
}
