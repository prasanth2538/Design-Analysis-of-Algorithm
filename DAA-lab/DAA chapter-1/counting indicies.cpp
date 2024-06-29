#include <stdio.h>

int countMatchingIndices(int *nums1, int n, int *nums2, int m) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (nums1[i] == nums2[j]) {
                answer++;
                break;
            }
        }
    }
    return answer;
}

int* calculateAnswers(int *nums1, int n, int *nums2, int m) {
    static int result[2];
    result[0] = countMatchingIndices(nums1, n, nums2, m);
    result[1] = countMatchingIndices(nums2, m, nums1, n);
    return result;
}

int main() {
    int nums1[] = {2, 3, 2};
    int nums2[] = {1, 2};
    int n = sizeof(nums1) / sizeof(nums1[0]);
    int m = sizeof(nums2) / sizeof(nums2[0]);

    int *result = calculateAnswers(nums1, n, nums2, m);

    printf("Output: [%d, %d]\n", result[0], result[1]);

    return 0;
}
