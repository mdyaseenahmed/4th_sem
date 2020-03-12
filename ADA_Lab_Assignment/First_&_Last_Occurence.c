/**********************************************************************************************
Given a sorted array with repeating integers. You need to find the first occurrence , 
last occurrence and count of a given key in the array. USE ONLY BINARY SEARCH. Your 
algorithm should run in LogN time.If element is not present print -1 -1 0.
**********************************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int first(int A[], int low, int high, int x, int n) 
{ 
    if(high >= low) 
    { 
	    int mid = (low + high)/2; 
	    if(( mid == 0 || x > A[mid-1]) && A[mid] == x) 
	    {
	        printf("\nFirst Occurence : %d",mid);
	        return mid; 
	    }
	    else if(x > A[mid]) 
	    return first(A, (mid + 1), high, x, n); 
	    else    
	    return first(A, low, (mid -1), x, n); 
    } 
    return -1; 
} 

int last(int A[], int low, int high, int x, int n) 
{ 
    if (high >= low) 
    { 
    	int mid = (low + high)/2; 
    	if( ( mid == n-1 || x < A[mid+1]) && A[mid] == x ) 
    	{
	        printf("\nLast Occurence : %d",mid);
	        return mid; 
	    }
	    else if(x < A[mid]) 
    	return last(A, low, (mid -1), x, n); 
	    else
    	return last(A, (mid + 1), high, x, n);	 
    } 
    return -1; 
} 


int count(int A[], int n, int x) 
{ 
    int i;
    int j; 

    i = first(A, 0, n-1, x, n); 

    if(i == -1) 
	    return i; 
	
    j = last(A, i, n-1, x, n);	 
return j-i+1; 
} 

int main()
{
    int A[100000],n;
    int i,k;
    printf("\nEnter The Size Of The Array : ");
    scanf("%d",&n);
    printf("\nEnter %d Elements in Ascending Order : \n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("\nEnter The Key To Be Searched : ");
    scanf("%d",&k);
    int c = count(A,n,k);
    if(c != -1)
    {
        printf("\nThe Element %d Occurs %d Times...!",k,c);
    }
    else
    {
        printf("\n%d",c);
    }
    return 0;
}
