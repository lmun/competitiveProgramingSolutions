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
int n;
int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	for (int t = 0; t < T; t++)	{
		cin >> n;
		char cha;
		int co = 0;
		vi zero(0);
		vi uno(0);
		vi resp(n);
		int este;
		for (int i = 0; i < n; ++i)
		{
			cin >> cha;
			if (cha=='0')
			{
				if (uno.size()==0)
				{
					este = ++co;
				}else{
					 este = uno.back();
					 uno.pop_back();
				}
				zero.push_back(este);
				resp[i] = este;
			} else {
				if (zero.size()==0)
				{
					este = ++co;
				}else{
					este = zero.back();
					zero.pop_back();
				}
				uno.push_back(este);
				resp[i] = este;
			}
		}
		cout << co << endl;
		for (int i = 0; i < n; ++i)
		{
			if (i)
			{
				cout << ' ';
			}
			cout << resp[i];
		}
		cout << endl;
	}
	return 0;
}
