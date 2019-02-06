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
int main()
{
	std::ios::sync_with_stdio(false);
	int c, r, q;
	int nute = 1;
	while (cin >> c >> r >> q) {
		if (c == 0 && r == 0 && q == 0) {
			break;
		}
		// cin.ignore(); must be there when using getline(cin, s)
		vi costos(c, 0);
		for (int i = 0; i < c; ++i) {
			cin >> costos[i];
		}
		vvi gra(c, vi (c, mod));
		vvi mac(c, vi (c, mod));
		for (int i = 0; i < c; ++i) {
			for (int j = 0; j < c; ++j) {
				mac[i][j] = max(costos[i], costos[j]);
			}
		}
		int a, b, p;
		while (r--) {
			cin >> a >> b >> p;
			a--, b--;
			gra[a][b] = p;
			gra[b][a] = p;
		}
		int tt = 3;
		while (tt--)
			for (int i = 0; i < c; ++i) {
				for (int j = 0; j < c; ++j) {
					for (int k = 0; k < c; ++k) {
						if (gra[i][j] + mac[i][j] > gra[i][k] + gra[k][j] + max(mac[i][k], mac[k][j])) {
							gra[i][j] = gra[i][k] + gra[k][j];
							gra[j][i] = gra[j][k] + gra[k][i];
							mac[i][j] = max(mac[i][k], mac[k][j]);
							mac[j][i] = max(mac[j][k], mac[k][i]);
						}
					}
				}
			}
		if (nute > 1)
		{
			cout << endl;
		}
		cout << "Case #" << nute++ << endl;
		while (q--) {
			int o, d;
			cin >> o >> d;
			int este = mac[o - 1][d - 1] + gra[o - 1][d - 1];
			if (este >= mod) {
				cout << -1 << endl;
			} else {
				cout << este << endl;
			}
		}

	}
	return 0;
}
