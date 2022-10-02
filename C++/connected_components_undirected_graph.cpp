#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector <int> g[N];
bool vis[N];
void dfs(int vertex){
    vis[vertex] = true;
    for(int child:g[vertex]){
        if(vis[child]) continue;
        dfs(child);
    }
}
int main() {
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;-g[x].push_back(y);
        g[y].push_back(x);
 
    }
    int ct =0;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        dfs(i);
        ct++;
    }
    cout<<ct;
}

