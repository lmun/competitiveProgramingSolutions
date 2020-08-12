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
int main()
{
	std::ios::sync_with_stdio(false);
	int n,m;
	cin >> n>> m;
	// cin.ignore(); must be there when using getline(cin, s)
	vi ene(n,0);
	vi eme(m,0);
	vvi mat(n,vi(m,0));
	for (int i = 0; i < n; ++i)
	{
		cin >> ene[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin  >> eme[i];
	}
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << ene[i]<< ' ';
	// }
	// cout << endl;
	// for (int i = 0; i < m; ++i)
	// {
	// 	cout << eme[i]<< ' ';
	// }
	// cout << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			mat[i][j] = ene[i]&eme[j];
		}
	}


	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < m; ++j)
	// 	{
	// 		cout << mat[i][j] << '\t';
	// 	}
	// 	cout << endl;
	// }


	for (int t = 0; t < 550; ++t)
	{
		bool ispo = true;
		int note = ~t;
		bool pos = true;
		for (int i = 0; i < n and pos; ++i)
		{
			pos = false;
			// cout << note;
			// note = ~147;
			for (int j = 0; j < m; ++j)
			{
				// cout << i<< ' ' << j << ' '<< (note&mat[i][j])<< endl;
				if ((note&mat[i][j])==0)
				{
					pos = true;
					// cout << note << '.'<< mat[i][j]<<' ' << i<<' ' << j << endl;
					break;
				}
			}
			// cout << pos << endl;
		}
		if (pos)
		{
			cout << t << endl;
			break;
		}
	}
	return 0;
}
