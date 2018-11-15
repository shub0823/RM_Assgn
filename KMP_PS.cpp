#include<bits/stdc++.h>

void compute_LPS_array(char *pattern, int p, int *lps);

void KMP_search(char *text, char *pattern)
{
    int p;
    int t;
    t = strlen(text);
    p = strlen(pattern);

    int lps[p];//create lps array of characters that will hold the longest prefix suffix values for pattern

    compute_LPS_array(pattern, p, lps);

    int i;
    int j;
    i = 0;
    j = 0;

    while (i < t) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }
        if (j == p) {
            printf("Given Pattern is found at index %d\n", i - j);
            j = lps[j - 1];
        }
        else if (i < t && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i += 1;
        }
    }
}

void compute_LPS_array(char *pattern, int p, int *lps)
{
    int l;
    l = 0;

    lps[0] = 0;//lps[0] is always 0

    int i;
    i = 1;

    while (i < p) {
        if (pattern[i] == pattern[l]) {
            l++;
            lps[i] = l;
            i++;
        }
        else {
            if (l != 0) {
                l = lps[l - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main()
{
    char text[200];
    char pattern[30];

    scanf("%s", text);
    scanf("%s", pattern);

    KMP_search(text, pattern);

    return 0;
}
