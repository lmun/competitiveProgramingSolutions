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
#define pllpii pair<long long, pii>
#define mod 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;
wgraph tree;
vi visi;
ll sum;
ll aux(int root, priority_queue<pllpii, vector<pllpii>> &pq){
	ll hojas = 0;
	visi[root] = 1;
	for(auto a:tree[root]) {
		if (visi[a.f])
		{
			continue;
		}
		ll ehojas = aux(a.f, pq);
		// cout << a.f << ' ' << a.s << endl;
		sum += ehojas*a.s;
		pq.push(mp((a.s-a.s/2)*ehojas, mp(a.s, ehojas)));
		hojas+=ehojas;
	}
	if(hojas==0){
		return 1;
	}
	return hojas;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	for (int t = 0; t < T; t++)	{
		ll n, mas;
		cin >> n >> mas;
		tree.assign(n,vpii(0));
		visi.assign(n,0);
		int v,u,w;
		sum = 0;
		for (int i = 0; i < n-1; ++i)
		{
			cin >> v >> u >>w;
			v--,u--;
			tree[v].push_back(mp(u,w));
			tree[u].push_back(mp(v,w));
		}
		priority_queue<pllpii, vector<pllpii> > pq;
		aux(0, pq);
		// cout << sum << endl;
		int wa = 0;
		// while(!pq.empty()){
		// 	pllpii top = pq.top();
		// 	pq.pop();
		// 	cout << top.f << ' ' << top.s.f << ',' << top.s.s << endl;
		// }
		while(sum > mas){
			wa++;
			pllpii top = pq.top();
			pq.pop();
			sum -= top.f;
			ll h = top.s.s;
			ll a = top.s.f/2;
			pq.push(mp((a-a/2)*h, mp(a, h)));
			// cout << sum << endl;
		}
		cout << wa << endl;
		// cout << endl;
	}
	return 0;
}
