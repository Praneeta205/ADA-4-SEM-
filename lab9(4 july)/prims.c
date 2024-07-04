#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 9999

void prims(int n, int cost[MAX][MAX]) {
    int d[MAX], p[MAX], s[MAX];
    int source, min, sum = 0;
    int T[MAX][2], k = 0;


    min = INF;
    source = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cost[i][j] != 0 && cost[i][j] < min) {
                min = cost[i][j];
                source = i;
            }
        }
    }


    for (int i = 0; i < n; i++) {
        s[i] = 0;
        d[i] = cost[source][i];
        p[i] = source;
    }

    s[source] = 1;

    // Step 4: Find the Minimum Spanning Tree if it exists
    for (int i = 1; i < n; i++) {
        // Find u and d[u] such that d[u] is minimum and u ∉ s
        min = INF;
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (s[j] == 0 && d[j] < min) {
                min = d[j];
                u = j;
            }
        }


        T[k][0] = u;
        T[k][1] = p[u];
        k++;


        sum += cost[u][p[u]];

        s[u] = 1;


        for (int v = 0; v < n; v++) {
            if (s[v] == 0 && cost[u][v] < d[v]) {
                d[v] = cost[u][v];
                p[v] = u;
            }
        }
    }


    if (sum >= INF) {
        printf("Spanning tree does not exist\n");
    } else {
        printf("Spanning tree exists and MST is:\n");
        for (int i = 0; i < n - 1; i++) {
            printf("%d - %d\n", T[i][0], T[i][1]);
        }
        printf("The cost of the Minimum Spanning Tree is: %d\n", sum);
    }
}

int main() {
    int n;
    int cost[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use %d to represent infinity):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    prims(n, cost);

    return 0;
}

