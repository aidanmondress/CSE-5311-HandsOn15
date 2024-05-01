#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define N 5
 
int minDistance(int dis[], bool set[])
{
    int i;
    int min = INT_MAX;
    for(int v = 0; v < N; v++)
      {
        if (set[v] == false && dis[v] <= min)
            min = dis[v], i = v;
      }
    return i;
}

void printSolution(int dis[])
{
    printf("Vertex:\t");
    for(int i = 0; i < N; i++)
      {
        printf("%d\t", i);
      }
    printf("\nTotal Cost: ");
    for(int i = 0; i < N; i++)
      {
        printf("%d\t", dis[i]);
      }
  
}
 
void dijkstra(int set[N][N], int src)
{
    int dis[N];
    bool solSet[N];
 
    for (int i = 0; i < N; i++)
      {
        dist[i] = INT_MAX;
        solSet[i] = false;
      }
    dis[src] = 0;
 
    for (int i = 0; i < N - 1; i++)
    {
        int u = minDistance(dis, solSet);
        solSet[u] = true;
 
        for (int v = 0; v < N; v++)
          {
            if (dis[u] != INT_MAX && dis[u] + set[u][v] < dis[v] && !solSet[v] && set[u][v])
                dis[v] = dis[u] + set[u][v];
          }
    }
    printSolution(dis);
}
 
int main()
{
    int nodes[V][V] = {{0, 10, 0, 5, 0},
                      {0, 0, 1, 2, 0},
                      {0, 0, 0, 0, 4},
                      {0, 3, 9, 0, 2},
                      {7, 0, 6, 0, 0}};
 
    dijkstra(nodes, 0);
    return 0;
}
