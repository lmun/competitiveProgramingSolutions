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
vvi nums(5);
vvi minis(25);
ll costo(int i1, int i2, int i3, int i4, int i5) {
	// std::vector<pair<int, int> > pares;
	// pares.push_back(mp(i1 / 5, i1 % 5));
	// pares.push_back(mp(i2 / 5, i2 % 5));
	// pares.push_back(mp(i3 / 5, i3 % 5));
	// pares.push_back(mp(i4 / 5, i4 % 5));
	// pares.push_back(mp(i5 / 5, i5 % 5));
	ll res = 0;
	// for (int i = 0; i < 5; ++i)
	// {
	// 	for (int j = 0; j < 5; ++j)
	// 	{
	// 		ll mindi = inf;
	// 		for (auto pp : pares) {
	// 			mindi = min(mindi, nums[i][j] * (ll)(abs(i - pp.f) + abs(j - pp.s)));
	// 		}
	// 		res += mindi;
	// 	}
	// }
	for (int i = 0; i < 25; ++i)
	{
		res += min(minis[i][i1], min(minis[i][i2], min(minis[i][i3],min(minis[i][i4], minis[i][i5]) )));
	}
	return res;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	for (int t = 0; t < T; t++)	{
		int n;
		cin >> n;
		for (int i = 0; i < 5; ++i)
		{
			nums[i] = vi(5, 0);
		}
		for (int i = 0; i < n; ++i)
		{
			int x, y, b;
			cin >> x >> y >> b;
			nums[x][y] = b;
		}

		ll res = inf;
		int resp[5] = {0,1,2,3,4};
		for (int i = 0; i < 25; ++i)
		{
			minis[i] = vi(25, 0);
		}
		for (int i = 0; i < 25; ++i)
		{
			for (int j = 0; j < 25; ++j)
			{
				minis[i][j] = nums[i/5][i%5]*(abs(i/5-j/5) + abs(i%5-j%5));
			}
		}
		for (int i = 0; i < 25; ++i)
		{
			for (int i2 = i + 1; i2 < 25; ++i2)
			{
				for (int i3 = i2 + 1; i3 < 25; ++i3)
				{
					for (int i4 = i3 + 1; i4 < 25; ++i4)
					{
						for (int i5 = i4 + 1; i5 < 25; ++i5)
						{
							ll co = costo(i, i2, i3, i4, i5);
							if(co < res){
								res = co;
								resp[0] = i;
								resp[1] = i2;
								resp[2] = i3;
								resp[3] = i4;
								resp[4] = i5;
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < 5; ++i)
		{
			if(i){
				cout << ' ';
			}
			cout << resp[i];
		}
		cout << endl;
	}
	return 0;
}
