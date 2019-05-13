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
int visita(vvi &mat, vi &visi, int ind) {
	visi[ind] = 1;
	int a = 0, b = 0;
	int mevi = 0;
	for (int aa : mat[ind]) {
		if (visi[aa] == 0) {
			mevi = max(mevi, visita(mat, visi, aa));
			if (visi[aa] >= visi[ind]) {
				visi[ind] = visi[aa] + 1;
			}
			int c = visi[aa];
			if (c > a) {
				b = a;
				a = c;
			} else if (c > b) {
				b = c;
			}
		}
	}
	return max(mevi, a + b);
}
int main()
{
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	// cin.ignore(); must be there when using getline(cin, s)
	vvi mat(N, vi());
	int a, b;
	for (int t = 0; t < N - 1; t++)	{
		cin >> a >> b;
		a--, b--;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}
	vi visi(N, 0);
	int res = visita(mat, visi, 0);
	a = 0, b = 0;
	for (int aa : mat[0]) {
		int c = visi[aa];
		if (c > a) {
			b = a;
			a = c;
		} else if (c > b) {
			b = c;
		}
	}
	cout << max(a + b, res) << endl;
	return 0;
}
