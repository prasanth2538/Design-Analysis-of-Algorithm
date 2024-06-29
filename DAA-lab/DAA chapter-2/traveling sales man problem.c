#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <string.h>

typedef struct {
    double x, y;
} City;

double distance(City a, City b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void tsp(City* cities, int n, double* minDist, City* bestPath) {
    int* perm = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) perm[i] = i;
    
    do {
        double dist = 0.0;
        for (int i = 0; i < n - 1; i++) {
            dist += distance(cities[perm[i]], cities[perm[i + 1]]);
        }
        dist += distance(cities[perm[n - 1]], cities[perm[0]]);

        if (dist < *minDist) {
            *minDist = dist;
            for (int i = 0; i < n; i++) {
                bestPath[i] = cities[perm[i]];
            }
            bestPath[n] = cities[perm[0]];
        }
    } while (next_permutation(perm, n));

    free(perm);
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

void printPath(City* path, int n) {
    for (int i = 0; i <= n; i++) {
        printf("(%.1f, %.1f) ", path[i].x, path[i].y);
    }
    printf("\n");
}

int main() {
    City cities1[] = {{1, 2}, {4, 5}, {7, 1}, {3, 6}};
    int n1 = sizeof(cities1) / sizeof(cities1[0]);
    double minDist1 = DBL_MAX;
    City bestPath1[n1 + 1];
    tsp(cities1, n1, &minDist1, bestPath1);
    printf("Shortest Distance: %f\n", minDist1);
    printPath(bestPath1, n1);

    City cities2[] = {{2, 4}, {8, 1}, {1, 7}, {6, 3}, {5, 9}};
    int n2 = sizeof(cities2) / sizeof(cities2[0]);
    double minDist2 = DBL_MAX;
    City bestPath2[n2 + 1];
    tsp(cities2, n2, &minDist2, bestPath2);
    printf("Shortest Distance: %f\n", minDist2);
    printPath(bestPath2, n2);

    return 0;
}
