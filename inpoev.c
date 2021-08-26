

//infix to postfix

#include<stdio.h>
#include<string.h>
#include<ctype.h> //for isalnum 

char Stack[100];
int top=-1;
char expr[100];
int len;


int priority(char c)
{
	if(c=='(')
		return 0;
	if(c=='+'||c=='-')
		return 1;
	if(c=='*'||c=='/')
		return 2;
	if(c=='^')
		return 3;
}

void PUSH(char c)
{
	top++;
	Stack[top]=c;
}

char POP()
{
	if(top==-1)
		return 0;
	else
	{
		return Stack[top--];
	}
}

void main()
{
	
	char c,x;
	int i;
	printf("Enter the infix expression\n");
	scanf("%s",expr);
	len=strlen(expr);
	
	for(i=0;i<len;i++)
	{
		c=expr[i];
		if(isalnum(c))
			printf("%c",c);
		else
		{
			if(c=='(')
				PUSH(c);
			else
			{
				if(c==')')
				{
					x=POP();
					while(x!='(')
					{
						printf("%c",x);
						x=POP();
					}
				}
				else
				{
					while(priority(Stack[top])>=priority(c))
					{
						x=POP();
						printf("%c",x);
					}
					PUSH(c);
				}
			}
		}
	}
	while(top!=-1)
	{
		x=POP();
		printf("%c",x);
	}
	printf("\n");
}

