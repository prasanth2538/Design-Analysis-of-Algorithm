#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    int hLen = strlen(haystack);
    int nLen = strlen(needle);

    if (nLen == 0) return 0;

    for (int i = 0; i <= hLen - nLen; i++) {
        if (strncmp(&haystack[i], needle, nLen) == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    printf("Output: %d\n", strStr("sadbutsad", "sad")); // Output: 0
    printf("Output: %d\n", strStr("leetcode", "leeto")); // Output: -1

    return 0;
}
