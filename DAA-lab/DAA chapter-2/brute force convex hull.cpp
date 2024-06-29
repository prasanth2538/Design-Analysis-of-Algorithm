#include <stdio.h>
#include <stdbool.h>

typedef struct {
    double x, y;
} Point;

bool onLeft(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) > 0;
}

void convexHull(Point points[], int n) {
    Point hull[2 * n];
    int k = 0;

    // Sort points lexicographically (you can use qsort for efficiency)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (points[j].x < points[i].x || (points[j].x == points[i].x && points[j].y < points[i].y)) {
                Point temp = points[i];
                points[i] = points[j];
                points[j] = temp;
            }
        }
    }

    // Build lower hull
    for (int i = 0; i < n; i++) {
        while (k >= 2 && !onLeft(hull[k - 2], hull[k - 1], points[i])) k--;
        hull[k++] = points[i];
    }

    // Build upper hull
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && !onLeft(hull[k - 2], hull[k - 1], points[i])) k--;
        hull[k++] = points[i];
    }

    printf("Convex Hull:\n");
    for (int i = 0; i < k - 1; i++) {
        printf("(%.1f, %.1f) ", hull[i].x, hull[i].y);
    }
    printf("\n");
}

int main() {
    Point points[] = {{10, 0}, {11, 5}, {5, 3}, {9, 3.5}, {15, 3}, {12.5, 7}, {6, 6.5}, {7.5, 4.5}};
    int n = sizeof(points) / sizeof(points[0]);
    convexHull(points, n);

    return 0;
}
