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
#define vpii vector<pii >
#define wgraph vector<vpii >
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
int n,a,b,da,db, u, v, madi;
vvi mat;
int aux(int pa, int pe){
	int ma = 0;
	for(int aa: mat[pe]){
		if (aa!=pa)
		{
			int me = 1 + aux(pe,aa);
			if (ma+me>madi)
			{
				madi = ma+me;
			}
			if (me > ma)
			{
				ma = me;
			}
		}
	}
	return ma;
}
int busca(int pa, int pe, int pi){
	for(int aa: mat[pe]){
		if(aa==pi){
			return 1;
		}
		if (aa!=pa)
		{
			int me = busca(pe,aa,pi);
			if (me>0)
			{
				return me+1;
			}
		}
	}
	return 0;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	for (int t = 0; t < T; t++)	{
		cin >> n >> a >> b >>da >> db;
		a--,b--;
		madi = 0;
		mat.assign(n,vi(0));
		for (int i = 0; i < n-1; ++i)
		{
			cin >> u >>v;
			u--,v--;
			mat[u].push_back(v);
			mat[v].push_back(u);
		}
		aux(-1,0);
		int odi = busca(-1,a,b);
		string winner = "Alice";
		if (da<odi and db>2*da and madi > 2*da)
		{
			winner = "Bob";
		}
		// cout << (da<odi) <<  (db>=2*da+1) <<  (madi >= 2*da+1)<< endl;
		cout << winner << endl;
		// cout << madi << ' ' << odi << endl;
	}
	return 0;
}
