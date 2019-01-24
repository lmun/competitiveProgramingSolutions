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
std::vector<int> divisor(ll a,std::vector<int> &p){
	std::vector<int> res;

	ll u=p[a];
	while(u>1){
		res.push_back(p[a]);
		while(a%u==0){
			a/=u;
		}
		u=p[a];
	}
	return res;
}

int main()
{
	long long x=100001;
	std::vector<int> p(x,0);
	std::vector<int> pri;
	for (int i = 2; i < x; ++i){
		if(p[i]==0){
			pri.push_back(i);
			p[i]=i;
			for(long long a=i+i;a<x;a+=i){
				if (p[a] == 0){
					p[a] = i;
				}
			}
		}
	}

	std::ios::sync_with_stdio(false);
	ll T;
	cin>>T;
	// cin.ignore(); must be there when using getline(cin, s)
	std::vector<ll> v(T);
	std::vector<ll> res(T); //largo de la cadena mas larga con ese divisor
	std::vector<ll> cou(x,0);//posicion de la ultima ocurrencia del primo divisor

	for (ll i = 0; i < T; ++i){
		cin >> v[i];
	}
	std::vector<int> divi;
	for (int i = 0; i < T; ++i)
	{
		ll a = v[i]; //numero
		divi=divisor(a,p);
		ll mal=0;
		for (unsigned k = 0; k < divi.size(); ++k)
		{
			mal=max(mal,cou[divi[k]]);
		}
		mal++;
		for (unsigned k = 0; k < divi.size(); ++k)
		{
			cou[divi[k]]=mal;
		}
	}
	ll maxi=0;
	for (unsigned i = 0; i < cou.size(); ++i)
	{
		maxi=max(maxi,cou[i]);
	}
	/*
	res[0]=1;
	ll longest=1;
	for (ll i = 1; i < T; ++i)
	{
		ll pos=1;
		for (ll k = i-1; k >=0; k--)
		{
			
			if(gcd(v[i],v[k])!=1){
				pos=max(pos,res[k]+1);
				if(pos>longest){
					longest=pos;
					break;
				}
			}
			
		}
		res[i]=pos;
	}
	ll maxi=res[0];
	for (int i = 1; i < T; ++i)
	{
		maxi=max(maxi,res[i]);
	
	}*/
	if(maxi == 0 && T > 0){
		maxi=1;
	}
	cout << maxi << endl;
	return 0;
}
