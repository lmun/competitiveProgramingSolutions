#include <bits/stdc++.h>
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
	// Inicializar variables!!
	// N cantidad de nodos, M cantidad de aristas
	int t;
	cin >> t;
	while(t--){
		int N,M; cin >> N >> M;
		G.clear(); G.resize(N);
		std::vector<int> lle(N,0);
		std::vector<int> res(N,0);
		tarjan_time = 0;
		disc.assign(N,-1);
		low.assign(N,-1);
		while(!S.empty()) S.pop();
		inStack.assign(N,false);
		SCC.clear();

		// Recibir aristas
		for(int _ = 0; _ < M; ++_)
		{
			int u,v; cin >> u >> v;
			u--,v--;
			G[u].push_back(v);
		}

		// Si el nodo no esta visitado, utilizar tarjan
		for(int u = 0; u < N; ++u)
			if(disc[u] == -1)
				tarjan(u);

		int k = 0;
		for(vector<int> &C : SCC){
			// cout << "La " << k++ << "-esima componente conexa es: ";
			k++;
			for(int u : C) lle[u]=k;
			// cout << '\n';
		}
		std::vector<int> comp(k,1);
		for (int i = 0;i < N ; i++){
			vector<int> C=G[i];
			for(int j: C){
				//cout << i << ' ' << j << endl;
				if(lle[i]!=lle[j]){
					comp[lle[j]]=0;
				}
			}
		}
		int resultado=0;
		for (int i = 0; i < k; ++i)
		{
			resultado+=comp[i];
		}
		cout << resultado << endl;
	}

	return 0;
}