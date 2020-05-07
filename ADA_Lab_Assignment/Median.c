/******************************************************************************************************************************************************************************************************************
  There are 2 sorted arrays A and B of size n each. Write an algorithm to find the median of the array obtained after merging the above 2 arrays(i.e. array of length 2n). The complexity should be O(log(n)).
******************************************************************************************************************************************************************************************************************/

#include<stdio.h>
#include<conio.h>

int getMedian(int A[],int B[],int n)
{
	int r1 = -1;
	int r2 = -1;
	int i = 0;
	int j = 0;
	int k;
	
	for(k = 0;k<=n;k++)
	{
		if(i == n)
		{
			r1 = r2;
			r2 = B[0];
			break;
		}
		else if(j == n)
		{
			r1 = r2;
			r2 = A[0];
			break;
		}
		if(A[i] < B[j])
		{
			r1 = r2;
			r2 = A[i];
			i++;
		}
		else
		{
			r1 = r2;
			r2 = B[j];
			j++;
		}
	}
	return (r1+r2)/2;
}

int main()
{
	int A[10000],B[10000];
	int n1,n2;
	int i;
	printf("Enter the Size Of Array 1 : ");
	scanf("%d",&n1);
	printf("Enter %d Elements : \n",n1);
	for(i = 0;i<n1;i++)
		scanf("%d",&A[i]);
	printf("Enter the Size Of Array 2 : ");
	scanf("%d",&n2);
	printf("Enter %d Elements : \n",n2);
	for(i = 0;i<n2;i++)
		scanf("%d",&B[i]);
	if(n1 == n2)	
		printf("\nThe Median is : %d",getMedian(A,B,n1));
	else
		printf("Enter The Same Size For Both the Arrays oe Else it wont works.");	
	return 0;		
}

/***********************
-----------------
Output:
-----------------
Enter the Size Of Array 1 : 5                                                                                                   
Enter 5 Elements :                                                                                                              
1                                                                                                                               
12                                                                                                                              
15                                                                                                                              
26                                                                                                                              
38                                                                                                                              
Enter the Size Of Array 2 : 5                                                                                                   
Enter 5 Elements :                                                                                                              
2                                                                                                                               
13                                                                                                                              
17                                                                                                                              
30                                                                                                                              
45                                                                                                                              
                                                                                                                                
The Median is : 16
***********************/
