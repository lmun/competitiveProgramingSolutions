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
#define pipii pair<int, pii >
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

int maxdeci(int x, int y, vi &po,vector<vector< pii > > &mat){
	if(x==y){
		return 1;
	}
	for (pii u : mat[x]){
		if(po[u.f]>0){
			continue;
		}
		po[u.f]++;
		int a=maxdeci(u.f,y,po,mat);
		if(a>0){
			return max(a,u.s);
		}
	}
	return 0;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int c,s,q,a,b,d;
	int test=0;

	while(cin >> c >> s >> q){
		test++;
		if(c==0 && s==0 && q==0){
			break;
		}
		if(test>1){
			cout << endl;
		}
		vector<pipii> vec(s);
		for (int i = 0; i < s; ++i){
			cin >> a >> b >> d;
			vec[i]=mp(d,mp(a-1,b-1));
		}
		UnionFind G(c);
		//vvi mat(c);
		vector<vector< pii > > mat(c,vector< pii > ());
		sort(vec.begin(), vec.end());
		for (int i = 0; i < s; ++i)
		{
			if(!G.isSameSet(vec[i].s.f ,vec[i].s.s)){
				G.unionSet(vec[i].s.f ,vec[i].s.s);
				mat[vec[i].s.f].push_back(mp(vec[i].s.s,vec[i].f));
				mat[vec[i].s.s].push_back(mp(vec[i].s.f,vec[i].f));
				
			}
		}
		cout << "Case #" << test << endl;
		for (int i = 0; i < q; ++i)
		{
			
			cin >> a >> b;
			vi po(c,0);
			int res=maxdeci(a-1,b-1,po,mat);
			if(res>0){
				cout << res << endl;
			}else{
				cout << "no path\n";
			}
		}
	}
	return 0;
}
