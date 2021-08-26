//infix to postfix and evaluation

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

char Stack[100];
char post[100];
char expr[100];
int top=-1;
int p=0;
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
	return Stack[top--];
}

void postEval()
{
	int i;
	int m,n;
	int val;
	char c;
	
	for(i=0;i<p;i++)
	{
		c=post[i];
		if(isdigit(c))
		PUSH(c-'0');
		else if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
		{
			m=POP();
			n=POP();
			
			switch(c)
			{
				case '+':
				val=n+m;
				break;
				
				case '-':
				val=n-m;
				break;
				
				case '*':
				val=n*m;
				break;
				
				case '/':
				val=n/m;
				break;
				
				case '^':
				val=pow(n,m);
				break;
			}
			PUSH(val);
		}
	}
	printf("The value of the expression is %d\n",val);
}

void main()
{
	int i;
	char c,x;
	
	printf("Enter the expression:");
	gets(expr);
	len=strlen(expr);
	
	for(i=0;i<len;i++)
	{
		c=expr[i];
		if(isalnum(c))
		post[p++]=c;
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
						post[p++]=x;
						x=POP();
					}
				}
				else
				{
					while(priority(Stack[top])>=priority(c))
					{
						x=POP();
						post[p++]=x;
					}
					PUSH(c);
				}
			}
		}
	}
	
	while(top!=-1)
	{
		x=POP();
		post[p++]=x;
	}
	
	printf("The postfix expression:");
	for(i=0;i<p;i++)
	printf("%c",post[i]);
	printf("\n");
	
	postEval();
}

