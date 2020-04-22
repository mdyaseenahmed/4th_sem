#include <stdio.h> 
void findMin(int cost,int coins[10],int n) 
{ 
    int coinList[20] = { 0 }; 
    int i, k = 0; 
  
    for (i = n - 1; i >= 0; i--) { 
        while (cost >= coins[i]) { 
            cost -= coins[i]; 
            coinList[k++] = coins[i]; 
        } 
    } 
  
    for (i = 0; i < k; i++) { 
        printf("%d ", coinList[i]); 
    } 
    return; 
} 
  
int main(void) 
{ 
    int coins[10];
    int n ,amt,i; // input value 
    printf("Enter number of denominations\n");
    scanf("%d",&n);
    printf("enter the denominations available\n");
    for(i=0;i<n;i++)
    scanf("%d",&coins[i]);
    printf("Enter amount to be found for change\n");
    scanf("%d",&amt);
    printf("Following is minimal number of change for %d: ", amt); 
    findMin(amt,coins,n); 
    return 0; 
} 