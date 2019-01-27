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

std::vector<int> divisor(ll a, std::vector<int> &p) {
	std::vector<int> res;

	ll u = p[a];
	while (u > 1) {
		res.push_back(p[a]);
		while (a % u == 0) {
			a /= u;
		}
		u = p[a];
	}
	return res;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	long long x = 1000001;
	std::vector<int> p(x, 0);
	std::vector<int> pri;
	for (ll i = 2; i < x; ++i) {
		if (p[i] == 0) {
			pri.push_back(i);
			p[i] = i;
			for (long long a = i * i; a < x; a += i) {
				if (p[a] == 0) {
					p[a] = i;
				}
			}
		}
	}
	ll n;

	while (T--)
	{
		cin >> n;
		std::vector<int> divi = divisor(n, p);
		ll res = n - 1;
		for (ll i = ((1 << divi.size()) - 1); i > 0; --i)
		{
			//cout << i << " ";
			ll m = 1;
			ll a = i;
			ll c = 0;
			for (unsigned j = 0; j < divi.size(); ++j)
			{
				if ((a >> j) & 1) {
					c++;
					m *= divi[j];
				}
			}
			if (c % 2) {
				res -= ((n / m) - 1);
			} else {
				res += ((n / m) - 1);
			}
		}
		res = res > 0 ? res : 1;
		printf("%lld\n", res);
	}
	return 0;
}