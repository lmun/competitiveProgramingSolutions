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
int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)	{
		int n;
		cin >> n;
		std::vector<vvi > wa(n, vvi(n, vi(n, 0)));
		int res = -100000;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> wa[0][i][j];
				res = max(res, wa[0][i][j]);
			}
		}
		for (int w = 1; w < n; ++w) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					wa[w][i][j] = wa[w-1][i][j] + wa[0][i][(j+w)%n];
					res = max(res, wa[w][i][j]);
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			vvi mima(n, vi(n,0));
			for (int j = 0; j < n; ++j)
			{
				for (int x = 0; x < n; ++x)
				{
					for (int y = 0; y < n; ++y)
					{
						mima[x][y] += wa[i][(x+j)%n][y];
						res = max(res, mima[x][y]);
					}
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}
