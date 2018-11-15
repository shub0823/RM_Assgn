#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void search(char *text, char *pattern)
{
    int t;
    int p;
    int i;
    t = strlen(text);
    p = strlen(pattern);

    for (i = 0; i <= t; ++i) {
        int j;

        for (j = 0; j < t; ++j) {
            if(text[i + j] != pattern[j])
                break;
        }
        if (j == p) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main()
{
    char text[200];
    char pattern[30];

    scanf("%s", text);
    scanf("%s", pattern);

    search(text,pattern);

    return 0;
}
