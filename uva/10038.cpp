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
	int n;
	while(cin >> n){
		std::vector<int> v(n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		std::vector<int> jol(n,0);
		for (int i = 0; i < n-1; ++i)
		{
			int d = abs(v[i+1]-v[i]);
			if (d<n)
			{
				jol[d] += 1;
			}
		}
		bool pos = true;
		for (int i = 1; i < n; ++i)
		{
			if(jol[i]!=1){
				pos = false;
			}
		}
		cout << (pos?"J":"Not j") << "olly"<< endl;
	}
	return 0;
}
