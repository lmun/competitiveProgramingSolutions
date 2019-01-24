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
	int n;
	cin>>n;
	vll di(n,inf);
	string num;
	wgraph mat(n,vector<pii> (0));
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < i; ++j){
			cin >> num;
			if(num[0] != 'x'){
				int d = atoi(num.c_str());
				// printf("%d\t%d\t%d\t %s\n",d,i,j,num.c_str());
				mat[i].push_back(mp(d,j));
				mat[j].push_back(mp(d,i));
			}
		}
	}
	Dijsktra(0,mat,di);
	ll total=0;
	for(ll costo:di){
		total = max(total,costo);
		// cout << costo << endl;
	}
	cout << total << endl;
	// cin.ignore(); must be there when using getline(cin, s)
	
	return 0;
}
