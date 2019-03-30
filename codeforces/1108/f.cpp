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
class UnionFind {                                              // OOP style
private:
	vi p, rank, setSize;                       // remember: vi is vector<int>
	int numSets;
public:
	explicit UnionFind(int N) {
		setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
		p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i;
	}
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			numSets--;
			int x = findSet(i), y = findSet(j);
			// rank is used to keep the tree short
			if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
			else                   {
				p[x] = y; setSize[y] += setSize[x];
				if (rank[x] == rank[y]) rank[y]++;
			}
		}
	}
	int numDisjointSets() { return numSets; }
	int sizeOfSet(int i) { return setSize[findSet(i)]; }
};
int main()
{
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	// cin.ignore(); must be there when using getline(cin, s)
	std::vector<pair<int, pii > > edges;
	for (int t = 0; t < m; t++)	{
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		edges.push_back(mp(w, mp(u, v)));
	}
	sort(edges.begin(), edges.end());
	UnionFind uni(n);
	int i = 0;
	int resp = 0;
	while (i < m) {
		int j = i;
		while (j < m and edges[i].f == edges[j].f) {
			j++;
		}
		int posi = 0;
		for (int k = i; k < j; ++k) {
			if (!uni.isSameSet(edges[k].s.f, edges[k].s.s)) {
				posi++;
			}
		}
		int act = 0;
		for (int k = i; k < j; ++k) {
			if (!uni.isSameSet(edges[k].s.f, edges[k].s.s)) {
				uni.unionSet(edges[k].s.f, edges[k].s.s);
				act++;
			}
		}
		resp += posi - act;
		i = j;
	}
	cout << resp << endl;
	// for (auto aa : edges) {
	// 	cout << aa.f << endl;
	// }
	return 0;
}
