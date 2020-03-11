/*C Program To Check whether a given graph is connected or not using DFS method.*/

#include<stdio.h>
#include<stdlib.h>
int A[100][100];
int reach[100],n;
int i,j;

void dfs(int v)
{
	reach[v] = 1;
	for(i=1;i<=n;i++)
		if(A[v][i] && !reach[i])
		{
			printf("\n%d -> %d",v,i);
			dfs(i);
		}
}

int main()
{
	int count = 0;
	int v;
	printf("\nEnter The Number Of Vertices : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		reach[i] = 0;
		for(j=1;j<=n;j++)
		{
			A[i][j] = 0;
		}
	}
	
	printf("\nEnter The Adacency Matrix Of The Graph : \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	
	printf("\nEnter The Starting Vertex : ");
	scanf("%d",&v);
	dfs(1);
	printf("\n");	
	for(i=1;i<=n;i++)
	{
		if(reach[i])
			count++;
	}
	if(count == n)
	{
		printf("\nGraph is Connected..!\n");
	}
	else
	{
		printf("\nGraph is Not Connected..!\n");
	}
	return 0;
}
