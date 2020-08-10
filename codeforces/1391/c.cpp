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
ll modpow(ll base, ll exp, ll m) {

   ll result = 1;

   while (exp > 0) {
      if ((exp & 1) > 0) result = (result * base) % m;
      exp >>= 1;
      base = (base * base) % m;
   }

   return result;

 }
ll recfact(ll start, ll n) {
    ll i;
    if (n <= 16) { 
        ll r = start;
        for (ll i = start + 1; i < start + n; i++){
         r *= i;
         r%=mod;
     	}
        return r;
    }
    i = n / 2;
    return (recfact(start, i) * recfact(start + i, n - i))%mod;
}
ll factorial(ll n) { return recfact(1, n); }

int main()
{
	std::ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll res = 1;
	for (ll i = 2; i < n+1; ++i)
	{
		res*=i;
		res %=mod;
	}
	// ll res = factorial(n);
	res += mod-modpow(2,n-1,mod);
	res %=mod;
	cout << res << endl;
	return 0;
}
