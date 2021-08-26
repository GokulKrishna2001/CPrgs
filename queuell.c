//Queue using linked list

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	int info;
	struct node *link;
}*first=NULL;

void Insert()
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	struct node *cpt=(struct node*)malloc(sizeof(struct node));
	
	printf("Enter the element\n");
	scanf("%d",&ptr->info);
	if(first==NULL)
	{
		first=ptr;
		ptr->link=NULL;
	}
	else
	{
		cpt=first;
	    while(cpt->link!=NULL)
	    {
		   cpt=cpt->link;
	    }
	    cpt->link=ptr;
	    ptr->link=NULL;
	}
}

void Delete()
{
	int item; 
	
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	
	if(first==NULL)
		printf("Underflow\n");
	else
	{
		ptr=first;
		first=ptr->link;
		ptr->link=NULL;
		printf("%d has been deleted\n",ptr->info);
		free(ptr);
	}
}

void Display()
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	
	
	if(first==NULL)
		printf("Underflow\n");
	else
	{
		ptr=first;
		printf("The Queue:");
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->info);
			ptr=ptr->link;
		}
		printf("\n");
	}
}

void main()
{
	int ch;
	printf("Queue using Linked List\n");
	printf("Enter your choice:\n");
	printf("1.Enter an element\n");
	printf("2.Delete an element\n");
	printf("3.Display the Queue\n");
	printf("4.Exit\n");
	scanf("%d",&ch);
	
	while(ch>=1&&ch<=3)
	{
		switch(ch)
		{
			case 1:
			{
				Insert();
				break;
			}
			case 2:
			{
				Delete();
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
	printf("The end\n");
}
