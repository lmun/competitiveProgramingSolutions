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
	int t;
	cin >> t;
	// cin.ignore(); must be there when using getline(cin, s)
	while (t--)
	{
		int n, a, b;
		std::vector<pii> v;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a >> b;
			v.push_back(mp(a, b));
		}
		int y = n - 1;
		long double area = 0;
		for (int i = 0; i < n; ++i) {
			area += (v[y].f + v[i].f) * (v[y].s - v[i].s);
			y = i;
		}
		cout << abs(area/2) << endl;
	}
	return 0;
}
