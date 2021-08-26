//binary search trees

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
	struct node *left;
	int info;
	struct node *right;
}*root=NULL;

int s=0;//for search function

void insert()
{
	struct node *new=(struct node*)malloc(sizeof(struct node));
	printf("Enter the node value\n");
	scanf("%d",&new->info);
	new->left=NULL;
	new->right=NULL;
	if(root==NULL)
	{
		root=new;
		return;
	}
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

struct node* searching(struct node* node, int data)
{
	if(node==NULL)
	   return node;
	else if(node->info==data)
	{
		printf("Entered element is found!\n");
        s=1;;
	}
	else if(data>node->info)
	   return searching(node->right,data);
	else
	   return searching(node->left,data);
}


struct node* minimum(struct node *temp)
{
	if(temp->left!=NULL)
	   return minimum(temp->left);
	else
	   return temp;
}

struct node* deletion(struct node *node,int data)
{

	if(node==NULL)
	{
		printf("The Tree is empty.\n");
	    return NULL;
	}
	
	if(data<node->info)
		node->left=deletion(node->left,data);
	else if(data>node->info)
	    node->right=deletion(node->right,data);
	else
	{
		//leaf node or for node without any children
		if(node->left==NULL&&node->right==NULL)
		{
			free(node);
			return NULL;
		}
		   
		//for nodes with one child   
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
			
		//for nodes with two children
		else
		{
			struct node *temp=minimum(node->right);
			node->info=temp->info;
			node->right=deletion(node->right,temp->info);
		}
		
		return node;
	}
}


void inOrder(struct node *node)
{
	
	if(node!=NULL)
	{
		//if(node->left!=NULL)
		inOrder(node->left);
		printf("%d\t",node->info);
		//if(node->right!=NULL)
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
				insert();
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
