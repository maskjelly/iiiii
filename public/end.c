#include <stdio.h>
#include <string.h>

void find(const char *text, const char *pattern) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    int found = 0;

    for (int i = 0; i <= textLen - patternLen; i++) {
        int j;
        for (j = 0; j < patternLen; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == patternLen) {
            printf("Pattern found at index %d\n", i + patternLen - 1);
            found = 1;
        }
    }
    if (!found) {
        printf("Not found\n");
    }
}

int main() {
    char text[100];
    char pattern[100];

    printf("Enter text: ");
    scanf("%s", text);  

    printf("Enter pattern: ");
    scanf("%s", pattern);  

    find(text, pattern);

    return 0;
}
