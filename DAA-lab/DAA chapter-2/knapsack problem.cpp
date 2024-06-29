#include <stdio.h>

int total_value(int* items, int n, int* values) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (items[i] == 1) {
            total += values[i];
        }
    }
    return total;
}

int is_feasible(int* items, int n, int* weights, int capacity) {
    int totalWeight = 0;
    for (int i = 0; i < n; i++) {
        if (items[i] == 1) {
            totalWeight += weights[i];
        }    }
    return totalWeight <= capacity;
}
void knapsack(int* weights, int* values, int n, int capacity) {
    int bestValue = 0;
    int bestItems[n];
    int items[n];
   for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            items[j] = (i & (1 << j)) ? 1 : 0;
        }
        if (is_feasible(items, n, weights, capacity)) {
            int value = total_value(items, n, values);
            if (value > bestValue) {
                bestValue = value;
                for (int j = 0; j < n; j++) {
                    bestItems[j] = items[j];
                }
            }
        }
    }
    printf("Optimal Selection: ");
    for (int i = 0; i < n; i++) {
        if (bestItems[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\nTotal Value: %d\n", bestValue);
}
int main() {
    int weights1[] = {2, 3, 1};
    int values1[] = {4, 5, 3};
    knapsack(weights1, values1, 3, 4); // Output: Optimal Selection: 0 2, Total Value: 7

    int weights2[] = {1, 2, 3, 4}; 
    int values2[] = {2, 4, 6, 3};
    knapsack(weights2, values2, 4, 6); // Output: Optimal Selection: 0 1 2, Total Value: 10

    return 0;
}
