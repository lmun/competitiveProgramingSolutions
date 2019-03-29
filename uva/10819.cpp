#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
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
	int m, n;
	while (cin >> m >> n) {
		if (n == 0)
		{
			cout << "0\n";
			continue;
		}
		int om = m;
		m += 200;
		
		vi price(n, 0);
		vi beauty(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> price[i] >> beauty[i];
		}
		if (om == 0)
		{
			cout << "0\n";
			continue;
		}
		vvi dp(n, vi(m + 1, 0));
		if(price[0]<=m){
			dp[0][price[0]] = beauty[0];
		}
		
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j <= m; ++j)
			{
				if (price[i] > j or (price[i]<j and dp[i - 1][j - price[i]] == 0)) {
					dp[i][j] = dp[i - 1][j];
				} else {
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - price[i]] + beauty[i]);
				}
			}
		}
		int res = 0;
		for (int i = 0; i <= min(om, 2000); ++i)
		{
			res = max(res, dp[n-1][i]);
		}
		for (int i = 2001; i <= m; ++i)
		{
			res = max(res, dp[n-1][i]);
		}
		cout << res << endl;
	}
	return 0;
}
