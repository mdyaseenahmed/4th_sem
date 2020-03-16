/****************************************************************************************************
Sort a given set of N integer elements using Merge Sort technique and compute its time taken. 
Run the program for different values of N and record the time taken to sort.
****************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//C Function To Merge The Elements...  
void Merge(int A[],int l,int m,int h)
{
    int i,j,k;
    i = l;
    k = l;
    j = m+1;
    int temp[1000000];
    
    while(i<=m && j<=h)
    {
        if(A[i]<=A[j])
        {
            temp[k] = A[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = A[j];
            j++;
            k++;
        }
    }
    while(i<=m)
    {
        temp[k] = A[i];
        i++;
        k++;
    }
    while(j<=h)
    {
        temp[k] = A[j];
        j++;
        k++;
    }
        
    for(k=l;k<=h;k++)
    {
        A[k] = temp[k];
    }
}

//C Function To Display The Elements of An Array..
void Display(int A[],int n)
{
    int i;
    printf("Sorted Array : \n");
    for(i=0;i<n;i++)
    {
        printf("\t\n%d",A[i]);
    }
}

//C Function To Divide The Given Array...
void Merge_Sort(int A[],int l,int h)
{
    int m;
    if(l<h)
    {
        m = (l+h)/2;
        Merge_Sort(A,l,m);
        Merge_Sort(A,m+1,h);
        Merge(A,l,m,h);
    }
    
}

int main()
{
    int A[1000000];
    int i,n;
    clock_t start,end;
    //double time_required;
    printf("\nEnter The Size Of Array : ");
    scanf("%d",&n);
    printf("\nEnter %d Elements : \n",n);
    for(i=0;i<n;i++)
    {
        A[i] = rand() % 100000+1;
        //scanf("%d",&A[i]);
    }
    int l = 0;
    int h = n-1;
    start = clock();
    Merge_Sort(A,l,h);
    end = clock();
    //Display(A,n);
    double time_required = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nTime Required To Sort %d Elements is %f ",n,time_required);
    return 0;
}

/*
---------------------
Output:
---------------------
Enter The Size Of Array : 5                                                                                                     
                                                                                                                                
Enter 5 Elements :                                                                                                              
9                                                                                                                               
8                                                                                                                               
7                                                                                                                               
6                                                                                                                               
5                                                                                                                               
                                                                                                                                
Sorted Array :                                                                                                                                 
5                                                                                                                               
6                                                                                                                               
7                                                                                                                               
8                                                                                                                               
9                                                                                                                               
Time Required To Sort 5 Elements is 0.000017
*/
