#include <stdio.h>

double champagneTower(int poured, int query_row, int query_glass) {
    double tower[101][101] = {{0}};
    tower[0][0] = poured;

    for (int i = 0; i <= query_row; i++) {
        for (int j = 0; j <= i; j++) {
            double flow = (tower[i][j] - 1.0) / 2.0;
            if (flow > 0) {
                tower[i + 1][j] += flow;
                tower[i + 1][j + 1] += flow;
            }
        }
    }

    return tower[query_row][query_glass] > 1.0 ? 1.0 : tower[query_row][query_glass];
}

int main() {
    int poured = 2;
    int query_row = 1;
    int query_glass = 1;

    double result = champagneTower(poured, query_row, query_glass);
    printf("Output: %.5f\n", result);

    return 0;
}
