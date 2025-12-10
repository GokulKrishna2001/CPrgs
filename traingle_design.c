/* to print in
									1	
								2	1	2	
							3	2	1	2	3	
						4	3	2	1	2	3	4	
					5	4	3	2	1	2	3	4	5	
*/
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of lines:");
    scanf("%d", &n);
    int i, j, k, m;
    //to print each lines, starting with spaces
    for(i=1;i<=n;i++)
    {
        //printing the blank spaces
        for(j=0;j<n-i;j++)
            printf("\t");
        //printing the spaces in the left
        for(k=n-j;k>0;k--)
            printf("%d\t",k);
        //to print the right side
        if(i!=1)
        {
            m=2;
            while(m<=i)
            {
                printf("%d\t",m);
                m++;
            }
        }
        //giving space for the next line
        printf("\n");
    }
}
