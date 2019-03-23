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
	int ma = 3000005;
	std::vector<long double> logs(ma, 0.0);
	for (int i = 2; i < ma; ++i)
	{
		logs[i] = logs[i-1]+log(i);
	}
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	for (int t = 0; t < T; t++)	{
		int a;
		cin >> a;
		int lo = 0, hi = ma-1;
		long double la = log(a);
		while(hi> lo){
			int mid = (hi+lo)/2;
			if(logs[mid] <= mid*la){
				lo = mid+1;
			} else {
				hi = mid;
			}
		}
		cout << lo << endl;
	}
	return 0;
}
