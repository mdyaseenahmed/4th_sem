/******************************************************************************************************************************************************************************************************************
  Implement “Sum of Subsets” using Backtracking. “Sum of Subsets” problem: Find a subset of a given set  S = {s1,s2,……,sn} of n positive integers whose sum is equal to a given positive integer d.
  For example, if S = {1,2,5,6,8} and  d = 9 there are two solutions {1,2,6} and {1,8}. A suitable message is to be displayed if the given problem instance doesn’t have a solution. 
******************************************************************************************************************************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int x[1000],w[1000],d,count=0;

void subset(int cs,int k,int r)
{
    int i;
    x[k]=1;
    if(cs+w[k]==d)
    {
        printf("\nSubset %d\n",++count);
        for(i=0;i<=k;i++)
        if(x[i]==1)
        printf("%d\t",w[i]);
    }
    else if(cs+w[k]+w[k+1]<=d)
        subset(cs+w[k],k+1,r-w[k]);
    if(cs+r-w[k]>=d && cs+w[k]<=d)
    {
        x[k]=0;
        subset(cs,k+1,r-w[k]);
    }
}

int main()
{
    int i,n,sum=0;
    
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    printf("Enter the elements in ascending order:\n");
    for(i=0;i<n;i++)
        scanf("%d",&w[i]);
    printf("Enter the sum : ");
    scanf("%d",&d);
    for(i=0;i<n;i++)
        sum=sum+w[i];
    if(sum<d)
    {
        printf("No solution\n");
        exit(0);
    }
    subset(0,0,sum);
    if(count==0)
    {
        printf("No solution\n");
        exit(0);
    }
    return 0;
}

/*******************************
----------------
Output:
----------------
Enter the no. of elements: 5                                                                                                    
Enter the elements in ascending order:                                                                                          
1                                                                                                                               
2                                                                                                                               
5                                                                                                                               
6                                                                                                                               
8                                                                                                                               
Enter the sum : 9                                                                                                               
                                                                                                                                
Subset 1                                                                                                                        
1       2       6                                                                                                               
Subset 2                                                                                                                        
1       8
*******************************/
