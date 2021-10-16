Problem Link : https://www.codechef.com/CDMN21B/problems/NODRUGS

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
        ll n,k,l;
        cin >> n >> k >> l;
        int a[n];
        int max = INT_MIN;
        int i=0;
        int t=n;
        while(n--){
            int x;
            cin >> x;
            a[i]=x;
            if(x>max){
                max = x;
            }
            i++;
        }
        
        int f;
        f = a[t-1] + (k*(l-1));
        if(k<=0 and a[t-1]>=max){
            cout << "Yes" << "\n";
        }
        else if(f>max){
            cout << "Yes" << "\n";
        }
        else{
            cout << "No" << "\n";
        }
    }
    return 0;
}
