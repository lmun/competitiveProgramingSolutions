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
bool isposi(int ind, vll &hap, vll &po, vvi &ma, vll &toha, vll &visi){
	ll su = 0;
	visi[ind] = 1;
	for(int a:ma[ind]){
		if (visi[a]>0)
		{
			continue;
		}
		if (!isposi(a, hap, po, ma, toha, visi)){
			return false;
		}
		su += toha[a];
		po[ind] += po[a];
	}
	int tohappy = po[ind]+hap[ind];
	if (tohappy <  0 || tohappy % 2 == 1)
	{
		return false;
	}
	tohappy/=2;
	toha[ind] = tohappy;
	if (toha[ind]>=su && toha[ind] <= po[ind])
	{
		return true;
	}
	return false;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	for (int t = 0; t < T; t++)	{
		int n, m;
		cin >> n >> m;
		vll hapyind(n, 0);
		vll pop(n, 0);
		vvi mat(n, vi());
		vll toha(n, 0);
		vll visi(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> pop[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> hapyind[i];
		}
		for (int i = 0; i < n-1; ++i)
		{
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			mat[a].push_back(b);
			mat[b].push_back(a);
		}
		bool posi = isposi(0, hapyind, pop, mat, toha, visi);
		cout << (posi?"YES":"NO") << endl;
	}
	// for (int i = -20; i < 20; ++i)
	// {
	// 	cout << i << ' ' << abs(i)%2 << endl;
	// }
	return 0;
}
