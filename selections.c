//selection sorting

#include<stdio.h>

void main()
{
	int i,j,n,temp,pos;
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
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(a[pos]>a[j])
			pos=j;
		}
		if(pos!=i)
		{
			temp=a[i];
			a[i]=a[pos];
			a[pos]=temp;
		}
	}
	
	printf("Sorted array:");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	printf("\n");
}