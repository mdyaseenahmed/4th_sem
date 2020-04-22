#include <stdio.h> 
  
int findPartiion (int arr[], int n) 
{ 
    int sum = 0; 
    int i, j; 
    
    for (i = 0; i < n; i++) 
      sum += arr[i]; 
 
    if (sum%2 != 0)   
       return 0; 
    int part[sum/2+1][n+1]; 
      
    for (i = 0; i <= n; i++) 
      part[0][i] = 1; 
        
    for (i = 1; i <= sum/2; i++) 
      part[i][0] = 0;      
     for (i = 1; i <= sum/2; i++)   
     { 
       for (j = 1; j <= n; j++)   
       { 
         part[i][j] = part[i][j-1]; 
         if (i >= arr[j-1]) 
           part[i][j] = part[i][j] || part[i - arr[j-1]][j-1]; 
       }         
     }       
     return part[sum/2][n]; 
}      
  

int main() 
{ 
  int arr[10],n,i; 
  printf("Enter size of array\n");
  scanf("%d",&n);
  printf("Enter array elements\n");
  for(i=0;i<n;i++)
  scanf("%d",&arr[i]);
  if (findPartiion(arr, n) == 1) 
     printf("Can be divided into two subsets of equal sum"); 
  else
     printf("Can not be divided into two subsets of equal sum"); 
  getchar(); 
  return 0; 
} 