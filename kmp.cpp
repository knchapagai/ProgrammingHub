#include <bits/stdc++.h>
using namespace std;


void printer(int *arr, int m)
{
    for(int i = 0 ; i < m ; i++)
        cout << arr[i] << " ";
}

int *kmpPrefix(char *str)
{
    int q, k, m = strlen(str);
    int *pref = new int[m];
    pref[0] = 0;
    k = 0;
    for(q = 1 ; q < m ; q++)
    {
        while(k > 0 && str[k] != str[q])
            k = pref[k-1];
        if(str[k] == str[q])
            k++;
        pref[q] = k;
    }
    return pref;
}

void matcher(char *txt, char *pat)
{
    int q, i, n = strlen(txt), m = strlen(pat), *pi = kmpPrefix(pat);
    for(i = 0 ; i < n ; i++)
    {
        while(q > 0 && pat[q] != txt[i])
            q = pi[q-1];
        if(pat[q] == txt[i])
            q++;
        if(q == m-1)
        {
            cout << "\nPattern found with shifts: " << i-q+1;
            q = pi[q]-1;
        }
    }
}

int main()
{
    char p[] = "ABABCABAB", t[] = "ABABDABACDABABCABAB";
    // int *pi = kmpPrefix(p, 7);
    // printer(pi, 7);
    matcher(t, p);
    return 0;
}