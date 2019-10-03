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
#define LSOne(S) ((S) & -(S))

class FenwickTree {                    // remember that index 0 is not used
private: vll ft; int n;        // recall that vi is: typedef vector<int> vi;
public: FenwickTree(int _n) : n(_n) { ft.assign(n+1, 0); }    // n+1 zeroes
  FenwickTree(const vi& f) : n(f.size()-1) { ft.assign(n+1, 0);
    for (int i = 1; i <= n; i++) {                                  // O(n)
      ft[i] += f[i];                                      // add this value
      if (i+LSOne(i) <= n)    // if index i has parent in the updating tree
        ft[i+LSOne(i)] += ft[i]; } }       // add this value to that parent
  ll rsq(int j) {                                     // returns RSQ(1, j)
    ll sum = 0; for (; j; j -= LSOne(j)) sum += ft[j];
    return sum; }
  ll rsq(int i, int j) { return rsq(j) - rsq(i-1); }  // returns RSQ(i, j)
  // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
  void update(int i, ll v) {
    for (; i <= n; i += LSOne(i)) ft[i] += v; }    // note: n = ft.size()-1
  int select(int k) { // O(log^2 n)
    int lo = 1, hi = n;
    for (int i = 0; i < 30; i++) { // 2^30 > 10^9 > usual Fenwick Tree size
      int mid = (lo+hi) / 2;                    // Binary Search the Answer
      (rsq(1, mid) < k) ? lo = mid : hi = mid; }
    return hi; }
};

class RUPQ : FenwickTree {    // RUPQ variant is a simple extension of PURQ
public:
  RUPQ(int n) : FenwickTree(n) {}
  ll point_query(int i) { return rsq(i); }
  void range_update(int i, int j, int v) { update(i, v), update(j+1, -v); }
};

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	for (int t = 0; t < T; t++)	{
		int n;
		cin >> n;
		FenwickTree simple = FenwickTree(1000100);
		FenwickTree doble = FenwickTree(1000100);
		FenwickTree simpleb = FenwickTree(1000100);
		FenwickTree dobleb = FenwickTree(1000100);
		ll res = 0;
		for (int i = 0; i < n; ++i)
		{
			// cin >> players[i];
			int aa;
			cin >> aa;
			int bb = 1000050-aa;
			doble.update(aa, simple.rsq(aa-1));
			simple.update(aa, 1);
			res += doble.rsq(aa-1);


			dobleb.update(bb, simpleb.rsq(bb-1));
			simpleb.update(bb, 1);
			res += dobleb.rsq(bb-1);
		}
		cout << res << endl;
	}
	return 0;
}
