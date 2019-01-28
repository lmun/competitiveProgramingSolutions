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
int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	while (cin >> T) {
		if (T == 0) {
			break;
		}
		std::vector<int> v(T);
		std::vector<int> res(T, 0);
		for (int i = 0; i < T; ++i)
		{

			cin >> v[i];
		}
		int r = T;
		int sum = 0;
		for (int i = 2 * T; i >= 0; --i)
		{
			sum += v[i % T];
			if (v[i % T] < 0 || sum < 0) {
				if (res[i % T] >= 0)
				{
					res[i % T] = -1;
					r--;
				}

			} if (v[i % T] < 0 && sum > v[i % T]) {
				sum = v[i % T];
			}

		}
		cout << r << endl;
	}
	return 0;
}
