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
	int n;
	while(cin >> n){
	// cin.ignore(); must be there when using getline(cin, s)
	ll nums[n][n];
	ll susu[n+1][n+1];
	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < n+1; ++j)
		{
			susu[i][j] = 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < n; ++k) {
			cin >> nums[i][k];
			susu[i+1][k+1] = nums[i][k];
			if (i) {
				susu[i+1][k+1] += susu[i][k+1];
				if (k) {
					susu[i+1][k+1] -= susu[i][k];
				}
			}
			if (k)
			{
				susu[i+1][k+1] += susu[i+1][k];
			}
		}
	}
	ll res = -inf;
	for (int i = 1; i < n+1; ++i) {
		for (int j = 1; j < n+1; ++j) {
			for (int ii = 0; ii < i; ++ii)
			{
				for (int jj = 0; jj < j; ++jj)
				{
					res = max(res, susu[i][j]-susu[i][jj]-susu[ii][j]+susu[ii][jj]);
				}
			}
		}
	}
	cout << res << endl;}
	return 0;
}
