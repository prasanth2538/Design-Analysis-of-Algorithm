#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y;
} Point;

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void closestPair(Point points[], int n) {
    double minDist = INFINITY;
    Point p1, p2;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dist = distance(points[i], points[j]);
            if (dist < minDist) {
                minDist = dist;
                p1 = points[i];
                p2 = points[j];
            }
        }
    }
    printf("Closest pair: (%.1f, %.1f) - (%.1f, %.1f)\n", p1.x, p1.y, p2.x, p2.y);
    printf("Minimum distance: %f\n", minDist);
}

int main() {
    Point points[] = {{1, 2}, {4, 5}, {7, 8}, {3, 1}};
    int n = sizeof(points) / sizeof(points[0]);
    closestPair(points, n);

    return 0;
}
