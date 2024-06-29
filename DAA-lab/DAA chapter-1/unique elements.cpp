#include <stdio.h>
#include <stdlib.h>

int isUnique(int num, int *uniqueList, int uniqueSize) {
    for (int i = 0; i < uniqueSize; i++) {
        if (num == uniqueList[i]) {
            return 0;
        }
    }
    return 1; 
}

int* findUniqueElements(int *nums, int numsSize, int *uniqueSize) {
    int *uniqueList = (int *)malloc(numsSize * sizeof(int));
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (isUnique(nums[i], uniqueList, count)) {
            uniqueList[count] = nums[i];
            count++;
        }
    }

    *uniqueSize = count;
    return uniqueList;
}

int main() {
    int test1[] = {3, 7, 3, 5, 2, 5, 9, 2};
    int size1 = sizeof(test1) / sizeof(test1[0]);

    int test2[] = {-1, 2, -1, 3, 2, -2};
    int size2 = sizeof(test2) / sizeof(test2[0]);

    int test3[] = {1000000, 999999, 1000000};
    int size3 = sizeof(test3) / sizeof(test3[0]);

    int uniqueSize1, uniqueSize2, uniqueSize3;
    int *uniqueList1 = findUniqueElements(test1, size1, &uniqueSize1);
    int *uniqueList2 = findUniqueElements(test2, size2, &uniqueSize2);
    int *uniqueList3 = findUniqueElements(test3, size3, &uniqueSize3);

    printf("Unique Elements for Test Case 1:");
    for (int i = 0; i < uniqueSize1; i++) {
        printf(" %d", uniqueList1[i]);
    }
    printf("\n");

    printf("Unique Elements for Test Case 2:");
    for (int i = 0; i < uniqueSize2; i++) {
        printf(" %d", uniqueList2[i]);
    }
    printf("\n");

    printf("Unique Elements for Test Case 3:");
    for (int i = 0; i < uniqueSize3; i++) {
        printf(" %d", uniqueList3[i]);
    }
    printf("\n");

    free(uniqueList1);
    free(uniqueList2);
    free(uniqueList3);

    return 0;
}
