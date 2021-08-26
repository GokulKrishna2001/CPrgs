//sparse matrix

#include<stdio.h>

int rows;
int columns;
int m[20][20];
int n[20][20];

void matrix_input()
{
	int i,j;
	printf("Enter the Sparse matrix elements\n");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		{
			printf("[%d][%d] of the Matrix:",i,j);
			scanf("%d",&m[i][j]);
		}
	}
}

void matrix_sparse()
{
	int i,j,count;
	n[0][0]=rows;
	n[0][1]=columns;
	count=1;
	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		{
			if(m[i][j]!=0)
			{
				n[count][0]=i;
			    n[count][1]=j;
			    n[count][2]=m[i][j];
			    count++;
			}
		}
	}
	n[0][2]=count-1;
}

void matrix_print()
{
	int i;
	printf("The Sparse Matrix representation is given below:\n");
	printf("ROWS\tCOLUMNS\tVAlUES\n");
	for(i=0;i<=n[0][2];i++)
		printf("%d\t%d\t%d\n",n[i][0],n[i][1],n[i][2]);
}

void main()
{
	printf("Enter the number of rows\n");
	scanf("%d",&rows);
	printf("Enter the number of columns\n");
	scanf("%d",&columns);
	
	matrix_input();
	matrix_sparse();
	matrix_print();
}