#include <bits/stdc++.h>
using namespace std;

void Example(char *s)
{
    // Some c functions that work with char*
    printf("Upper: %s \n", strupr(s));
    printf("Lower: %s \n", strlwr(s));
    printf("Love ~ Love, %d \n", strcmp("Love", "Love"));
    printf("Love ~ Lova, %d \n", strcmp("Love", "Lova"));
    printf("Love ~ Lovz, %d \n", strcmp("Love", "Lovz"));
    printf("Love ~ love, %d \n", stricmp("Love", "love"));
}

void CopyString(char *s)
{
    char s2[100];
    char *s3;
    strcpy(s2, s);
    printf("%s \n", s2);
    strncpy(s2 + 2, "12345", 4);
    printf("%s \n", s2);
    s3 = strdup(s + 5);
    printf("%s \n", s3);
    free(s3);
}

void SeparateString(char *s)
{
    char *p = strtok(s, " ");
    while (p != NULL)
    {
        printf("%s \n", p);
        p = strtok(NULL, " ");
    }
}

void SearchSubstring(char *s)
{
    char *p;
    p = strchr(s, 's');
    printf("%s \n");
    p = strstr(s, "so");
    printf("%s \n");
}

void InsertString(char *s, char *sub)
{
    int n = strlen(sub);
    memmove(s + n, s, strlen(s));
    strncpy(s, sub, n);
    printf("%s \n", s);
}

void DeleteString(char *s, int n)
{
    memmove(s, s + n, strlen(s + n) + 1);
}

int main()
{
    char *s = strdup("Wes're so f");
    char *i = strdup("Rip ");
    InsertString(s, i);
}
