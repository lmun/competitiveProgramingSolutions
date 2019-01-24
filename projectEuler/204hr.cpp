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
vll	pri;
ll n,k,npr,res;
void hamming(ll x, ll a){
	if(x<=n){
		res++;
		for (int i = a; i < npr; ++i)
		{
			hamming(x*pri[i],i);
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	
	cin >> n >> k;
	vll criba(n+1,0);
	npr=0;
	res=0;
	for (ll i = 2; i <= k; ++i)
	{
		if(criba[i]==0){
			npr++;
			pri.push_back(i);
			for(ll j=i*i;j<=n;j+=i){
				criba[j]=i;
			}
		}
	}
	hamming(1,0);
	cout << res << endl;
	return 0;
}
