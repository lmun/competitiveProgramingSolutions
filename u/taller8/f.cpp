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
#define pii pair<int, int>
#define pill pair<int, ll>
#define pllpill pair<ll, pill>
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
typedef vector<vector<pill> > wgraph;

void Dijsktra(int s, wgraph &M, vll &dist, vll &padre) {
	dist[s] = 0;
	priority_queue<pllpill, vector<pllpill>, greater<pllpill> > pq; pq.push(mp(0, mp(s,0)));

	while (!pq.empty()) {
		pllpill front = pq.top(); pq.pop();
		int d = front.first;
		ll u = front.s.f,
		z = front.s.s;
		if (d > dist[u]) continue;
		padre[u] = z;
		for (int j = 0; j < (int)M[u].size(); j++) {
			//cout << d << "-" << u << endl;
			pill v = M[u][j];
			//cout << u << "-" << v.f << '-' << v.s << endl;
			//cout << dist[u] << '-'<< v.first << '-'<< dist[v.second]<< endl;
			if (dist[u] + v.first < dist[v.second]) {
				dist[v.second] = dist[u] + v.first;
				pq.push(mp(dist[v.second], mp(v.second, u)));
			} 
		} 
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	std::vector<std::vector<pair<int,ll> > > G(n,vector<pair<int,ll> > (0));
	vll di(n,inf);
	vll pad(n,-1);
	ll a,b;
	int c;
	for (int i = 0; i < m; ++i){
		cin >> a >> b >> c;
		a--,b--;
		G[a].push_back(mp(c,b));
		G[b].push_back(mp(c,a));
	}
	Dijsktra(0,G,di,pad);
	//cout << di[n-1] << ' ' << pad[n-1] << endl;
	int t = n-1;
	if(pad[n-1]==-1){
		cout << -1 << endl;
		exit(0);
	}
	vll cami(1,n);
	while(pad[t] != t){
		cami.push_back(pad[t]+1);
		// cout << pad[t]+1 << endl;
		t = pad[t];
	}
	for (int i = cami.size()-1; i >=0; i--)
	{
		//cout <<i << ' '<< pad[i] << endl;
		cout << cami[i] <<' ';
	}
	cout << endl;
	// cin.ignore(); must be there when using getline(cin, s)
	
	return 0;
}
