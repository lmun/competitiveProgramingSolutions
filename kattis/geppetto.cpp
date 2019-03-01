#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
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
vi ing(0);
vi visi(0);
int res, n, m;
void dfs(int nu, int av){
	if (visi[nu]){
		return;
	}
	// cout << nu << ' ' << av << endl;
	visi[nu] = 1;
	res++;
	for (int i = 0; i < n; ++i)
	{
		if ((av & (1<<i)) == 0)
		{
			dfs(nu|(1<<i), av|ing[i]);
		}
	}
	return;
}
int main() {
	std::ios::sync_with_stdio(false);
	
	res = 0;
	cin >> n >> m;
	// cin.ignore(); must be there when using getline(cin, s)
	ing.resize(n);
	for (int i = 0; i < n; ++i) {
		ing[i] = 1<<i;
	}
	visi.resize(1<<n, 0);
	for (int i = 0; i < m; ++i)
	{
		int a,b;
		cin >> a>> b;
		a--,b--;
		ing[a] |= (1<<b);
		ing[b] |= (1<<a);
	}
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << ing[i] << endl;
	// }
	dfs(0,0);
	cout << res << endl;
	return 0;
}
