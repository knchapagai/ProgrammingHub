#include <stdio.h>
#include <string.h>

int main () {
    char s1[45], s2[45];
    scanf("%s %s", s1, s2);

    char temp;
    int i, j;
    int n  = strlen(s1);
    int n1 = strlen(s2);

    if( n != n1) {
        printf("Strings are not anagrams! \n", s1, s2);
        return 0;
    }

    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (s1[i] > s1[j]) {
                temp  = s1[i];
                s1[i] = s1[j];
                s1[j] = temp;
            }
            if (s2[i] > s2[j]) {
                temp  = s2[i];
                s2[i] = s2[j];
                s2[j] = temp;
            }
        }
    }

    for(i = 0; i<n; i++) {
        if(s1[i] != s2[i]) {
            printf("Strings are not anagrams! \n", s1, s2);
            return 0;
        }
    }

    printf("Strings are anagrams! \n");
    return 0;
}
