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
int main()
{
	std::ios::sync_with_stdio(false);
	std::vector<ll> v(14,0);
	std::vector<ll> m(14,0);
	for (int i = 0; i < 14; ++i){
		cin >> v[i];
	}
	ll res=0;
	for (int i = 0; i < 14; ++i){
		std::vector<ll> pp(14,0);
		ll maxpos=0;	
		//ll este=v[i];
		ll reparto=v[i]/14;
		ll sobran=v[i]%14;
		if(reparto%2==0){
			maxpos+=reparto;
		}
		for (int j = 1; j < 14; ++j){
			
				ll quedocon=v[(i+j)%14]+reparto+(sobran>=j);
				
				if(quedocon%2==0){
					maxpos+=quedocon;
				}
				pp[j]=quedocon;
		}/*
		for (int t = 0; t < 14; ++t)
		{
			cout << pp[t] << ' ';
		}
		cout << '\t'<< i<< ' '<< maxpos<< endl;*/
		m[i]=maxpos;
		res=max(res,maxpos);
	}/*
	for (int i = 0; i < 14; ++i)
	{
		cout << m[i] << ' ';
	}*/
	cout << res << endl;
	
	return 0;
}
