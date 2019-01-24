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

typedef vector<vector<int>> graph;
graph G;
int tarjan_time;
vector<int> disc,low;
stack<int> S;
vector<bool> inStack;
vector<vector<int>> SCC;

void tarjan(int u){
	disc[u] = low[u] = tarjan_time++;
	S.push(u);
	inStack[u] = true;

	for(int v : G[u]){
		if(disc[v] == -1){
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}

		else if(inStack[v]) low[u] = min(low[u],disc[v]);
	}

	if(low[u] == disc[u]){
		SCC.emplace_back();
		while(S.top() != u){
			int v = S.top(); S.pop();
			SCC.back().push_back(v);
			inStack[v] = false;
		}

		S.pop();
		SCC.back().push_back(u);
		inStack[u] = false;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	int N,M;
	cin>>N;
	std::vector<int> cos(N);
	for (int i = 0; i < N; ++i){
		cin >> cos[i];
	}
	cin >> M;
	G.clear(); G.resize(N);
	tarjan_time = 0;
	disc.assign(N,-1);
	low.assign(N,-1);
	while(!S.empty()) S.pop();
	inStack.assign(N,false);
	SCC.clear();
	for(int _ = 0; _ < M; ++_){
		int u,v; cin >> u >> v;
		u--,v--;
		G[u].push_back(v);
	}
	for(int u = 0; u < N; ++u)
		if(disc[u] == -1)
			tarjan(u);

	ll tot=1;
	ll minco=0;
	for(vector<int> &C : SCC){
		/*
		cout << "La " << k++ << "-esima componente conexa es: ";
		for(int u : C) cout << u << ' ';
		cout << '\n';*/
		ll emin=inf,mico;
		for(int u : C){
			if (cos[u] < emin){
				emin=cos[u];
				mico=1;
			}else if(cos[u] == emin){
				mico++;
			}
		}
		minco += emin;
		tot*=mico;
		tot%=mod;
	}
	cout << minco << ' ' << tot << endl;
	
	return 0;
}
