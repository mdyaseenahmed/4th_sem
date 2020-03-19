/***************************************************************************************************
    Sort a given set of N integer elements using Quick Sort technique and compute its time taken 
***************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int A[],int *a,int *b)
{
    int temp;
    temp = A[*a];
    A[*a] = A[*b];
    A[*b] = temp;
}

int Partition(int A[],int low,int high)
{
    int pivot;
    int i,j;
    pivot = A[low];
    i = low;
    j = high;
    while(i<=j)
    {
        while(A[i]<=pivot)
            i++;
        while(A[j]>pivot)    
            j--;
        if(i<j)    
            swap(A,&i,&j);
    }
    swap(A,&low,&j);
    return j;
}

void Quick_Sort(int A[],int low,int high)
{
    if(low < high)
    {
        int j = Partition(A,low,high);
        Quick_Sort(A,low,j-1);
        Quick_Sort(A,j+1,high);
    }
}

int main()
{
    int A[100000],n;
    int i,j;
    clock_t start,end;
    double time_required;
    printf("\nEnter The Size Of Array : ");
    scanf("%d",&n);
    printf("Enter %d Elements : \n",n);
    for(i=0;i<n;i++)
        A[i] = rand() % 10000+1;
        //scanf("%d",&A[i]);
    start = clock();
        Quick_Sort(A,0,n-1);
    end = clock();
    time_required = ((double)(end-start))/CLOCKS_PER_SEC;
    /*printf("\nSorted ELements Are : \n");
    for(i=0;i<n;i++)
        printf("\t%d",A[i]);*/
    printf("\nTime Required To Sort %d Elements is %f",n,time_required);
    return 0;
}

---------------------------
Output:
---------------------------

Enter The Size Of Array : 10                                                                                                    
Enter 10 Elements :                                                                                                             
                                                                                                                                
Sorted ELements Are :                                                                                                           
        493     887     1422    2778    5387    6650    6916    7794    8336   9384                                                                                                                             
Time Required To Sort 10 Elements is 0.000391 
