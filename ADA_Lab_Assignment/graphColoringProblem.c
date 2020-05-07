/***********************************************************************************************************************************************************************************************************************************************************************************************************
  Write a program for the following: Given an undirected graph and a number m, determine if the graph can be colored with at most m colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices.
***********************************************************************************************************************************************************************************************************************************************************************************************************/

#include<stdio.h> 
#include<stdbool.h> 
#define V 4 

void printSolution(int color[]) 
{ 
    printf("Solution Exists:\nFollowing are the assigned colors: \n"); 
    for (int i = 0; i < V; i++) 
        printf(" %d ", color[i]); 
    printf("\n"); 
} 

bool isSafe (int v, bool graph[V][V], int color[], int c) 
{ 
    for (int i = 0; i < V; i++) 
        if (graph[v][i] && c == color[i]) 
            return false; 
    return true; 
} 

bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) 
{ 
    if (v == V) 
        return true; 
    for (int c = 1; c <= m; c++) 
    { 
        if (isSafe(v, graph, color, c)) 
        { 
            color[v] = c; 
            if (graphColoringUtil (graph, m, color, v+1) == true) 
                return true; 
            color[v] = 0; 
        } 
    }
    return false; 
} 

bool graphColoring(bool graph[V][V], int m) 
{ 
    int color[V]; 
    for (int i = 0; i < V; i++) 
        color[i] = 0; 
    if (graphColoringUtil(graph, m, color, 0) == false) 
    { 
        printf("Solution does not exist"); 
        return false; 
    } 
    printSolution(color); 
    return true; 
} 
  
int main() 
{ 
    int i,j,m;
    bool graph[V][V];
    printf("Enter Graph Details in the form of Adjacency Matrix : \n");
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
            scanf("%d",&graph[i][j]);
    printf("Enter number of colors\n");
    scanf("%d",&m);
    graphColoring (graph, m); 
    return 0; 
} 

/******************************************
-----------------------
Output:
-----------------------
Enter Graph Details in the form of Adjacency Matrix :                                                                         
0       1       1       1                                                                                                     
1       0       1       0                                                                                                     
1       1       0       1                                                                                                     
1       0       1       0                                                                                                     
Enter number of colors                                                                                                        
3                                                                                                                             
Solution Exists:                                                                                                              
 Following are the assigned colors                                                                                            
 1  2  3  2
******************************************/
