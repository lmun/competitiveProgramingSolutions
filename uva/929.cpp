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
#define vvll vector < vll >
#define pii pair<int,int>
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
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	int x, y;
	int dir[4][2] = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};
	while (t--) {
		cin >> x >> y;
		vvll mat(x + 2, vll(y + 2, inf));
		vvll minis(x + 2, vll(y + 2, inf));

		priority_queue<pllpii, vector<pllpii>, greater<pllpii> > pq;


		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < y; ++j) {
				cin >> mat[i + 1][j + 1];
			}
		}
		pq.push(mp(mat[1][1], mp(1, 1)));
		minis[1][1] = mat[1][1];
		while (!pq.empty()) {
			pllpii front = pq.top();
			pq.pop();
			int a = front.s.f, b = front.s.s;
			ll c = front.f;
			// cout << c << ' '<< a << ' '<< b << ' ' << minis[a][b] << endl;
			if (c > minis[a][b]) continue;
			//cout << "waaaaa";
			for (int i = 0; i < 4; ++i) {
				if (c + mat[a + dir[i][0]][b + dir[i][1]] < minis[a + dir[i][0]][b + dir[i][1]]) {

					minis[a + dir[i][0]][b + dir[i][1]] = c + mat[a + dir[i][0]][b + dir[i][1]];
					pq.push(mp(minis[a + dir[i][0]][b + dir[i][1]], mp(a + dir[i][0], b + dir[i][1])));
				}
			}
		}
		cout << minis[x][y] << endl;
	}

	return 0;
}
