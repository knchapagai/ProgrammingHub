void stringCompression(char input[]) {
    // Write your code here
    int k;
    for (int i=0; i<n; i++)
    {
        k=n-1;
        for (int j=0; j<k; j++)
        {
            swap(input[i][j], input[i][k]);
            k--;
        }  
    }
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            swap(input[i][j], input[j][i]);
}
#include <iostream>
#include <cstring>
#include<string>
using namespace std;

//#include "solution.h"

int main() {
    int size = 1e6;
    string str;
    cin >> str;
    str = getCompressedString(str);
    cout << str << endl;
}
