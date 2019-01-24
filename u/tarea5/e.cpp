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
int n,m,k;
int main()
{
	std::ios::sync_with_stdio(false);
	
	cin >> n >> m >> k;
	std::vector<int> cap(k);
	std::vector<int> tam(k);
	std::vector<std::vector<int> > gr(n+1,std::vector<int> ());
	for (int i = 0; i < k; ++i)
	{
		cin >> cap[i];
	}
	for (int i = 0; i < m; ++i)
	{
		int o,d;
		cin >> o >> d;
		gr[o].push_back(d);
		gr[d].push_back(o);
	}

	
	std::vector<int> visi(n+1,0);
	int total=0;
	int maxtam=-1;
	int maxind=-1;
	for (int i = 0; i < k; ++i){
		queue<int> q;
		q.push(cap[i]);
		int count=0;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			if(visi[u]==0){
				visi[u]++;
				count++;
				for(int k : gr[u]){
					q.push(k);
				}
			}
		}
		tam[i]=count;
		total+=count;
		if(count > maxtam){
			maxtam=count;
			maxind=i;
		}
	}
	tam[maxind]+=n-total;
	int res=0;
	for (int i = 0; i < k; ++i)
	{
		res+=(tam[i]*(tam[i]-1))/2;
	}

	cout << res-m << endl;
	// cin.ignore(); must be there when using getline(cin, s)
	
	return 0;
}
