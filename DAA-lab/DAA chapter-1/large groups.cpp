#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** largeGroupPositions(char* s, int* returnSize, int** returnColumnSizes) {
    int n = strlen(s);
    int count = 1, start = 0;
    int** result = (int**)malloc(sizeof(int*));
    *returnColumnSizes = (int*)malloc(sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < n; i++) {
        if (i == n-1 || s[i] != s[i+1]) {
            if (count >= 3) {
                result = (int**)realloc(result, (*returnSize + 1) * sizeof(int*));
                (*returnColumnSizes) = (int*)realloc(*returnColumnSizes, (*returnSize + 1) * sizeof(int));

                result[*returnSize] = (int*)malloc(2 * sizeof(int));
                result[*returnSize][0] = start;
                result[*returnSize][1] = i;
                
                (*returnColumnSizes)[*returnSize] = 2;
                (*returnSize)++;
            }

            count = 1;
            start = i + 1;
        } else {
            count++;
        }
    }

    return result;
}

int main() {
    char s1[] = "abbxxxxzzy";
    char s2[] = "abc";
    int returnSize1, returnSize2;
    int* returnColumnSizes1;
    int* returnColumnSizes2;

    int** result1 = largeGroupPositions(s1, &returnSize1, &returnColumnSizes1);
    int** result2 = largeGroupPositions(s2, &returnSize2, &returnColumnSizes2);

    printf("Output 1: ");
    for (int i = 0; i < returnSize1; i++) {
        printf("[%d, %d] ", result1[i][0], result1[i][1]);
        free(result1[i]);
    }
    free(result1);
    free(returnColumnSizes1);
    printf("\n");

    printf("Output 2: ");
    for (int i = 0; i < returnSize2; i++) {
        printf("[%d, %d] ", result2[i][0], result2[i][1]);
        free(result2[i]);
    }
    free(result2);
    free(returnColumnSizes2);
    printf("\n");

    return 0;
}
