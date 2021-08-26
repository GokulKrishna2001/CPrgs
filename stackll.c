//Stack using linked list

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	int info;
	struct node *link;
}*first=NULL;

void PUSH()
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

void POP()
{
	int item; 
	
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	struct node *cpt=(struct node*)malloc(sizeof(struct node));
	
	if(first==NULL)
		printf("Underflow\n");
	else
	{
		ptr=first;
		cpt=first;
		while(ptr->link!=NULL)
		{
			cpt=ptr;
			ptr=ptr->link;
		}
		if(ptr==cpt)
		{
			printf("%d has been deleted\n",ptr->info);
			free(ptr);
			first=NULL;
		}
		else
		{
	    	cpt->link=NULL;
    	   	printf("%d has been deleted\n",ptr->info);
    		free(ptr);
		}
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
		printf("The linked list:");
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
	printf("Stack using Linked List\n");
	printf("Enter your choice:\n");
	printf("1.PUSH an element\n");
	printf("2.POP an element\n");
	printf("3.Display the stack\n");
	printf("4.Exit\n");
	scanf("%d",&ch);
	
	while(ch>=1&&ch<=3)
	{
		switch(ch)
		{
			case 1:
			{
				PUSH();
				break;
			}
			case 2:
			{
				POP();
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
