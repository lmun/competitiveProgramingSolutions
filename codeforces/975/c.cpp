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
	int n,q;
	cin>>n>>q;
	std::vector<ll> vn(n+1,0);
	std::vector<ll> acc(n+1,0);
	for (int i = 0; i < n; ++i){
		cin >> vn[i];
	}
	vn[n]=3000000000;
	acc[0]=vn[0];
	for (int i = 1; i < n+1; ++i)
	{
		acc[i]=acc[i-1]+vn[i];
	}/*
	for (int i = 0; i < n+1; ++i)
	{
		cout << acc[i]<< ' ';
	}
	cout << endl;*/
	ll ahora;
	ll flechas=0;
	for (int i = 0; i < q; ++i)
	{
		cin >> ahora;
		flechas+=ahora;
		ll a=0,b=n;
		while(a<b){
			ll mid=(a+b)/2;
			if(acc[mid]<=flechas){
				a=mid+1;
			}else{
				b=mid;
			}
		}
		cout << (b==n?n:n-b)<< endl;
		if(b==n){
			flechas=0;
		}
	}
	// cin.ignore(); must be there when using getline(cin, s)
	
	return 0;
}
