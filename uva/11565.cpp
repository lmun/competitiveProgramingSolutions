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
		int a, b, c;
		cin >> a >> b >> c;
		bool found = false;
		int ra, rb, rc;
		for (int i = -100; i <= 100 && !found; ++i)
		{
			for (int j = i+1; j <= 100 && !found; ++j)
			{
				int ij = i*i+j*j;
				int k = a-i-j;
				if (k <= j)
				{
					continue;
				}
				if(ij+k*k == c && i*j*k == b){
					found = true;
					ra = i;
					rb = j;
					rc = k;
				}
			}
		}
		if (found)
		{
			cout << ra << ' ' << rb << ' ' << rc << endl;
		} else {
			cout << "No solution.\n";
		}
	}
	return 0;
}
