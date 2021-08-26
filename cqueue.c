//circular Queue program

#include<stdio.h>

int Queue[100];
int rear;
int front;
int n;

void Insertion()
{
	int item;
	if(front==rear+1||front==0&rear==n-1)
	{
		printf("Queue overflow\n");
	}
	else
	{
		
	    if(rear==(n-1))
		   rear=0;
	    else
		   rear++;
	    printf("Enter the element\n");
	    scanf("%d",&item);
	    Queue[rear]=item;
	}
	if(front==-1)
		front=0;
}

void Deletion()
{
	int item;
	if(front==-1)
		printf("Queue underflow\n");
	else
	{
		item=Queue[front];
		printf("The item %d is deleted\n",item);
	}
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else if(front==n-1)
		front=0;
	else
		front++;
}

void Display()
{
	int i;
	if(front==-1)
		printf("The queue is empty\n");
	else
	{
		if(rear>=front)
	    {
		   for(i=front;i<=rear;i++)
			  printf("%d\t",Queue[i]);
		   printf("\n");
	    }
    	else
    	{
	    	for(i=front;i<n;i++)
	    		printf("%d\t",Queue[i]);
	    	for(i=0;i<=rear;i++)
	    		printf("%d\t",Queue[i]);
		    printf("\n");
	    }
	}
}

void main()
{
	int ch;
	rear=-1;
	front=-1;
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
				Insertion();
				break;
			}
			case 2:
			{
				Deletion();
				break;
			}
			case 3:
			{
				Display();
				break;
			}
		}
		printf("Enter your choice again\n");
		scanf("%d",&ch);
	}
}