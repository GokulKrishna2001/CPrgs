//binary trees insertion and traversal

#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *left;
	int info;
	struct node *right;
}*root=NULL;

struct node *insert()
{
	int data;
	struct node *new=(struct node*)malloc(sizeof(struct node));
	
	printf("Enter the node value(Enter -1 to end it)\n");
	scanf("%d",&data);
	
	if(data==-1)
	return NULL;
	else
	new->info=data;
	
	printf("Enter the left child of %d\n",data);
	new->left=insert();
	printf("Enter the right child of %d\n",data);
	new->right=insert();
	
	return new;
}

void preorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		printf("%d\t",ptr->info);
		preorder(ptr->left);
		preorder(ptr->right);
	}
	
}

void main()
{
	printf("Binary Trees\n");
	
	root=insert();
	
	printf("The Pre Order Traversal of the tree:");
	preorder(root);
	
	printf("\n");
	printf("Thank You");
}
	