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
#define inf 100000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;
typedef vector<vector<pii> > wgraph;

void Dijsktra(int sa, wgraph &M, vll &dist) {
	dist[sa] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq; pq.push(mp(0, sa));

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
	int n, m;
	n = 30;
	while (cin >> m) {
		if (m == 0) {
			break;
		}
		std::vector<std::vector<pair<int, ll> > > Gy(n, vector<pair<int, ll> > (0));
		std::vector<std::vector<pair<int, ll> > > Gm(n, vector<pair<int, ll> > (0));
		vll diy(n, inf);
		vll dim(n, inf);
		char age, uni, a, b;
		ll c;
		while (m--) {
			cin >> age >> uni >> a >> b >> c;
			if (age == 'Y') {
				Gy[a - 'A'].push_back(mp(c, b - 'A'));
				if (uni == 'B') {
					Gy[b - 'A'].push_back(mp(c, a - 'A'));
				}
			} else {
				Gm[a - 'A'].push_back(mp(c, b - 'A'));
				if (uni == 'B') {
					Gm[b - 'A'].push_back(mp(c, a - 'A'));
				}
			}
		}
		char yo, pro;
		cin >> yo >> pro;
		//cout << "aa" << endl;
		Dijsktra(yo - 'A', Gy, diy);
		Dijsktra(pro - 'A', Gm, dim);
		//cout << "Case #"<< k <<':' << ' ';
		vll di(n);
		for (int i = 0; i < n; ++i)
		{
			di[i] = dim[i] + diy[i];
		}
		ll mini = inf;

		for (int i = 0; i < n; ++i)
		{
			if (mini > di[i]) {
				mini = di[i];
			}
		}
		if (mini < inf) {
			cout << mini;
			for (int i = 0; i < n; ++i)
			{
				if (di[i] == mini) {
					cout << ' ' << (char)(i + 'A');
				}
			}
			cout << endl;
		} else {
			cout << "You will never meet." << endl;
		}

	}
	return 0;
}
