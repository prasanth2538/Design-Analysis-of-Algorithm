#include <stdio.h>

int findPeakElement(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    int nums1[] = {1, 2, 3, 1};
    printf("Output: %d\n", findPeakElement(nums1, 4)); // Output: 2

    int nums2[] = {1, 2, 1, 3, 5, 6, 4};
    printf("Output: %d\n", findPeakElement(nums2, 7)); // Output: 5

    return 0;
}
