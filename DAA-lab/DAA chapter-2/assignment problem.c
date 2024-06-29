#include <stdio.h>
#include <stdlib.h>

int total_cost(int* assignment, int n, int cost_matrix[n][n]) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += cost_matrix[i][assignment[i]];
    }
    return total;
}

void assignment_problem(int n, int cost_matrix[n][n]) {
    int* perm = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) perm[i] = i;

    int minCost = INT_MAX;
    int* bestAssignment = malloc(n * sizeof(int));

    do {
        int cost = total_cost(perm, n, cost_matrix);
        if (cost < minCost) {
            minCost = cost;
            for (int i = 0; i < n; i++) {
                bestAssignment[i] = perm[i];
            }
        }
    } while (next_permutation(perm, n));

    printf("Optimal Assignment: ");
    for (int i = 0; i < n; i++) {
        printf("(worker %d, task %d) ", i + 1, bestAssignment[i] + 1);
    }
    printf("\nTotal Cost: %d\n", minCost);

    free(perm);
    free(bestAssignment);
}

int next_permutation(int* array, int size) {
    int k = -1;
    for (int i = 0; i < size - 1; i++) {
        if (array[i] < array[i + 1]) k = i;
    }
    if (k == -1) return 0;

    int l = k + 1;
    for (int i = k + 1; i < size; i++) {
        if (array[k] < array[i]) l = i;
    }

    int temp = array[k];
    array[k] = array[l];
    array[l] = temp;

    for (int i = k + 1, j = size - 1; i < j; i++, j--) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    return 1;
}

int main() {
    int cost_matrix1[3][3] = {
        {3, 10, 7},
        {8, 5, 12},
        {4, 6, 9}
    };
    assignment_problem(3, cost_matrix1);

    int cost_matrix2[3][3] = {
        {15, 9, 4},
        {8, 7, 18},
        {6, 12, 11}
    };
    assignment_problem(3, cost_matrix2);

    return 0;
}
