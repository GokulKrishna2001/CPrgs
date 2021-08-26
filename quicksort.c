//quicksort

/*
#include<stdio.h>

int m[50];
int n;
int j;

int partition(int l, int h)
{
	int temp;
	int pivot=m[l];
	int i=l;
	int j=h;
	
	while(i<j)
	{
		do
		{
			i++;
		}while(m[i]<=pivot);
		do
		{
			j--;
		}while(m[j]>pivot);
		if(i<j)
		{
			temp=m[i];
			m[i]=m[j];
			m[j]=temp;
		}
	}
	temp=m[l];
	m[l]=m[j];
	m[j]=temp;
	
	return j;
}

void QuickSort(int l,int h)
{
	if(l<h)
	{
		j=partition(l,h);
		QuickSort(l,j);
		QuickSort(j+1,h);
	}
}

void Display()
{
	int i;
	printf("The sorted array:");
	for(i=0;i<n;i++)
	printf("%d\t",m[i]);
	printf("\n");
}
	

void main()
{
	int i;
	int l,h;
	printf("Quick Sort\n");
	printf("Enter the number of array elements\n");
	scanf("%d",&n);
	printf("Enter the array elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&m[i]);
	l=0;
	h=n;
	QuickSort(l,h);
	Display();
}
*/

//Quicksort try #2

#include<stdio.h>
int a[50];
int j;
int n;

int Partition(int l,int h)
{
	int temp;
	int pivot=a[l];
	int i=l;
	int j=h;
	
	while(i<j)
	{
		do
		{
			i++;
		}while(a[i]<=pivot);
		do
		{
			j--;
		}while(a[j]>pivot);
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[l];
	a[l]=a[j];
	a[j]=temp;
	
	return j;
}

void QuickSort(int l,int h)
{
	if(l<h)
	{
		j=Partition(l,h);
		QuickSort(l,j);
		QuickSort(j+1,h);
	}
}

void Display()
{
	int i;
	printf("The sorted array:");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	printf("\n");
}

void main()
{
	int i;
	int l,h;
	printf("Quick Sort\n");
	printf("Enter the array size:");
	scanf("%d",&n);
	printf("Enter the array elements:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	l=0;
	h=n;
	
	QuickSort(l,h);
	Display();
}