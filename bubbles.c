//bubble sorting in c

#include<stdio.h>

void main()
{
	int i,j,n,temp;
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
	
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
		if(a[j]>a[j+1])
		{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
		}
	}
	
	printf("Sorted array:");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	printf("\n");
}
	