void rotate(int **input, int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Taking input and printing output is handled automatically.
     */
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
#include<iostream>
using namespace std;


int main() {
    int n;
    cin >> n;
    
    int **input = new int*[n];
    
    for(int i = 0; i < n; i++) {
        input[i] = new int[n];
        for(int j = 0; j < n; j++) {
            cin >> input[i][j];
        }
    }
    
    rotate(input, n);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }
}
