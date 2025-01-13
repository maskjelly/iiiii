#include <stdio.h>
#include <string.h>
void computeLPSArray(const char *pattern, int patternlen, int *lps)
{
    int length = 0;
    lps[0] = 0;  
    int i = 1;
    while (i < patternlen)
    {
        if (pattern[i] == pattern[length])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            if (length != 0)
            {
                length = lps[length - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void KMPsearch(const char *text, const char *pattern)
{
    int textlen = strlen(text);
    int patternlen = strlen(pattern);
    int lps[patternlen];
    computeLPSArray(pattern, patternlen, lps);
    int i = 0; 
    int j = 0; 
    while (i < textlen)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }
        if (j == patternlen)
        {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        }
        else if (i < textlen && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}
int main()
{
    char text[100];
    char pattern[100];
    printf("Enter text: ");
    scanf("%s", text);
    printf("Enter pattern: ");
    scanf("%s", pattern);
    KMPsearch(text, pattern);
    return 0;
}