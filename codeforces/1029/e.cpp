#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;
int res;
int dfs(int a, int b, vvi &mat, vi &vis){
	//printf("%d\t%d\n", a, b);
	if(vis[a]){
		return 0;
	}
	vis[a]=1;
	int niet=0;
	for(int k : mat[a]){
		niet += mat[k].size();
	}	
	if((b == 2 && mat[a].size() > 2) || b > 2){
		b=1;
		res++;
	}
	for(int k : mat[a]){
		dfs(k, b+1, mat, vis);
	}
	return 0;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int n, a, b;
	cin>>n;
	res = 0;
	vvi mat(n, vi(0));
	vi visi(n, 0);
	int t=n-1;
	while(t--){
		cin >> a >> b;
		a--, b--;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}
	visi[0]=1;
	for(int a : mat[0]){
		dfs(a, 1, mat, visi);
	}
	cout << res << endl;
	return 0;
}
