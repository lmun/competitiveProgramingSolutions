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
ll x = 100001;
vi cri(x, 0);
vi prims;

ll toti(ll a) {
	ll res = 1;
	while (a > 1) {
		ll divi = a;
		if (a >= x)
		{

			for (int i = 0; i < prims.size(); ++i)
			{
				if (a % prims[i] == 0)
				{
					divi = prims[i];
				}
			}
		} else {
			if(cri[a] == 0){
				divi = a;
			} else {
				divi = cri[a];
			}
		}
		//cout << divi << endl;
		a /= divi;
		ll este = divi-1;
		while (a % divi == 0) {
			a /= divi;
			este *= divi;
		}
		res *= este;
	}
	return res;
}

ll divi(ll a) {
	ll res = 1;
	while (a > 1) {
		ll divi = a;
		if (a >= x) {

			for (int i = 0; i < prims.size(); ++i)
			{
				if (a % prims[i] == 0)
				{
					divi = prims[i];
				}
			}
		} else {
			if(cri[a] == 0){
				divi = a;
			} else {
				divi = cri[a];
			}
		}
		//cout << a << 'a' << divi << endl;
		ll tot = 1;
		while (a % divi == 0) {
			tot++;
			a /= divi;
		}
		res *= tot;
	}
	return res;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	for (ll i = 2; i < x; ++i) {
		if(cri[i] == 0) {
			prims.push_back(i);
			for (ll j = i*i; j < x; j += i) {
				cri[j] = i;
			}
		}
	}
	ll n;
	while(cin >> n) {
		if (n == 0) {
			break;
		}
		// cout << toti(n)  << ' ' << divi(n) << endl;
		cout << (1+n-toti(n)-divi(n)) << endl;
		//cout << divi(n) << endl;
		//cout << toti(n) << endl;
	}
	return 0;
}
