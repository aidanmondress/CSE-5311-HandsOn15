#include <stdio.h>
#include <stdlib.h>

#define INF 1000000

struct edge
{
  int u;
  int v;
  int w;
};

struct graph
{
  int v;
  int e;
  struct edge *edge;
};

void printAns(int arr[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void bellmanford(struct graph *g, int src)
{
  int i;
  int j;
  int u;
  int v;
  int w;
  
  int vTotal = g->v;
  int eTotal = g->e;
  
  int dis[vTotal];
  int arr[vTotal];

  for (i = 0; i < vTotal; i++)
  {
    dis[i] = INF;
    arr[i] = 0;
  }

  dis[src] = 0;

  for(i = 1; i <= vTotal - 1; i++)
  {
    for(j = 0; j < eTotal; j++)
    {
      u = g->edge[j].u;
      v = g->edge[j].v;
      w = g->edge[j].w;
      if(dis[u] != INF && dis[v] > dis[u] + w)
      {
        dis[v] = dis[u] + w;
        arr[v] = u;
      }
    }
  }

  for(i = 0; i < eTotal; i++)
  {
    u = g->edge[i].u;
    v = g->edge[i].v;
    w = g->edge[i].w;
    if(dis[v] > dis[u] + w && dis[u] != INF)
    {
      printf("Negative weight cycle found\n");
      return;
    }
  }

  printf("Final Distance Array: ");
  printAns(dis, vTotal);
  printf("Predecessor array: ");
  printAns(arr, vTotal);
}

int main(void)
{
  return 0;
}
