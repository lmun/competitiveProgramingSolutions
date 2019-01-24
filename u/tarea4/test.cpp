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
std::vector<int> divi(ll a,std::vector<int> &p){
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
	// cin.ignore(); must be there when using getline(cin, s)
	for (int i = 0; i < 33; ++i)
	{
		std::vector<int> v=divi(i,p);
		for (unsigned j = 0; j < v.size(); ++j)
		{
			cout << v[j] << '\t' << i;
		}
		cout << endl;
	}
	return 0;
}
