#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the Knapsack problem using dynamic programming
void knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            } else {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    // Display the table
    printf("DP Table:\n");
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            printf("%4d", K[i][w]);
        }
        printf("\n");
    }

    // Find the items included in the knapsack
    int res = K[n][W];
    printf("\nMaximum value in Knapsack = %d\n", res);
    printf("Items included in the knapsack:\n");

    w = W;
    for (i = n; i > 0 && res > 0; i--) {
        if (res == K[i - 1][w])
            continue;
        else {
            printf("Item %d (Value: %d, Weight: %d)\n", i, val[i - 1], wt[i - 1]);
            res -= val[i - 1];
            w -= wt[i - 1];
        }
    }
}

int main() {
    int n = 4;
    int val[] = {12, 10, 20, 15};
    int wt[] = {2, 1, 3, 2};
    int W = 5;

    knapsack(W, wt, val, n);

    return 0;
}

