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
	int n;
	long long x=1000001;
	std::vector<ll> criba(x,0);
	std::vector<ll> pri;
	for (ll i = 2; i < x; ++i){
		if(criba[i]==0){
			pri.push_back(i);
			criba[i]=i;
			for(long long a=i*i;a<x;a+=i){
				if (criba[a] == 0){
					criba[a] = i;
				}
			}
		}
	}
	cin>>n;
	while(n--){
		ll num;
		cin >> num;
    	ll minimo=num;
		for (int i = 0; i < (int)pri.size(); ++i)
		{

			while(minimo>pri[i] && minimo%pri[i]==0){
				minimo/=pri[i];
			}
		}
		cout << minimo << endl;

	}
	// cin.ignore(); must be there when using getline(cin, s)
	
	return 0;
}
