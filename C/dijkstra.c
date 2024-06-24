#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *parent, *keys;

int minIndex(int *keys, int *visited, int n)
{
    int min = INT_MAX, ind = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && keys[i] < min)
        {
            min = keys[i];
            ind = i;
        }
    }
    return ind;
}

void dijkstra(int adjmat[9][9], int n, int s)
{
    parent = (int *)malloc(n * sizeof(int));
    int *visited = (int *)calloc(n, sizeof(int));
    keys = (int *)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
        keys[i] = INT_MAX;
    parent[s] = -1;
    keys[s] = 0;
    for (int i = 0; i < n ; i++)
    {
        int u = minIndex(keys, visited, n);
        visited[u] = 1;
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && adjmat[u][v] && keys[u] + adjmat[u][v] < keys[v])
            {
                parent[v] = u;
                keys[v] = keys[u] + adjmat[u][v];
            }
        }
    }
}

void path(int s, int d)
{
    if (d == s)
        printf("%d ", d);
    else
    {
        path(s, parent[d]);
        printf("%d ", d);
    }
}

int main()
{
    int mat[9][9] = {{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }};
    dijkstra(mat, 9, 7);
    path(7, 4);
    printf("\nTotal Cost for the path is %d", keys[4]);
    // for(int i = 0 ; i < 5 ; i++)
    //     printf("%d ", keys[i]);
    return 0;
}