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
	// cin.ignore(); must be there when using getline(cin, s)
	while (cin >> t) {
		int tot = 1 << t;
		vi aris(tot, 0);
		vi nei(tot, 0);
		for (int i = 0; i < tot; ++i) {
			cin >> aris[i];
		}

		for (int i = 0; i < tot; ++i) {
			for (int j = 0; j < t; ++j) {
				nei[i] += aris[i^(1<<j)];
			}
			// cout << nei[i] << endl;
		}
		int maxi = 0;
		for (int i = 0; i < tot; ++i) {
			for (int j = 0; j < t; ++j) {
				int vesi = i^(1<<j);
				// nei[i] += aris[i^(1<<j)];
				maxi = max(maxi, nei[i] + nei[vesi]);
			}
		}
		cout << maxi << endl;
	}
	return 0;
}
