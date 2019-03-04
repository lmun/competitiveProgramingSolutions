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
int p,q,r,s,t,u;
double fun(double x){
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cout << setprecision(4) << fixed;
	while(cin >>  p >> q >> r >> s >> t >> u){
		double hi = 1;
		double lo = 0;
		double mid;
		if(fun(lo)*fun(hi)>0){
			cout << "No solution\n";
			continue;
		}
		for (int i = 0; i < 100; ++i)
		{
			mid = (hi+lo)/2;
			if (fun(mid)*fun(hi) > 0)
			{
				hi = mid;
			}else{
				lo = mid;
			}
		}
		// cout << fun(mid) << endl;
		cout << mid << endl;
		// cout << fun(0) << ' ' << fun(1) << endl;
	}
	return 0;
}
