#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> graph;
graph G;
int tarjan_time;
vector<int> disc, low;
stack<int> S;
vector<bool> inStack;
vector<vector<int>> SCC;

void tarjan(int u) {
	disc[u] = low[u] = tarjan_time++;
	S.push(u);
	inStack[u] = true;

	for (int v : G[u]) {
		if (disc[v] == -1) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}

		else if (inStack[v]) low[u] = min(low[u], disc[v]);
	}

	if (low[u] == disc[u]) {
		SCC.emplace_back();
		while (S.top() != u) {
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
	int N, M;
	while (cin >> N >> M) {
		if (N == 0 && M == 0) {
			break;
		}
		G.clear(); G.resize(N);
		tarjan_time = 0;
		disc.assign(N, -1);
		low.assign(N, -1);
		while (!S.empty()) S.pop();
		inStack.assign(N, false);
		SCC.clear();

		// Recibir aristas
		for (int _ = 0; _ < M; ++_) {
			int u, v, x; cin >> u >> v >> x;
			u--, v--;
			G[u].push_back(v);
			if (x == 2) {
				G[v].push_back(u);
			}

		}

		// Si el nodo no esta visitado, utilizar tarjan
		for (int u = 0; u < N; ++u)
			if (disc[u] == -1)
				tarjan(u);
		cout << (((int)SCC.size()) == 1) << endl;
	}
	return 0;
}
