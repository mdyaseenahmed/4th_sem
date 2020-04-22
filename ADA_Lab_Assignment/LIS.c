#include<stdio.h>
int max_element(int lis[],int n)
{
    int max,i;
    max=lis[0];
    for(i=1;i<n;i++)
    {
        if(lis[i]>max)
        max=lis[i];
    }
    return max;
}
int lis( int arr[], int n )  
{  
    int lis[n]; 
   int i,j;
    lis[0] = 1;    
  
    for ( i = 1; i < n; i++ )  
    { 
        lis[i] = 1; 
        for ( j = 0; j < i; j++ )   
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)  
                lis[i] = lis[j] + 1;  
    } 
  
    return max_element(lis, n); 
}  

int main()  
{  
    int arr[10],n,i;  
    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("Enter elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printf("Length of lis is %d\n", lis( arr, n ) );  
    return 0;  
}
