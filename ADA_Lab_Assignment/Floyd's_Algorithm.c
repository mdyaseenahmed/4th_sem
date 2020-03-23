/*
    C Program To Implement All Pair Shortest paths problem Using Floyd’s Algorithm.
*/

#include<stdio.h>
#include<stdlib.h>
#define V1 4
#define INF 9999

void Floyd_algo(int G[][V1])
{
    int dist[V1][V1];
    int i,j,k;
    
    for(i=0;i<V1;i++)
        for(j=0;j<V1;j++)
            dist[i][j] = G[i][j];
    
    for(k=0;k<V1;k++)        
    {
        for(i=0;i<V1;i++)
        {
            for(j=0;j<V1;j++)
            {
                if(dist[i][k]+dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k]+dist[k][j];
            }
        }
    }
    printf("\nFollowing Matrix Shows the Shortest Distances Between Every Pair of Vertices : \n");
    for(i=0;i<V1;i++)
    {
        for(j=0;j<V1;j++)
        {
            if(dist[i][j] == INF)
                printf("%7s","INF");
            else
                printf("%7d",dist[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int G1[V1][V1] = {
                      { 0 , 5 ,INF, 10},
                      {INF, 0 , 3 ,INF},
                      {INF,INF, 0 , 1 },
                      {INF,INF,INF, 0 }
                    };
    int G2[V1][V1] = {
                        { 0 ,INF, 3 ,INF},
                        { 2 , 0 ,INF,INF},
                        {INF, 7 , 0 , 1 },
                        { 6 ,INF,INF, 0 }
                    };
    Floyd_algo(G1);
    printf("\n\n");
    Floyd_algo(G2);
    return 0;
}                

---------------------
Output:
--------------------
Following Matrix Shows the Shortest Distances Between Every Pair of Vertices :                                                  
      0      5      8      9                                                                                                    
    INF      0      3      4                                                                                                    
    INF    INF      0      1                                                                                                    
    INF    INF    INF      0                                                                                                    
                                                                                                                                
                                                                                                                                
                                                                                                                                
Following Matrix Shows the Shortest Distances Between Every Pair of Vertices :                                                  
      0     10      3      4                                                                                                    
      2      0      5      6                                                                                                    
      7      7      0      1                                                                                                    
      6     16      9      0 
      
