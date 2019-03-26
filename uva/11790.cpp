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
	for (int t = 0; t < T; t++)	{
		int n;
		cin >> n;
		vi hei(n, 0);
		vi wid(n, 0);
		vi mwi(n, 0);
		vi mwd(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> hei[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> wid[i];
			mwi[i] = mwd[i] = wid[i];
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (hei[j] < hei[i] and mwi[j] + wid[i] > mwi[i])
				{
					mwi[i] = mwi[j] + wid[i];
				}
				if (hei[j] > hei[i] and mwd[j] + wid[i] > mwd[i])
				{
					mwd[i] = mwd[j] + wid[i];
				}
			}
		}
		int md = 0, mi = 0;
		for (int i = 0; i < n; ++i)
		{
			if (mwi[i] > mi)
			{
				mi = mwi[i];
			}
			if (mwd[i] > md)
			{
				md = mwd[i];
			}
		}
		if(md > mi){
			printf("Case %d. Decreasing (%d). Increasing (%d).\n", t+1, md , mi);
		} else {
			printf("Case %d. Increasing (%d). Decreasing (%d).\n", t+1, mi , md);
		}
	}
	return 0;
}
