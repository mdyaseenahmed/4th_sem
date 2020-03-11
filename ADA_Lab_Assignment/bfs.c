/******************************************************************************************************* 
C Program To Print all the nodes reachable from a given starting node in a digraph using BFS method.
********************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int A[100][100],Q[100],visited[100];
int i,j,n;
int f=0,r=-1,start;
	
void BFS(int v)
{
	for(i=1;i<=n;i++)
	{
		if(A[v][i] && !visited[i])
		{
			Q[++r] = i;
		}
	}
	if(f<=r)
	{
		visited[Q[f]] = 1;
		BFS(f++);
	}
}

int main()
{
	printf("\nEnter The Number Of Vertices : ");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		Q[i] = 0;
		visited[i] = 0;
	}
	
	printf("\nEnter The Details of the Graph in Matrix Form : \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		scanf("%d",&A[i][j]); 
	}
	
	printf("\nEnter The Starting Vertex : ");
	scanf("%d",&start);
	
	BFS(start);
	
	printf("The Nodes Which Are Reachable Using BFS Traversal Include : \n");		
	for(i=1;i<=n;i++)
	{
		if(visited[i])
			printf("%d\t",i);
		else
		{
			printf("\nNot Reachable..!");
			break;
		}
			
	}
	printf("\n");
	return 0;
}
