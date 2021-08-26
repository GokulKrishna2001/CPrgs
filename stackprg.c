//Gokul Krishna S, S3R2, Roll no 16
//stack program in C

#include<stdio.h>

int top;
int Stack[100];

void PUSH(int Stack[],int n)
{
	int item;
	if(top>=n)
		printf("\nStack Overflow!!No element can be further inserted.\n");
	else
	{
		printf("\nEnter the element to be inserted or to be Pushed\n");
		scanf("%d",&item);
		Stack[top]=item;
		top++;
	}
}

void POP(int Stack[])
{
	int item;
	if(top==0)
		printf("\nStack Underflow!!NO element to be deleted.\n");
	else
	{
		top--;
		item=Stack[top];
		printf("\nThe item:%d is deleted from the stack\n",item);
	}
}

void DISPLAY(int Stack[])
{
	if(top==0)
		printf("\nThe stack is empty.\n");
	else
	{
		int i;
		printf("\nThe elements in the Stack are:\n");
		for(i=top-1;i>=0;i--)
			printf("%d\t",Stack[i]);
		printf("\n");
	}
}

void main()
{
	int n;
	int ch;
	top=0;
	printf("Enter the array size\n");
	scanf("%d",&n);
	
	printf("Enter your choice:\n");
	printf("1)To Push\n");
	printf("2)To Pop\n");
	printf("3)To Display\n");
	scanf("%d",&ch);
	
	while(ch>=1&&ch<=3)
	{
		switch(ch)
		{
			case 1:
			{
				PUSH(Stack,n);
				break;
			}
			case 2:
			{
				POP(Stack);
				break;
			}
			case 3:
			{
				DISPLAY(Stack);
				break;
			}
		}
		printf("\nEnter your choice again:\n");
	    printf("1)To Push\n");
	    printf("2)To Pop\n");
	    printf("3)To Display\n");
		printf("4)To Exit\n");
		scanf("%d",&ch);
	}
}