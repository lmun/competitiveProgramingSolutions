#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
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

	ll gcd( ll a, ll b )
	{
		if(b==0)
		{
		     return a;
		}
		else
		{
		     return gcd( b, a%b );
		}
	}
	ll lcm (ll a, ll b)
	{
		return (a*b)/gcd(a,b);
	}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	while(n--){
		int k;
		cin >> k;
		ll act=1;
		for (int i = 1; i <= k; ++i)
		{
			act=lcm(act,i);
		}
		cout << act << endl;
	}
	return 0;
}
