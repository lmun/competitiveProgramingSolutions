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
std::vector<int> pri;
long long x=100021;
std::vector<int> criba(x,0);

int falta(int k){
	int h=pri.size()-1;
	int l=0;
	int mid;
	while(h>l){
		mid=(h+l)/2;
		if(pri[mid]<k){
			l=mid+1;
		}else{
			h=mid;
		}
	}
	if(pri[h]-k<0){
		printf("%d\t%d\n", pri[h],k);
	}
	return pri[h]-k;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int m,n;
	cin>>m>>n;
	// cin.ignore(); must be there when using getline(cin, s)
	std::vector<std::vector<int> > v(m,(std::vector<int> (n,0)));
	std::vector<std::vector<int> > fal(m,(std::vector<int> (n,0)));

	for (int i = 2; i < x; ++i){
		if(criba[i]==0){
			pri.push_back(i);
			criba[i]=i;
			for(long long a=i+i;a<x;a+=i){
				if (criba[a] == 0){
					criba[a] = i;
				}
			}
		}
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];
			fal[i][j]=falta(v[i][j]);
		}
	}
	

	
	ll mini=inf;
	for (int i = 0; i < m; ++i)
	{
		ll esta=0;
		for (int j = 0; j < n; ++j)
		{
			esta+=fal[i][j];
		}
		mini=min(mini,esta);
	}
	for (int i = 0; i < n; ++i)
	{
		ll esta=0;
		for (int j = 0; j < m; ++j)
		{
			esta+=fal[j][i];
		}
		mini=min(mini,esta);
	}
	cout << mini << endl;
	return 0;
}
