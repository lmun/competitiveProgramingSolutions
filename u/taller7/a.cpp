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
#define pii pair<int,ll>
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
typedef vector<vector<pii> > wgraph;

void Dijsktra(int s, wgraph &M, vll &dist) {
	dist[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq; pq.push(mp(0, s));

	while (!pq.empty()) {
		pii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if (d > dist[u]) continue;

		for (int j = 0; j < (int)M[u].size(); j++) {
			//cout << d << "-" << u << endl;
			pii v = M[u][j];
			//cout << u << "-" << v.f << '-' << v.s << endl;
			//cout << dist[u] << '-'<< v.first << '-'<< dist[v.second]<< endl;
			if (dist[u] + v.first < dist[v.second]) {
				dist[v.second] = dist[u] + v.first;
				pq.push(mp(dist[v.second], v.second));
			} 
		} 
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int n,m,s,t;
	for (int k = 1; k <= N; ++k)
	{
		cin >> n >> m >> s >> t;
		std::vector<std::vector<pair<int,ll> > > G(n,vector<pair<int,ll> > (0));
		vll di(n,inf);
		int a,b;
		ll c;
		while(m--){
			cin >> a >> b >> c;
			G[a].push_back(mp(c,b));
			G[b].push_back(mp(c,a));
		}
		Dijsktra(s,G,di);
		cout << "Case #"<< k <<':' << ' ';
		if(di[t]<inf){
			cout << di[t] << endl;
		}else{
			cout << "unreachable\n";
		}
	}
	
	return 0;
}
