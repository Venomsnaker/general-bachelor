#include <bits/stdc++.h>
using namespace std;

void Example(char *s) {
    // Some c functions that work with char*
    printf("Upper: %s \n", strupr(s));
    printf("Lower: %s \n", strlwr(s));
    printf("Love ~ Love, %d \n", strcmp("Love", "Love"));
    printf("Love ~ Lova, %d \n", strcmp("Love", "Lova"));
    printf("Love ~ Lovz, %d \n", strcmp("Love", "Lovz"));
    printf("Love ~ love, %d \n", stricmp("Love", "love"));
}

void CopyStringN() {
    char s[] = "Tony Blurt";
    char s2[100], *s3;
    strcpy(s2, s);
    printf("%s\n", s2);
    strncpy(s2 + 2, "12345", 3);
    printf("%s\n", s2);
    s3 = strdup(s + 5);
    printf("%s\n", s3);
    free(s3);
}

int main() {
    char *s = strdup("We're so f");
}
