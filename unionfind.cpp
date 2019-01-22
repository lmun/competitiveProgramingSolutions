#include<bits/stdc++.h>

using namespace std;

/*
IMPORTANTE: el ejemplo presente es para el caso en que se tengan varias preguntas
            del tipo ¿Nodo u y nodo v estan en la misma componente conexa?

IMPORTANTE: en el caso de Minimum Spanning Tree, se debe ordenar las aristas segun peso
            de menor a mayor, (para 3 tupla: pair<int, pair<int, int> >) y luego insertar 
            las aristas en un grafo vacio, verificando previamente que no se encuentren en la
            misma componente conexa.
*/              

struct UnionFind {
  vector<int> p, r;

  // creacion de estructura.
  UnionFind(int n) {
    r.assign(n+1, 0);
    p.assign(n+1, 0);

    for(int i=1; i<=n; i++) p[i] = i;
  }

  // Devuelve representante del conjunto al que pertenece nodo i.
  int findSet(int i) {
    return (p[i] == i) ? i : (p[i] = findSet(p[i]));
  }

  // Determina si dos nodos pertenecen al mismo conjunto.
  bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
  }

  // Une los conjunto de dos nodos.
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);

      if (r[x] > r[y]) p[y] = x;
      else {
        p[x] = y;
        if (r[x] == r[y]) r[y]++;
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // Variable n es cantidad de nodos.
  // Variable m es cantidad de aristas.
  int n, m; cin >> n >> m;

  UnionFind G(n);

  // Arma el grafo en la estructura UnionFind.
  for(int i=0; i<m; i++) {
    char c;
    int u, v;
     cin >> c >> u >> v;
    if(c == '?'){
      cout << (G.isSameSet(u, v) ? "yes" : "no") << endl;
    }else{
      G.unionSet(u, v);
    }
  }
  return 0;
}
