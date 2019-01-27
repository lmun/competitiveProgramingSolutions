#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
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
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	while (T--)	{
		int h, w;
		cin >> h >> w;
		std::vector<std::vector<int> > v(h, std::vector<int> (w, 0));
		for (int i = 0; i < h; ++i)
		{	
			for (int j = 0; j < w; ++j)
			{
				cin >> v[i][j];
			}
		}
		std::vector<std::vector<int> > v2(h, std::vector<int> (w, 0));
		v2[h - 1] = v[h - 1];
		for (int k = h - 2; k >= 0; k--)
		{
			if (w == 1) {
				v2[k][0] = v2[k + 1][0] + v[k][0];
			} else {
				v2[k][0] = v[k][0] + max(v2[k + 1][0], v2[k + 1][1]);
				v2[k][w - 1] = v[k][w - 1] + max(v2[k + 1][w - 1], v2[k + 1][w - 2]);
				for (int g = 1; g < w - 1; ++g)
				{
					v2[k][g] = v[k][g] + max(v2[k + 1][g - 1], max(v2[k + 1][g], v2[k + 1][g + 1]));
				}
			}
		}
		int res = 0;
		for (int i = 0; i < w; ++i)
		{
			res = max(res, v2[0][i]);
		}
		cout << res << endl;
	}
	return 0;
}