#include <stdio.h>

#define INF 9999
#define N 6

void dijkstra(int cost[N][N], int src) {
    int dist[N];
    int vis[N];
    int count, min_dist, u;

    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        vis[i] = 0;
    }

    dist[src] = 0;

    for (count = 0; count < N-1; count++) {
        min_dist = INF;
        for (int v = 0; v < N; v++) {
            if (!vis[v] && dist[v] <= min_dist) {
                min_dist = dist[v];
                u = v;
            }
        }

        vis[u] = 1;

        for (int v = 0; v < N; v++) {
            if (!vis[v] && cost[u][v] && dist[u] != INF && dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < N; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    int cost[N][N] = {
        {0, 15, 10, INF, 45, INF},
        {INF, 0, 15, INF, 20, INF},
        {20, INF, 0, 20, INF, INF},
        {INF, 10, INF, 0, 35, INF},
        {INF, INF, INF, 30, 0, INF},
        {INF, INF, INF, 4, INF, 0}
    };

    int src = 5;
    dijkstra(cost, src);

    return 0;
}
