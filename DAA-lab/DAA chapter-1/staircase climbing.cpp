#include <stdio.h>

int climbStairs(int n) {
    if (n == 1) {
        return 1;
    }

    int first = 1;
    int second = 2;
    int result;

    for (int i = 3; i <= n; i++) {
        result = first + second;
        first = second;
        second = result;
    }

    return second;
}

int main() {
    int n1 = 4;
    int n2 = 3;

    printf("Output 1: %d\n", climbStairs(n1));
    printf("Output 2: %d\n", climbStairs(n2));

    return 0;
}
