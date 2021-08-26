//insertion sorting

#include<stdio.h>

void main()
{
	int i,j,n,pos;
	int a[50];
	printf("Enter the array size:");
	scanf("%d",&n);
	printf("Enter the array elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	printf("Original array:");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	printf("\n");
	
	for(i=1;i<n;i++)
	{
		pos=a[i];
		j=i-1;
		while(j>=0&&a[j]>pos)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=pos;
	}
	
	printf("Sorted array:");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	printf("\n");
}