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
	int n,k;
	cin>>n;
	// cin.ignore(); must be there when using getline(cin, s)
	std::vector<int> v(n,0);
	long long x=10000001;
	std::vector<int> criba(x,0);
	std::vector<int> pri;
	for (long long i = 2; i < x; ++i){
		if(criba[i]==0){
			//cout << i << endl;
			pri.push_back(i);
			criba[i]=i;
			for(long long a=i*i;a<x;a+=i){
				if (criba[a] == 0){
					criba[a] = i;
				}
			}
		}
	}
	
	std::vector<int> counts(10000001);
	for (int i = 0; i < n; ++i)
	{
		cin >> k;
		/*
		for (unsigned j = 0; j < pri.size(); ++j)
		{
			if( k%pri[j]==0 ){
				counts[pri[j]]++;
				while(k>1 && k%pri[j]==0){
					k/=pri[j];
				}
			}
			if(k==1){
				break;
			}
			if(criba[k]==k){
				counts[k]++;
				break;
			}
		}*/
		while(k!=1){
			counts[criba[k]]++;
			int act=criba[k];
			while(k>1&&k%act==0){
				k/=act;
			}
		}
		
	}
	

	std::vector<int> acc(10000001);

	acc[0]=counts[0];
	for (int i = 1; i < 10000001; ++i)
	{
		acc[i]=acc[i-1]+counts[i];
	}

	long long m,a,b;
	cin >> m;
	while(m--){
		cin >> a >> b;
		/*
		long long total=0;
		for (unsigned i = 0; i < pri.size(); ++i)
		{
			if(pri[i]>=a && pri[i]<=b){
				total+=counts[pri[i]];
			}
			if(pri[i]>b){
				break;
			}
		}*/
		if(b>=x){
			b=x-1;
		}
		if(a>=x){
			cout << 0 << endl;
		}else{
			cout << (acc[b]-acc[a-1]) << endl;
		}
	}

	return 0;
}
