//Polynomial addition using Doubly Linked List

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
	int coeff;
	int expo;
	struct node *link;
	struct node *prev;
}*first=NULL,*first1=NULL,*first2=NULL;

int count;

void create()
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	struct node *cpt=(struct node*)malloc(sizeof(struct node));
	
	printf("Enter the co-efficient:");
	scanf("%d",&ptr->coeff);
	printf("Enter the exponent:");
	scanf("%d",&ptr->expo);
	printf("\n");  
	
	if(count==1)
	{
		
		if(first1==NULL)
	    {
			first1=ptr;
			ptr->prev=NULL;
			ptr->link=NULL;
	    }
	    else
	    {
			cpt=first1;
			while(cpt->link!=NULL)
			{
				cpt=cpt->link;
			}
			cpt->link=ptr;
			ptr->prev=cpt;
    	    ptr->link=NULL;
	    }
	}
	else
	{
		if(first2==NULL)
	    {
			
			first2=ptr;
			ptr->link=NULL;
			ptr->prev=NULL;
	    }
	    else
	    {
			cpt=first2;
			while(cpt->link!=NULL)
			{
				cpt=cpt->link;
			}
			cpt->link=ptr;
			ptr->prev=cpt;
    	    ptr->link=NULL;
	    }
	}
	
}

void PolyAdd()
{
	
	struct node *ptr1=(struct node*)malloc(sizeof(struct node));
	struct node *ptr2=(struct node*)malloc(sizeof(struct node));
	
	
	ptr1=first1;
	ptr2=first2;
	
	while(ptr1!=NULL&&ptr2!=NULL)
	{
		struct node *ptr=(struct node*)malloc(sizeof(struct node));
		struct node *cpt=(struct node*)malloc(sizeof(struct node));
		
		if(ptr1->expo>ptr2->expo)
		{
			ptr->coeff=ptr1->coeff;
			ptr->expo=ptr1->coeff;
			ptr1=ptr1->link;
		}
		else if(ptr2->expo>ptr1->expo)
		{
			ptr->coeff=ptr2->coeff;
			ptr->expo=ptr2->expo;
			ptr2=ptr2->link;
		}
		else
		{
			ptr->coeff=ptr1->coeff+ptr2->coeff;
			ptr->expo=ptr2->expo;
			ptr1=ptr1->link;
			ptr2=ptr2->link;
		}
		
		
		if(first==NULL)
	    {
	    	first=ptr;
	    	ptr->link=NULL;
			ptr->prev=NULL;
	    }
    	else
    	{
	    	cpt=first;
	        while(cpt->link!=NULL)
	        {
		       cpt=cpt->link;
	        }
	        cpt->link=ptr;
			ptr->prev=cpt;
	        ptr->link=NULL;
	    }
	}
	
	while(ptr1!=NULL)
	{
		struct node *ptr=(struct node*)malloc(sizeof(struct node));
		struct node *cpt=(struct node*)malloc(sizeof(struct node));
		
		ptr->coeff=ptr1->coeff;
		ptr->expo=ptr1->expo;
		cpt->link=ptr;
		ptr->prev=cpt;
		ptr1=ptr->link;
	}
	
	while(ptr2!=NULL)
	{
		struct node *ptr=(struct node*)malloc(sizeof(struct node));
		struct node *cpt=(struct node*)malloc(sizeof(struct node));
		
		ptr->coeff=ptr2->coeff;
		ptr->expo=ptr2->expo;
		cpt->link=ptr;
		ptr->prev=cpt;
		ptr2=ptr->link;
	}
}

void Display()
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	
	ptr=first;
	
	printf("The final expression:");
	while(ptr!=NULL)
	{
		printf("%dx^%d",ptr->coeff,ptr->expo);
		ptr=ptr->link;
		if(ptr!=NULL)
			printf("+");
	}
	printf("\n");
}

void main()
{
	int n,i;
	printf("Enter the number of terms for expression 1:\n");
	scanf("%d",&n);
	printf("Enter the respective values for each terms in expression 1\n");
	for(i=0;i<n;i++)
	{
		count=1;
		create();
	}
	printf("Enter the number of terms for expression 2:\n");
	scanf("%d",&n);
	printf("Enter the respective values for each terms in expression 2\n");
	for(i=0;i<n;i++)
	{
		count=2;
		create();
	}
	PolyAdd();
	Display();
	printf("The End\n");
}