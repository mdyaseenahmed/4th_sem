/*********************************************************************************************************************************************************************************************************************
There are a total of n tasks you have to pick, labelled from 0 to n-1. Some tasks may have prerequisites tasks, for example to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1]
Given the total number of tasks and a list of prerequisite pairs, return the ordering of tasks you should pick to finish all tasks.
There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all tasks, return an empty array
*********************************************************************************************************************************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int temp[10],k=0;
  
void topo(int n,int indegree[10],int a[10][10])
{
   int i,j;
  
   for(i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            indegree[i]=1;
            temp[++k]=i;
            for(j=1;j<=n;j++)
            {
                if(a[i][j]==1&&indegree[j]!=-1)
                indegree[j]--;
            }
            i=0;
       }
    }
}

void main()
{
   int i,j,n,p,x,y,indegree[10],a[10][10];
   int pre[10][10];
   printf("enter the number of vertices:");
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   indegree[i]=0;
   printf("enter number of prerequistes\n");
   scanf("%d",&p);
   printf("enter the prerequites\n");
   for(i=1;i<=p;i++)
   {
        for(j=1;j<=2;j++)
        scanf("%d",&pre[i][j]);
   }
   for(i=1;i<=n;i++)
   {
        for(j=1;j<=n;j++)
        a[i][j]=0;
   }
   for(i=1;i<=p;i++)
   {
        x=pre[i][1];
        y=pre[i][2];
        a[x+1][y+1]=1;
   }
   for(i=1;i<=n;i++)
   {
        for(j=1;j<=n;j++)
        {
          if(a[i][j]==1)
          indegree[j]++;
       }
   }
   topo(n,indegree,a);

   if(k!=n)
   printf("All tasks are not possible\n");
 
    else
    {
      printf("\n All tasks are possible\n");
      
    }
 }
