#include <stdio.h>

void dijkstra(int n, int v, int cost[10][10], int dist[10])
{
    int i, u, count, w, min;
    int flag[10] = {0};

    for (i = 1; i <= n; i++)
        dist[i] = cost[v][i];
    
    count = 2;
    while (count <= n)
    {
        // find the minimum distance vertex from the source
        min = 99;
        for (w = 1; w <= n; w++)
            if (dist[w] < min && !flag[w])
                min = dist[w], u = w;
        flag[u] = 1;
        count++;

        // relax the other vertices
        for (w = 1; w <= n; w++)
            if ((dist[u] + cost[u][w] < dist[w]) && !flag[w])
                dist[w] = dist[u] + cost[u][w];
    }
}

void main()
{
    int n, v, i, j, cost[10][10], dist[10];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost matrix: ");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter the source node: ");
    scanf("%d", &v);

    dijkstra(n, v, cost, dist);
    
    printf("Shortest path from %d to all other nodes are: \n", v);
    for (i = 1; i <= n; i++)
        if (i != v)
            printf("%d -> %d, cost = %d\n", v, i, dist[i]);
}