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
	int T, a, b;
	cin >> a >> b >> T;
	int g=gcd(a,b);
	ll h,l;
	//long long x=31623;
	std::vector<int> divis;
	std::vector<int> dipi;
	long long x=31624;
	std::vector<int> criba(x,0);
	//std::vector<int> pri;
	for (int i = 2; i < x; ++i){
		if(criba[i]==0){
	//		pri.push_back(i);
			criba[i]=i;
			for(long long a=i*i;a<x;a+=i){
				if (criba[a] == 0){
					criba[a] = i;
				}
			}
		}
	}
	int nu=g;
	for (int i = 2; i < x && nu >1; ++i)
	{
		if(criba[i]==i){
			while(nu%i==0){
				dipi.push_back(i);
				nu/=i;
			}
		}
	}
	if(dipi.size()==0){
		dipi.push_back(g);
	}
	for (ll i = ((1<<dipi.size())-1); i >0; --i)
	{
		//cout << i << " ";
		ll plm=1;
		ll pla=i;
		ll plc=0;
		for (unsigned j = 0; j < dipi.size(); ++j)
		{
			if((pla>>j)&1){
				plc++;
				plm*=dipi[j];
			}
		}
		divis.push_back(plm);
	}
	sort(divis.begin(), divis.end());
	
	
	while(T--)
	{
		cin >> l >> h;
		//h=T+l;
		int hi=divis.size()-1;
		int lo=0;
		while(hi>lo){
			int mid=(hi+lo+1)/2;
			if(divis[mid]>h){
				hi=mid-1;
			}else{
				lo=mid;
			}
		}
		//printf("%d\t%d\n",h,divis[lo] );
		if(divis[lo]<l){
			cout << -1 << endl;
			//cout << divis[lo] << endl;
		}else{
			if(divis[lo]>h){
				if(l==1){
					cout << 1 << endl;
					//cout << divis[lo] << endl;
				}else{
					cout << -1 << endl;
					//cout << divis[lo] << endl;
				}
			}else{
				cout << divis[lo] << endl;
			}
		}
	}
	return 0;
}
