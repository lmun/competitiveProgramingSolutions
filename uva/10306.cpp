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
	// cin.ignore(); must be there when using getline(cin, s)
	vi cv;
	vi iv;
	set<pair<pii, int> > se;
	for (int t = 0; t < T; t++)	{
		int m , S;
		cin >> m >> S;
		int rs = S * S;
		cv.resize(m);
		iv.resize(m);
		for (int i = 0; i < m; ++i)
		{
			cin >> cv[i] >> iv[i];
		}
		std::vector<vll > ss(305, vll(305, 0));
		se.clear();
		queue<pair<pii, int> > que;
		que.push(mp(mp(0, 0), 0));
		ll res = inf;
		while (!que.empty()) {
			auto aa = que.front();
			que.pop();
			for (int i = aa.s; i < m; ++i)
			{
				int pa = aa.f.f + cv[i];
				int pb = aa.f.s + iv[i];
				pair<pii, int> np = mp(mp(pa, pb), i);
				if (pa > 304 or pb > 304 or se.count(np) or ss[pa][pb] > 0)
				{
					continue;
				}
				ss[pa][pb] = ss[aa.f.f][aa.f.s] + 1;
				if (pa * pa + pb * pb == rs)
				{
					res = min(res, ss[pa][pb]);
				}
				se.insert(np);
				que.push(np);
			}
		}
		if (res == inf)
		{
			cout << "not possible\n";
		} else {
			cout << res << endl;
		}
	}
	return 0;
}
