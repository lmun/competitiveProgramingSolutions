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
	int n,a,b;
	cin>>n;
	// cin.ignore(); must be there when using getline(cin, s)
	std::vector<pair<int,int> > v(n);
	std::vector<std::vector<int> > x(1001,std::vector<int> ());
	std::vector<std::vector<int> > y(1001,std::vector<int> ());
	std::vector<int> visi(n,0);
	for (int i = 0; i < n; ++i){
		cin >> a >> b;
		x[a].push_back(i);
		y[b].push_back(i);
		v[i]=mp(a,b);
	}
	int total=0;
	for (int i = 0; i < n; ++i){
		if(visi[i]==0){
			total++;
			queue<int> q;
			q.push(i);
			while(!q.empty()){
				int u=q.front();
				q.pop();
				if(visi[u]==0){
					//printf("%d\t%d\n", u,i);
					visi[u]++;
				//	printf("-%d\t%d\n", v[u].f,v[u].s);
					
					for(int k: x[v[u].f]){
						
						if(visi[k]==0){
							q.push(k);
						}
					}
					for(int k: y[v[u].s]){
						if(visi[k]==0){
							q.push(k);
						}
					}
				}
			}
		}

	}
	cout << total-1 << endl;
	return 0;
}
