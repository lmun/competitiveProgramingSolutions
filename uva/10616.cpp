#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector< ll >
#define vll vector<ll>
#define vvi vector < vll >
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
	int n, q;
	int t = 0;
	while (cin >> n >> q) {
		if(n==0 and q == 0){
			break;
		}
		cout << "SET " << ++t << ':' << endl;
		vi nums(n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> nums[i];
		}
		for (int aa = 1; aa <= q; ++aa)
		{	// por cada query
			int m, d;
			cin >> d >> m;
			vi numos(n, 0);
			
			vvi dp(n, vi(d, 0));
			for (int i = 0; i < n; ++i)
			{
				numos[i] = nums[i]%d;
				if(numos[i]<0){
					numos[i]+=d;
				}
				dp[i][numos[i]] = 1;
			}
			for (int j = 1; j < m; ++j)
			{	//cada grupo de j
				vvi ndp(n, vi(d, 0));
				for (int k = j; k < n; ++k)
				{	//cada numero
					// int monu = nums[i] % d;
					for (int l = max(j-1, 0); l < k; ++l)
					{
						for (int p = 0; p < d; ++p)
						{
							ndp[k][(p+numos[k])%d] += dp[l][p];
						}
						
					}
				}
				dp = ndp;
			}
			ll resp = 0;
			for (int i = 0; i < n; ++i)
			{
				resp +=dp[i][0];
			}
			cout << "QUERY " << aa << ": "<<resp << endl;
		}
	}

	return 0;
}
