/*******************************************************************************************************************************************************************************************************
  Given k sorted lists of integers of size n each, find the smallest range that includes at least element from each of the k lists. If more than one smallest ranges are found, print any one of them.
*******************************************************************************************************************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define N 5

int ptr[999];

void findSmallestRange(int A[][N],int k,int n)
{
    int i, minval, maxval, minrange, minel, maxel, flag, minind;
    for (i = 0; i <= k; i++) 
        ptr[i] = 0;
    minrange = INT_MAX;
    while (1) { 
        minind = -1; 
        minval = INT_MAX; 
        maxval = INT_MIN; 
        flag = 0; 
  
        for (i = 0; i < k; i++) { 
            if (ptr[i] == n) { 
                flag = 1; 
                break; 
            } 
            if (ptr[i] < n && A[i][ptr[i]] < minval) { 
                minind = i; // update the index of the list 
                minval = A[i][ptr[i]]; 
            } 
            if (ptr[i] < n && A[i][ptr[i]] > maxval) { 
                maxval = A[i][ptr[i]]; 
            } 
        } 
  
        if (flag) 
            break; 
  
        ptr[minind]++; 
  
        if ((maxval - minval) < minrange) { 
            minel = minval; 
            maxel = maxval; 
            minrange = maxel - minel; 
        } 
    } 
  
    printf("The smallest range is [%d, %d]\n", minel, maxel); 
}

int main()
{
    int A[][N] = {
        { 4, 7, 9, 12, 15 }, 
        { 0, 8, 10, 14, 20 }, 
        { 6, 12, 16, 30, 50 }
    };
    int k = 3;
    findSmallestRange(A,k,N);
    return 0;
}

/*********************************************
-----------------------
Output:
-----------------------

The smallest range is [6, 8]
*********************************************/
