#include <iostream>
using namespace std;

int main()
{
    int n, j, a = 1;
    cin >> n;
    
    cout << "Enter the number of rows: "; 
    
    for (int i = 0; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {        
            cout << a << " "; 
            a++; 
        }
        cout << endl;
    }    
    return 0;
}