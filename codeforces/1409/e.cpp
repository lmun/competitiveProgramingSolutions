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
#define vpii vector<pii >
#define wgraph vector<vpii >
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
	// cin.ignore(); must be there when using getline(cin, s)
	for (int t = 0; t < T; t++)	{
		ll n,k;
		cin >> n >> k;
		vll xx(n+1,inf);
		vll yy(n+1,inf);
		for (int i = 0; i < n; ++i)
		{
			cin >> xx[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> yy[i];
		}
		sort(xx.begin(), xx.end());
		
		vll salva(n+1,0);
		ll res = 0;
		for (int i = n-1; i >=0; --i)
		{
			int mi = i,ma=n;
			while(ma>mi){
				int mid = (ma+mi)/2;
				if (xx[i] + k >= xx[mid])
				{
					mi = mid+1;
				}else{
					ma = mid;
				}
			}
			if (ma-i + salva[ma]>res)
			{
				res = ma-i + salva[ma];
			}
			salva[i] = ma-i > salva[i+1] ? ma-i : salva[i+1];
		}
		// for(ll x:xx){
		// 	cout << x << ' ';
		// }
		// cout << endl;
		// for(ll x:salva){
		// 	cout << x << ' ';
		// }
		// cout << endl;
		cout << res << endl;
	}
	return 0;
}
