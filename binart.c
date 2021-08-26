//binary trees insertion and 3 traversals

#include<stdio.h>
#include<malloc.h>

struct node
{
	struct node *left;
	int info;
	struct node *right;
}*root=NULL;

struct node *insert()
{
	struct node *new=(struct node*)malloc(sizeof(struct node));
	int data;
	
	printf("Enter the value:");
	scanf("%d",&data);
	
	if(data==-1)
	return NULL;
	else
	new->info=data;
	
	printf("The left child of %d:\n",data);
	new->left=insert();
	printf("The right child of %d:\n",data);
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

void inorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		printf("%d\t",ptr->info);
		inorder(ptr->right);
	}
}

void postorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d\t",ptr->info);
	}
}

void main()
{
	printf("Binary Trees\n");
	printf("Enter -1 if the addition of a node has to be ceased.\n");
	
	root=insert();
	
	printf("Preorder Traversal:");
	preorder(root);
	printf("\n");
	
	printf("Inorder Traversal:");
	inorder(root);
	printf("\n");
	
	printf("Postorder Traversal:");
	postorder(root);
	printf("\n");
}