//heap sort try#2

#include<stdio.h>

int heap[100];

void heapify(int n,int i)
{
	int temp;
	int root=i;
	int lchild=2*i+1;
	int rchild=2*i+2;
	
	if(lchild<n&&heap[lchild]>heap[root])
	root=lchild;
	
	if(rchild<n&&heap[rchild]>heap[root])
	root=rchild;
	
	if(root!=i)
	{
		temp=heap[i];
		heap[i]=heap[root];
		heap[root]=temp;
		
		heapify(n,root);
	}
}

void heapSort(int n)
{
	int i;
	int temp;
	for(i=(n/2)-1;i>=0;i--)
	heapify(n,i);
	
	for(i=n-1;i>=0;i--)
	{
		temp=heap[0];
		heap[0]=heap[i];
		heap[i]=temp;
		
		heapify(i,0);
	}
}

void Display(int n)
{
	int i;
	printf("The Sorted array:");
	for(i=0;i<n;i++)
	printf("%d\t",heap[i]);
	printf("\n");
}

void main()
{
	int i;
	int n;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
	scanf("%d",&heap[i]);
	
	printf("The original array:");
	for(i=0;i<n;i++)
	printf("%d\t",heap[i]);
	printf("\n");
	
	heapSort(n);
	Display(n);
}