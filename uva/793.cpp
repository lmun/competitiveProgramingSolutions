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
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	for (int t = 0; t < T; t++)	{
		int n ;
		cin >> n;
		UnionFind uni(n);
		cin.ignore();
		string st;
		int res[] = {0, 0};
		while (getline(cin, st)) {
			if (!st.size() || (st[0] != 'c' && st[0] != 'q')) {
				break;
			}
			stringstream ss(st);
			char ch;
			int a, b;
			ss >> ch >> a >> b;
			a--, b--;
			if (ch == 'q')
			{
				res[uni.isSameSet(a, b)]++;
			} else {
				uni.unionSet(a, b);
			}
		}
		if (t)
		{
			printf("\n");
		}
		printf("%d,%d\n", res[1], res[0]);


	}
	return 0;
}
