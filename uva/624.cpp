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
	int m, n;
	while(cin >> m >> n){
		vi tracks(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> tracks[i];
		}
		ll bestsum = 0;
		ll besti = 0;
		for (int i = 0; i < (1<<n); ++i)
		{
			ll sum = 0;
			for (int j = 0; j < n; ++j)
			{
				if(i & 1<<j){
					sum += tracks[j];
				}
			}
			if(sum <= m && sum > bestsum){
				besti = i;
				bestsum = sum;
			}
		}
		for (int j = 0; j < n; ++j) {
				if(besti & 1<<j){
					cout << tracks[j] << ' ';
				}
			}
		cout << "sum:" << bestsum << endl;
	}
	return 0;
}
