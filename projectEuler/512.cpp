#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
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
vi tot;
vll prim;
ll m;
ll modpow(ll base, ll exp, ll m) {

   ll result = 1;

   while (exp > 0) {
      if ((exp & 1) > 0) result = (result * base) % m;
      exp >>= 1;
      base = (base * base) % m;
   }

   return result;

 }

vll getPrimes(ll m){
	vi cri(m,0);
	prim.resize(0);
	for (ll i = 3; i < m; i+=2) {
		if (cri[i] == 0) {
			cri[i] = i;
			for (ll j = i * i; j < m; j+=i) {
				cri[j] = i;
			}
			prim.push_back(i);
		}
	}
	return prim;
}

void auxi(ll a,ll b,ll c, ll d) {
	if (a > m) {
		return;
	}
	tot[a] = (a/d)*c;
	auxi(a*prim[b], b, c, d);
	for (int i = b+1; i < prim.size(); ++i)
	{
		if (a*prim[i]>=m)
		{
			break;
		}
		auxi(a*prim[i], i, c*(prim[i]-1), d*prim[i]);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	m = modpow(10,8,inf);
	m*=5;
	m+=5;
	ll ocho = modpow(10, 8, inf);
	ocho*=5;
	tot.resize(m, 0);
	getPrimes(m);
	cout << prim.size() << endl;
	for (ll i = 0; i < prim.size(); ++i)
	{
		ll p = prim[i];
		auxi(p, i, p-1, p);
	}
	ll res = 1;
	for (ll i = 3; i < m; i++)
	{
		// ll kk = modpow(i,i,i+1);
		// ll pp = modpow(i,i,inf);
		// cout << i << '='<<kk<< '-' << ((pp-1)/(i-1)) % (i+1)  << 'o' << pp<< endl;
		// cout << i << ' ' << tot[i]*(i%2) << endl;
		if(i%2==0){
			if (i==ocho)
			{
				cout << i << ',' << res << endl;
			}
		continue;	
		}
		res += tot[i];
	}
	return 0;
}
