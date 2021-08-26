//implementing a DQ using array program

#include<stdio.h>
int DQ[100];
int front;
int rear;
int n;

void irear()
{
	int item;
	if(front==rear+1||front==0&rear==n-1)
		printf("Deque overflow.\n");
	else
	{
		if(rear==-1)
			rear=front=0;
		else if(rear==n-1)
			rear=0;
		else
		    rear++;
	    printf("Enter the item to be inserted:\n");
		scanf("%d",&item);
		DQ[rear]=item;
		
	}
}

void ifront()
{
	int item;
	if(front==rear+1||front==0&rear==n-1)
		printf("Deque overflow.\n");
	else
	{
		printf("Enter the element to be inserted:\n");
	    scanf("%d",&item);
        if(front==-1)
	    	front=rear=0;
	    else if(front==0)
		    front=n-1;
	    else
		    front--;
        DQ[front]=item;
	}
}

void drear()
{
	int item;
	if(rear==-1)
		printf("Deque underflow.\n");
	else
	{
		item=DQ[rear];
		printf("%d is deleted.\n",item);
	}
	if(front==rear)
		front=rear=-1;
	else if(rear==0)
		rear=n-1;
	else
		rear--;
}

void dfront()
{
	int item;
	if(front==-1)
		printf("Deque underflow.\n");
	else
	{
		item=DQ[front];
		printf("%d is deleted.\n",item);
	}
	if(front==rear)
		front=rear=-1;
	else if(front==n-1)
		front=0;
	else
		front++;
}

void Display()
{
	int i;
	if(front==-1)
		printf("Deque is empty.\n");
	if(rear>=front)
	{
		for(i=front;i<=rear;i++)
			printf("%d\t",DQ[i]);
		printf("\n");
	}
	else
	{
		for(i=front;i<n;i++)
			printf("%d\t",DQ[i]);
		for(i=0;i<=rear;i++)
			printf("%d\t",DQ[i]);
		printf("\n");
	}
}

void dqinput()
{
	int ch;
	printf("Enter the choice:\n");
	printf("1) Insertion from rear.\n");
	printf("2) Deletion from rear.\n");
	printf("3) Deletion from front.\n");
	printf("4) Display\n");
	printf("5) Exit\n");
	scanf("%d",&ch);
	
	while(ch>=1&&ch<=4)
	{
		switch(ch)
		{
			case 1:
			{
				irear();
				break;
			}
			case 2:
			{
				drear();
				break;
			}
			case 3:
			{
				dfront();
				break;
			}
			case 4:
			{
				Display();
				break;
			}
		}
		printf("Enter the choice again.\n");
		scanf("%d",&ch);
	}
}

void dqoutput()
{
	int ch;
	printf("Enter the choice:\n");
	printf("1) Insertion from rear.\n");
	printf("2) Insertion from front.\n");
	printf("3) Deletion from front.\n");
	printf("4) Display\n");
	printf("5) Exit\n");
	scanf("%d",&ch);
	
	while(ch>=1&&ch<=4)
	{
		switch(ch)
		{
			case 1:
			{
				irear();
				break;
			}
			case 2:
			{
				ifront();
				break;
			}
			case 3:
			{
				dfront();
				break;
			}
			case 4:
			{
				Display();
				break;
			}
		}
		printf("Enter the choice again.\n");
		scanf("%d",&ch);
	}
}

void main()
{
	rear=-1;
	front=-1;
	int qc;
	printf("Enter the string size.\n");
	scanf("%d",&n);
	printf("Enter the choice:\n");
	printf("1) Input restricted\n");
	printf("2) Output restricted\n");
	scanf("%d",&qc);
	switch(qc)
	{
		case 1:
		{
			dqinput();
			break;
		}
		case 2:
		{
			dqoutput();
			break;
		}
		default:
		{
			printf("Wrong choice\n");
			break;
		}
	}
}