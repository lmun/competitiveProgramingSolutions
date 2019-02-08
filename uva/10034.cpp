#include<bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
#define mp(x,y) make_pair(x,y)

using namespace std;

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
  int t;
  cin >> t;
  bool salto = false;
  while(t--){
    tot = 0;
    int n; cin >> n;

    UnionFind G(n);
    std::vector<pair<double, double> > v;
    for (int i = 0; i < n; ++i)
    {
      double a, b;
      cin >> a >> b;
      v.push_back(mp(a, b));
    }
    std::vector<pair<double, pii> > ari;
    for(int i=0; i<n; i++) {
      for (int j = 0; j < i; ++j) {
        double dx = v[i].f - v[j].f;
        double dy = v[i].s - v[j].s;
        double d = sqrt(dx*dx + dy*dy);
        ari.push_back(mp(d, mp(i, j)));
      }
    }
    sort(ari.begin(), ari.end());
    for(auto paa: ari){
      G.unionSet(paa.s.f, paa.s.s, paa.f);
    }
    if (salto)
    {
      printf("\n");
    }
    salto = true;
    printf("%.2f\n", tot);
  }
  return 0;
}
