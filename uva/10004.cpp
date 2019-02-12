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
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int n, l;
	for (;;) {
		cin >> n;
		if (0 == n) {
			break;;
		}
		cin >> l;
		bool colorable = true;
		std::vector<std::vector<int> > v(n, std::vector<int>());
		std::vector<int> bicolor(n, 0);
		std::vector<int> visitados(n, 0);
		int a, b;
		for (int i = 0; i < l; ++i) {
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		bicolor[0] = 1;
		queue<int> q;
		q.push(0);

		while (!q.empty() && colorable) {
			int u = q.front();
			q.pop();
			visitados[u] = 1;
			for (int k : v[u]) {
				if (!visitados[k]) {
					q.push(k);
				}
				if (bicolor[k] > 0) {
					if ((bicolor[k] % 2) == (bicolor[u] % 2)) {
						colorable = false;
						//printf("%d\t%d\n",k,u );
						break;
					}
				} else {
					bicolor[k] = bicolor[u] + 1;
				}
			}
		}
		cout << (!colorable ? "NOT BICOLORABLE." : "BICOLORABLE.") << endl;



	}
	return 0;
}
