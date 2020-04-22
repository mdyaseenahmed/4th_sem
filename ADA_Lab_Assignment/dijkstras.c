
#include <stdio.h> 

int minDistance(int dist[], int sptSet[],int V) 
{ 
    int min = 999, min_index; 
  int v;
    for ( v = 0; v < V; v++) 
        if (sptSet[v] == 0 && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
int printSolution(int dist[],int V )
{ int i;
    printf("Vertex \t\t Distance from Source\n"); 
    for (i = 0; i < V; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 
void dijkstra(int graph[10][10], int src,int V) 
{ 
    int dist[V]; 
  int i,count,u,v;
    int sptSet[V];
    for ( i = 0; i < V; i++) 
        dist[i] = 999, sptSet[i] = 0; 
  
    dist[src] = 0; 
  
    for ( count = 0; count < V - 1; count++) { 
         
        u = minDistance(dist, sptSet,V); 
        sptSet[u] = 1; 
  
        for (v = 0; v < V; v++) 
  
            if (!sptSet[v] && graph[u][v] && dist[u] != 999 
                && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    } 
  
    printSolution(dist,V); 
} 
  
int main() 
{ 
    int i,j,V;
    /* Let us create the example graph discussed above */
    int graph[10][10]; 
    printf("Enter number of vertices\n");
    scanf("%d",&V);
    printf("Enter adjacency matrix\n");
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
    scanf("%d",&graph[i][j]);
    }
  
    dijkstra(graph, 0,V); 
  
    return 0; 
}