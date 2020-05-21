/******************************************************************************************************
    C Program to sort a agiven set of N integers using QuickSort [Selecting Last Element as Pivot].
******************************************************************************************************/

#include<stdio.h>
#include<stdlib.h> 

void swap(int *a,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int A[],int low,int high)
{
    int pivot = A[high];  //Selects Last Element as PIVOT.
    int i = (low - 1);
    int j;
    
    for(j = low; j <= high-1; j++)
    {
        if(A[j] < pivot)
        {
            i++;
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[i + 1],&A[high]);
    return (i + 1);
}

void QuickSort(int A[],int low,int high)
{
    int mid;
    if(low < high)
    {
        mid = partition(A,low,high);
        
        QuickSort(A,low,mid-1);
        QuickSort(A,mid+1,high);
    }
}

void printArray(int A[],int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("\t%d",A[i]);
}

int main()
{
    int A[1000],i,n;
    
    printf("Enter The Size Of Array : ");
    scanf("%d",&n);
    
    printf("Enter %d Elements : \n",n);
    for(i = 0; i < n; i++)
        scanf("%d",&A[i]);
    
    QuickSort(A,0,n-1);
    printf("Sorted Array : ");
    printArray(A,n);
    return 0;
}

/**************************************
-------------------
Output:
-------------------
Enter The Size Of Array : 6
Enter 6 Elements : 
90
20
-60
30
45
54
Sorted Array : -60  20  30  45  54  90
****************************************/
