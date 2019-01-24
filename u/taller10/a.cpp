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
typedef vector<vector<int>> graph;
graph G;
int tarjan_time;
vector<int> disc,low;
stack<int> S;
vector<bool> inStack;
vector<vector<int>> SCC;

void tarjan(int u)
{
	disc[u] = low[u] = tarjan_time++;
	S.push(u);
	inStack[u] = true;

	for(int v : G[u])
	{
		if(disc[v] == -1)
		{
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}

		else if(inStack[v]) low[u] = min(low[u],disc[v]);
	}

	if(low[u] == disc[u])
	{
		SCC.emplace_back();
		while(S.top() != u)
		{
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
	int n,m;
	int t=1;
	while(cin>>n>>m){
		if(n==0 && m==0){
			break;
		}
		G.clear(); G.resize(n);
		tarjan_time = 0;
		disc.assign(n,-1);
		low.assign(n,-1);
		while(!S.empty()) S.pop();
		inStack.assign(n,false);
		SCC.clear();
		int j=0,ia=0,ib=0;
		map<string, int> mymap;
		std::vector<string> v(n);
		string a,b;
		for (int i = 0; i < m; ++i){
			cin >> a >> b;
			if(mymap.count(a)==0){
				ia=j;
				v[j]=a;
				mymap[a]=j++;
			}else{
				ia=mymap[a];
			}
			if(mymap.count(b)==0){
				ib=j;
				v[j]=b;
				mymap[b]=j++;
			}else{
				ib=mymap[b];
			}
			G[ia].push_back(ib);
		}
		for(int u = 0; u < n; ++u)
			if(disc[u] == -1)
				tarjan(u);

		// int k = 1;
		if(t>1)cout << endl;
		cout << "Calling circles for data set "<< t++ <<":"<< endl;
		//for(vector<int> &C : SCC){
		for (int i = (int)SCC.size()-1; i >=0 ; i--){
			vector<int> C=SCC[i];
			// cout << "La " << k++ << "-esima componente conexa es: ";
			// for(int u : C) cout << v[u] << ' ';
			for (int i = 0; i < (int)C.size(); ++i){
				cout << (i?", ":"") << v[C[i]];
			}
			cout << '\n';
		}
		
		// cout << ia<<' '<<ib << endl;
	}
	// cin.ignore(); must be there when using getline(cin, s)
	
	return 0;
}
