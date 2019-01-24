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
	int n,m;
	cin>>n>>m;
	std::vector<std::vector<int> > v(n+1,std::vector<int> ());
	std::vector<int> visi(n+1,0);
	for (int i = 0; i < m; ++i){
		int a,b;
		cin >>a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int total=0;

	for (int i = 1; i <= n; ++i){
		if(visi[i]>0){
			continue;
		}
		stack<int> q;
		q.push(i);
		visi[i]=i;
		bool ciclo=false;
		bool gran=false;
		while(!q.empty()){
			int k=q.top();
			q.pop();
			ciclo=false;
			
			if(v[k].size()!=2){
				gran=true;
			}
			for (int u :v[k])
			{	
				if(visi[u]==0){
					q.push(u);
					
					visi[u]=k+1;
					
				}else if(visi[u]>0&&visi[u]!=visi[k]-1&&q.empty()){
					//printf("%d\n",k );
					ciclo=true;
				}
			}

		}
		if(ciclo&&!gran){
			//printf("i %d\n",i );
			total++;
		}
	}
	cout << total << endl;
	// cin.ignore(); must be there when using getline(cin, s)
	
	return 0;
}
