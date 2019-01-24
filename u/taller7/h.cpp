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
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;
typedef vector<vll> graph;


int main()
{
	std::ios::sync_with_stdio(false);
	int t,n,m;
	cin>>t;
	while(t--){
		cin >> n >> m;
		graph G(n,vll(n));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				G[i][j]=inf;
			}
		}
		ll a,b,c;
		vector<pair<ll,pll> > e;
		vll mind(n,inf);
		mind[0]=0;

		while(m--){
			cin >> a >> b >> c;
			e.push_back(mp(c,mp(a,b)));
		}
		int wa=n;
		while(wa--){
			for(pair<ll,pll> xx :e){
				//cout << xx.f<< endl;
				mind[xx.s.s]=min(mind[xx.s.s],mind[xx.s.f]+xx.f);
			}
		}
		bool posi=false;
		for(pair<ll,pll> xx :e){
				//cout << xx.f<< endl;
				if(mind[xx.s.s]>mind[xx.s.f]+xx.f){
					posi=true;
				}
		}
		cout << (posi?"possible":"not possible") << endl;
	}
	
	return 0;
}
