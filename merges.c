//merge sort
/*
#include<stdio.h>

void Merge(int a[],int l,int mid, int h)
{
	int i=l;//for array1
	int j=mid+1;//for array2
	int k;//for final array
	int index=l;//for the temporary array
	int m[50];//temporary array
	
	while(i<=mid&&j<=h)
	{
		if(a[i]<a[j])//comparing the smaller array1 with 2
		{
			m[index]=a[i];
			i++;
		}
		else
		{
			m[index]=a[j];
			j++;
		}
		index++;
	}
	if(i>mid)//when the first array is complete
	{
		while(j<=h)
		{
			m[index]=a[j];
			index++;
			j++;
		}
	}
	else//when the second array is complete
	{
		while(i<=mid)
		{
			m[index]=a[i];
			index++;
			i++;
		}
	}
	
	k=l;
	while(k<index)//copying the elements from the temporary array to the original array
	{
		a[k]=m[k];
		k++;
	}
}

void MergeSort(int a[],int l, int h)
{
	int mid;
	if(l<h)
	{
		mid=(l+h)/2;
		MergeSort(a,l,mid);
		MergeSort(a,mid+1,h);
		Merge(a,l,mid,h);
	}
}

void Display(int a[],int n)
{
	int i;
	printf("The sorted array:");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}

void main()
{
	int a[50],n,i;
	printf("Merge Sort\n");
	printf("Enter the number of elements:\n");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("The original array:");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	
	int l=0;
	int h=n-1;
	
	MergeSort(a,l,h);
	Display(a,n);
	
	printf("Thank You\n");
}

*/

//merge sort try#2

#include<stdio.h>

void Merge(int a[],int l,int mid,int h)
{
	int i=l;//for array 1
	int j=mid+1;//for array 2
	int index=l;//for temporary array
	int k;//for final array
	int m[50];//temporary array
	
	while(i<=mid&&j<=h)
	{
		if(a[i]<a[j])//comparing the elements of array 1 and 2 and copying the smaller to m[]
		{
			m[index]=a[i];
			i++;
		}
		else
		{
			m[index]=a[j];
			j++;
		}
		index++;
	}
	
	if(i>mid)//done when array 1 transfer is over
	{
		while(j<=h)
		{
			m[index]=a[j];
			j++;
			index++;
		}
	}
	else//done when array 2 transfer is over
	{
		while(i<=mid)
		{
			m[index]=a[i];
			i++;
			index++;
		}
	}
	
	k=l;
	while(k<index)
	{
		a[k]=m[k];
		k++;
	}
}

void MergeSort(int a[],int l,int h)
{
	int mid;
	if(l<h)
	{
		mid=(l+h)/2;
		MergeSort(a,l,mid);
		MergeSort(a,mid+1,h);
		Merge(a,l,mid,h);
	}
}

void main()
{
	int i,n;
	int a[50];
	int l,h;
	
	printf("Merge Sort\n");
	
	printf("Enter the size of the array:");
	scanf("%d",&n);
	printf("Enter the array elements:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	printf("The original array:");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	printf("\n");
	
	l=0;
	h=n-1;
	
	MergeSort(a,l,h);
	
	printf("The sorted array:");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	printf("\n");
	
}