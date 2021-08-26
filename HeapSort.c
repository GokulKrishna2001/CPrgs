//Heap Sort
#include<stdio.h>

int temp;
int heap[50];

void heapCreation(int n,int i)
{
	int root=i;//the root node 
	int lchild=2*i+1;//the left child
	int rchild=2*i+2;//the right child
	
	if(lchild<n&&heap[lchild]>heap[root])
	{
		root=lchild;
	}
	if(rchild<n&&heap[rchild]>heap[root])
	{
		root=rchild;
	}
	if(root!=i)
	{
		temp=heap[i];
		heap[i]=heap[root];
		heap[root]=temp;
		heapCreation(n,root);
	}
}

void heapSort(int n)
{
	int i;
	for(i=(n/2)-1;i>=0;i--)
	{
		heapCreation(n,i);
	}
	for(i=n-1;i>=0;i--)
	{
		temp=heap[0];
		heap[0]=heap[i];
		heap[i]=temp;
		heapCreation(i,0);
	}
}

void Display(int n)
{
	int i;
	printf("The elements after Heap Sorting:");
	for(i=0;i<n;i++)
	printf("%d\t",heap[i]);
	printf("\n");
}

void main()
{
	int i;
	int n;//size of the heap
	
	printf("Heap Sort\n");
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&heap[i]);
	
	printf("The elements before Heap Sorting:");
	for(i=0;i<n;i++)
	printf("%d\t",heap[i]);
	printf("\n");
	
	heapSort(n);
	Display(n);
	
	printf("Thank You.");
}
