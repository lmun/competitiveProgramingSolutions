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
	int n, k;
	cin >> n >> k;
	// cin.ignore(); must be there when using getline(cin, s)
	std::vector<pii > songs;
	for (int t = 0; t < n; t++)	{
		int a, b;
		cin >> a >> b;
		songs.push_back(mp(-b, a));
	}
	sort(songs.begin(), songs.end());
	ll tole = 0;
	ll lb = 10000;
	priority_queue<int, vi, std::greater<int>> hea;
	ll res = 0;
	for (int i = 0; i < k; ++i) {
		hea.push(songs[i].s);
		tole += songs[i].s;
		lb = -songs[i].f;
		// cout << tole << ' ' << lb << endl;
		res = max(res, tole*lb);
		// cout << res << endl;
	}
	for (int i = k; i < n; ++i)
	{
		tole -= hea.top();
		// cout << hea.top() << endl;
		hea.pop();
		hea.push(songs[i].s);
		tole += songs[i].s;
		lb = -songs[i].f;
		// cout << tole << ' ' << lb << endl;
		res = max(res, tole*lb);
		// cout << res << endl;
	}
	cout << res << endl;
	// for(auto aa:songs){
	// 	cout << aa.f << ' ' << aa.s << endl;
	// }
	return 0;
}
