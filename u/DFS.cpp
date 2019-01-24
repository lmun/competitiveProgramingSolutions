//DFS - recorrer grafo

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	/*
	n = cantidad de vertices
	m = cantidad de aristas
	p = nodo en que parte el recorrido del grafo
	*/
	int n, m, p; cin >> n >> m >> p;
	vector<vector<int> > G(n, vector<int>());

	for(int i=0; i<m; i++) {
		int u, v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u); //eliminar para caso grafo dirigido
	}

	stack<int> st;
	vector<int> reg(n, 0); //se registran los nodos recorridos
	st.push(p);

	while(!st.empty()) {
		int u = st.top();
		st.pop();

		reg[u] = 1;
		for(int v : G[u]) {
			if(reg[v])
				continue;

			st.push(v);
		}
	}

	//muestra los nodos recorridos con 1 o 0
	for(int i=0; i<n; i++) cout << i << " : " << reg[i] << "\n";

	return 0;
}