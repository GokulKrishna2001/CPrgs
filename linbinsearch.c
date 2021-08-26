//to do linear and binary search in an array

#include<stdio.h>

int n[50];
int num;
int s;
int f=0;

void Sort()
{
	int i,j;
	int m;
	for(i=0;i<num-1;i++)
	{
		for(j=0;j<num-1-i;j++)
		{
			if(n[j]>n[j+1])
			{
				m=n[j];
				n[j]=n[j+1];
				n[j+1]=m;
			}
		}
	}
	printf("The sorted array is:");
	for(i=0;i<num;i++)
		printf("%d\t",n[i]);
	printf("\n\n");
}

void LinearSearch()
{
	int i,a;
	for(i=0;i<num;i++)
	{
		if(n[i]==s)
		{
			printf("From Linear Search method, %d was found out in position %d.\n\n",s,i+1);
			a=1;
			break;
		}
	}
	if(a!=1)
		printf("The element %d is not present\n\n",s);
}

void BinarySearch()
{
	int i;
	int first=0;
	int last=num-1;
	int mid=(first+last)/2;
	while(first<=last)
	{
		if(n[mid]<s)
			first=mid+1;
		else if(n[mid]==s)
		{
			printf("From Binary Search method, %d was found out in position %d.\n\n",s,mid+1);
			break;
		}
		
		else
			last=mid-1;
		mid=(first+last)/2;
		
	}
	if(first>last)
		printf("The element %d is not present\n\n",s);
}

void main()
{
	int i,c,ch;
	printf("Enter the array size\n");
	scanf("%d",&num);
	printf("Enter the array elements\n");
	for(i=0;i<num;i++)
		scanf("%d",&n[i]);
	printf("Enter the number to be searched\n");
	scanf("%d",&s);
	printf("Enter your choice:\n");
	printf("1.Linear Search\t 2.Binary Search\t 3.Exit\n");
	scanf("%d",&c);
	while(c>=1&&c<=2)
	{
		switch(c)
		{
			case 1:
		    {
				LinearSearch();
				break;
		    }
		    case 2:
		    {
				if(f==0)
				{
					Sort();
					f++;
				}
				BinarySearch();
				break;
		    }
		}
		printf("Press 1 to search again, else, press 0 to exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter the element\n");
			scanf("%d",&s);
			printf("1.Linear Search\t 2.Binary search\n");
			scanf("%d",&c);
		}
		else
			c=3;
	}
	
	printf("Thank You\n");
}