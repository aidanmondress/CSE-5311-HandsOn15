#include <stdio.h>

#define INF 1000000
#define N 4

void printAns(int dis[][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(dis[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dis[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int dis[][N])
{
    int i;
    int j;
    int k;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            for(k = 0; k < N; k++)
            {
                if(dis[j][i] + dist[i][k] < dist[j][k])
                  dis[j][k] = dis[j][i] + dist[i][k];
            }
        }
    }
    printAns(dis);
}

int main()
{
    int nodes[N][N] = {{0, 3, 8, INF, -4},
                      {INF, 0, INF, 1, 7},
                      {INF, 4, 0, INF, INF},
                      {2, INF, -5, 0, INF}
                      {INF, INF, INF, 6, 0}};
    floydWarshall(nodes);
    return 0;
}
