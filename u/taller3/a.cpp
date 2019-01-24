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
	
	// cin.ignore(); must be there when using getline(cin, s)
	long long x=1<<16;
	std::vector<int> v(x,0);
	std::vector<int> pri;
	for (int i = 2; i < x; ++i)
	{
		if(v[i]>0){
			continue;
		}else{
			pri.push_back(i);
			for(long long a=i*i;a<x;a+=i){
				if (v[a] == 0){
					v[a] = i;
				}
			}
		}
	}
	long long n;
	while(cin>>n)
	{
		long long k=n;
		long long total=0;
		std::vector<int> prims;
		for (long long i = 0; pri[i]*pri[i] < n; ++i)
		{
			//printf("%lld\n", i);
			
			if(!(n%pri[i])){
				total+=(n/pri[i]);
				for (unsigned j = 0; j < prims.size(); ++j){
					total-=((n/(pri[i]*prims[j])));
				}
				prims.push_back(pri[i]);
			
			}
		}
		cout << total << '\t' << k << endl;
		/*
		long long total=0;
		long long x=n;
		std::vector<int> prims;
		while(x>1&&v[x]!=0){
			prims.push_back(v[x]);
			total+=(n/v[x]-2);
			for (unsigned i = 0; i < prims.size(); ++i)
			{
				total-=(n/(v[x]*prims[i]))-2;
			}
			int k=v[x];
			while(!(x%k)){
				x/=k;
				printf("%lld\t%d\n",x,v[x] );	
			}
		}
		cout << total << endl;*/
		
	}
	return 0;
}
