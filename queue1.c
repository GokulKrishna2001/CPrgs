//regular queue

#include<stdio.h>

int Queue[100];
int rear;
int front;

void Insertion(int Queue[], int n)
{
	int item;
	if(rear>=n)
		printf("The Queue is full\n");
	else
	{
		printf("Enter the number to be inserted\n");
		scanf("%d",&item);
		rear++;
		Queue[rear]=item;
		
	}
	
	if(front==0)
		front=1;
}

void Deletion(int Queue[])
{
	int item;
	if(front==0)
		printf("Queue is empty\n");
	
	
	else
	{
		
		item=Queue[front];
		front++;
		printf("The item:%d is deleted\n",item);
		
	}
	
	if(front>rear)
	{
		front=0;
		rear=0;
	}
}

void Display(int Queue[])
{
	int i;
	if(front==0)
		printf("The Queue is empty\n");
	else
	{
		for(i=front;i<=rear;i++)
			printf("%d\t",Queue[i]);
		printf("\n");
	}
}

void main()
{
	int n;
	int ch;
	rear=0;
	front=0;
	printf("Enter the array size\n");
	scanf("%d",&n);
	printf("Enter your choice\n");
	printf("1.Insert an element into the Queue\n");
	printf("2.Delete an element in the Queue\n");
	printf("3.Display the Queue\n");
	printf("4.Exit\n");
	scanf("%d",&ch);
	while(ch>=1&&ch<=3)
	{
		switch(ch)
		{
			case 1:
			{
				Insertion(Queue,n);
				break;
			}
			case 2:
			{
				Deletion(Queue);
				break;
			}
			case 3:
			{
				Display(Queue);
				break;
			}
		}
		printf("Enter your choice again\n");
		scanf("%d",&ch);
	}
}