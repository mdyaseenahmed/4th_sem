/*********************************************************************************************************************************************************
Given an integer N which is a multiple of 4, the task is to find an N x N grid for which the bitwise xor of every row and column is same.
*********************************************************************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>

void findgrid(int n)
{
    int A[n][n];
    int x = 0;
    int i,j,k,l;
    for(i=0;i<n/4;i++)
    {
        for(j=0;j<n/4;j++)
        {
            for(k=0;k<4;k++)
            {
                for(l=0;l<4;l++)
                {
                    A[i * 4 + k][j * 4 + l] = x; 
                    x++;
                }
            }
        }
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\t%d",A[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("\nEnter an Integer N which is a multiple of 4 : ");
    scanf("%d",&n);
    findgrid(n);
    return 0;
}

------------------------------
Output: (1)
----------------------------

Enter an Integer N which is a multiple of 4 : 4             

        0       1       2       3                                                                                               
        4       5       6       7                                                                                               
        8       9       10      11                                                                                              
        12      13      14      15 
        
        
------------------------------
Output: (2)
----------------------------

Enter an Integer N which is a multiple of 4 : 8      

        0       1       2       3       16      17      18      19                                                            
        4       5       6       7       20      21      22      23                                                            
        8       9       10      11      24      25      26      27                                                            
        12      13      14      15      28      29      30      31                                                            
        32      33      34      35      48      49      50      51                                                            
        36      37      38      39      52      53      54      55                                                            
        40      41      42      43      56      57      58      59                                                            
        44      45      46      47      60      61      62      63  
        
