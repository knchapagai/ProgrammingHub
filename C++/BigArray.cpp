Problem Link : https://www.codechef.com/problems/BIGARRAY

Code :

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
    ll t;
    cin >> t;
    while(t--){
        ll n,s;
        cin >> n >> s;
        
        ll sum = n*(n+1)/2;
        
        if(s >= (sum-n) and s<= (sum-1)){
            cout << sum-s << "\n";
        }
        else{
            cout << "-1" << "\n";
        }
        
    }
    return 0;
}
