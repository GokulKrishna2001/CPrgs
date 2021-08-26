//bst new

#include<stdio.h>
#include<malloc.h>

struct node
{
	struct node *left;
	int info;
	struct node *right;
}*root=NULL;

int s=0;

void insertion()
{
	struct node *new=(struct node*)malloc(sizeof(struct node));
	
	printf("Enter the element:");
	scanf("%d",&new->info);
	
	new->left=NULL;
	new->right=NULL;
	
	if(root==NULL)
	root=new;
	else
	{
		struct node *ptr=root;
		struct node *cpt=NULL;
		
		while(ptr!=NULL)
		{
			cpt=ptr;
			if(new->info<ptr->info)
			ptr=ptr->left;
			else
			ptr=ptr->right;
		}
		
		if(new->info<cpt->info)
		cpt->left=new;
		else
		cpt->right=new;
	}
}

struct node *minimum(struct node *temp)
{
	if(temp->left!=NULL)
	return minimum(temp->left);
	else
	return temp;
}

struct node *deletion(struct node *node,int data)
{
	if(node==NULL)
	{
		printf("Empty\n");
		return NULL;
	}
	
	if(data<node->info)
	node->left=deletion(node->left,data);
	
	else if(data>node->info)
	node->right=deletion(node->right,data);
	
	else
	{
		if(node->left==NULL&&node->right==NULL)
		{
			free(node);
			return NULL;
		}
		else if(node->left==NULL||node->right==NULL)
		{
			struct node *temp;
			if(node->left==NULL)
			temp=node->right;
			else
			temp=node->left;
			free(node);
			return temp;
		}
		else
		{
			struct node *temp=minimum(node->right);
			node->info=temp->info;
			node->right=deletion(node->right,temp->info);
		}
		
		return node;
	}
}

struct node *searching(struct node *node,int data)
{
	if(node==NULL)
	{
		printf("Empty\n");
		return NULL;
	}
	else if(node->info==data)
	{
		printf("Element is found\n");
		s=1;
	}
	else if(data<node->info)
	searching(node->left,data);
	else 
	searching(node->right,data);
}

void inOrder(struct node *node)
{
	if(node!=NULL)
	{
		inOrder(node->left);
		printf("%d\t",node->info);
		inOrder(node->right);
	}
}

void main()
{
	int c;
	int data;
	printf("Binary Search Trees!\n");
	printf("Enter your choice\n");
	printf("1.Insert an Element\n2.Delete an element\n3.Display the BST\n4.To search an element\n5.Exit\n");
	scanf("%d",&c);
	while(c>=1&&c<=4)
	{
		switch(c)
		{
			case 1:
			{
				insertion();
				break;
			}
			case 2:
			{
				printf("Enter the value to be deleted\n");
				scanf("%d",&data);
				deletion(root,data);
				printf("Deleted %d.\n",data);
				break;
			}
		    case 3:
		    {
				if(root==NULL)
				{
					printf("The Binary Search Tree is empty\n");
					break;
				}
				printf("The BST:");
			    inOrder(root);
				printf("\n");
			    break;
		    }
			case 4:
			{
				printf("Enter the element to be searched\n");
				scanf("%d",&data);
				searching(root,data);
				if(s==0)
	            printf("The entered element is not found!\n");
				s=0;
				break;
			}
			
	    }
		printf("Enter your choice again\n");
    	scanf("%d",&c);
	}
	printf("Thank You\n");
}