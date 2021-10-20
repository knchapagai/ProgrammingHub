#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<unordered_map>
#define umap unordered_map
#define pii pair<int,int>
#define F first
#define S second
#define inf 1000000007
#define fr(i,n) for(int i=0;i<n;i++)
#define pr cout<<
#define en <<endl
#define sp <<' '

using namespace std;
typedef long long ll;

int N,M;
int wt[1001][1001]; 			
ll dis[1001][1001];
vector<int> nbr[1001];

// needs- nbr, wt, dis, N, inf. Complexity - O(V^3). All pair shortest path.
// N=no of vertices. inf=infinity value. ans is in dis(distance array). 
// max_weight*N<inf must be true. If any distance can go >inf make dis=ll,inf =10^18.

bool warshall()
{
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
			dis[i][j]=inf;
		dis[i][i]=0;
	}
	for(int n1=1;n1<=N;n1++)
		for(int n2:nbr[n1])
			dis[n1][n2]=wt[n1][n2];
	
	for(int k=1;k<=N;k++)
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				if(dis[i][j]>dis[i][k]+dis[k][j])
					dis[i][j]=dis[i][k]+dis[k][j];
	
}


main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,n1,n2,w;
	cin>>N>>M;
	
	fr(i,M)
	{
		cin>>n1>>n2 >>w;
		nbr[n1].push_back(n2);
		wt[n1][n2]=w;
		nbr[n2].push_back(n1);
		wt[n2][n1]=w;
	}
	
	warshall();
	
	for(int i=1;i<=N;i++){ for(int j=1;j<=N;j++) pr dis[i][j] sp; pr endl;}
	
}
/*
6 9
1 2 9
1 3 20
1 4 5
2 3 8
3 6 6
3 5 4
3 4 5
4 5 12
6 5 1

0 9 10 5 14 15
0 1 4 1 3 5
*/






