#include<bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
#define mp(x,y) make_pair(x,y)

using namespace std;

/*
IMPORTANTE: el ejemplo presente es para el caso en que se tengan varias preguntas
            del tipo ¿Nodo u y nodo v estan en la misma componente conexa?

IMPORTANTE: en el caso de Minimum Spanning Tree, se debe ordenar las aristas segun peso
            de menor a mayor, (para 3 tupla: pair<int, pair<int, int> >) y luego insertar 
            las aristas en un grafo vacio, verificando previamente que no se encuentren en la
            misma componente conexa.
*/              
double tot;
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
  void unionSet(int i, int j, double k) {
    if (!isSameSet(i, j)) {
      tot += k;
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
  int t;
  cin >> t;
  while(t--){
    tot = 0;
    int n; cin >> n;

    UnionFind G(n);
    std::vector<pair<double, double> > v;
    for (int i = 0; i < n; ++i)
    {
      double a, b;
      cin >> a >> b;
      // cout << a << ".-." << b << endl;
      v.push_back(mp(a, b));
    }
    // cout << v.size() << endl;
    // Arma el grafo en la estructura UnionFind.
    std::vector<pair<double, pii> > ari;
    for(int i=0; i<n; i++) {
      for (int j = 0; j < i; ++j) {
        // cout << v[i].f << 'h' << v[j].f << endl;
        double dx = v[i].f - v[j].f;
        double dy = v[i].s - v[j].s;
        double d = sqrt(dx*dx + dy*dy);
       // printf("%f\t%f\n", dx, dy);
        ari.push_back(mp(d, mp(i, j)));
      }
    }
    sort(ari.begin(), ari.end());
    for(auto paa: ari){
      // cout << ari.size() << endl << ari[0].f << endl;  
      // cout << paa.f << endl;
      // cout << paa.s.f << endl;
      // cout << paa.s.s << endl;
      G.unionSet(paa.s.f, paa.s.s, paa.f);
    }
    printf("%.2f\n", tot);
  }
  return 0;
}
