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
int total;
int ciclos(int a,std::vector<set<int> > &v,std::vector<int> &visi,std::vector<int> &cic){
	if(visi[a]>0){
		return 0;
	}else{
		int ciclo=0;
		visi[a]++;
		for (int u : v[a]){
			if(visi[u]==0){
				ciclo=ciclo+ciclos(u,v,visi,cic);
			}else{
				ciclo+=1;
				total++;
			}
		}
		if(ciclo){
			cic[a]+=ciclo;
		}
		return ciclo;
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n,m,a,b;
	total=0;
	cin>>n>>m;
	std::vector<std::set<int> > gr(n+1,std::set<int> ());
	//std::vector<int> visi(n+1,0);
	for (int i = 0; i < m; ++i){
		cin >> a >> b;
		gr[a].insert(b);
	}
	std::vector<int> cic(n+1,0);
	for (int i = 1; i <= n; ++i){
		std::vector<int> visi(n+1,0);
		ciclos(i,gr,visi,cic);
	}
	for (int i = 1; i <= n; ++i)
	{
		printf("%d\t%d\n",i, cic[i]);
	}

/*
	bool acy=true;
	int ini,fin;
	for (int i = 1; i <= n; ++i)
	{
		queue<int> q;
		q.push(i);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			if(visi[u]!=i){
				visi[u]=i;
				for(int k : gr[u]){
					if(visi[k]!=i){
						q.push(k);
					}else{
						if(acy && k==i){
							acy=false;
							ini=u;
							fin=k;
						}else{
							if(ini!=u||fin!=k){
								printf("%d\t%d\n", u,k);
								cout << "NO\n";
								return 0;
							}
						}
					}
				}
			}
		}
	}
	cout << "yes\n";*/
	return 0;
}
