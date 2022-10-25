Problem Link : https://www.codechef.com/problems/PASSWD

code : 

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
        string s;
        cin >> s;
        int l = s.length();
        int lc=0,uc=0,dc=0,sc=0;
        for(int i=0;i<l;i++){
            if(s[i]>='a' and s[i]<='z'){
                lc++;
            }
            else if((s[i]>='A' and s[i]<='Z') and (i!=0 and i!=(l-1))){
                uc++;
            }
            else if(s[i]>='0' and s[i]<='9' and (i!=0 and i!=(l-1))){
                dc++;
            }
            else if((s[i]=='@' or s[i]=='#' or s[i]=='%' or s[i]=='&' or s[i]=='?') and (i!=0 and i!=l-1) ){
                sc++;
            }
        }
        
        if(l>=10 and (lc>=1 and uc>=1 and dc>=1 and sc>=1)){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
    return 0;
}
