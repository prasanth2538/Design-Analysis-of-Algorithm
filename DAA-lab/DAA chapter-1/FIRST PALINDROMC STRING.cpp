#include <stdio.h>
#include <string.h>

int isPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

char *firstPalindrome(char **words, int wordsSize) {
    for (int i = 0; i < wordsSize; i++) {
        if (isPalindrome(words[i])) {
            return words[i];
        }
    }
    return "";
}

int main() {
    char *words[] = {"abc","car","ada","racecar","cool"};
    int wordsSize = sizeof(words) / sizeof(words[0]);
    
    char *result = firstPalindrome(words, wordsSize);
    
    printf("Output: %s\n", result);

    return 0;
}
