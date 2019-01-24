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

class Dinic {
    struct edge {
        int to, rev;
        ll f, cap;
    };
 
    vector<vector<edge>> g;
    vector<ll> dist;
    vector<int> q, work;
    int n, sink;
 
    bool bfs(int start, int finish) {
        dist.assign(n, -1);
        dist[start] = 0;
        int head = 0, tail = 0;
        q[tail++] = start;
        while (head < tail) {
            int u = q[head++];
            for (const edge &e : g[u]) {
                int v = e.to;
                if (dist[v] == -1 and e.f < e.cap) {
                    dist[v] = dist[u] + 1;
                    q[tail++] = v;
                }
            }
        }
        return dist[finish] != -1;
    }
 
    ll dfs(int u, ll f) {
        if (u == sink)
            return f;
        for (int &i = work[u]; i < (int)g[u].size(); ++i) {
            edge &e = g[u][i];
            int v = e.to;
            if (e.cap <= e.f or dist[v] != dist[u] + 1)
                continue;
            ll df = dfs(v, min(f, e.cap - e.f));
            if (df > 0) {
                e.f += df;
                g[v][e.rev].f -= df;
                return df;
            }
        }
        return 0;
    }
 
public:
    Dinic(int n) {
        this->n = n;
        g.resize(n);
        dist.resize(n);
        q.resize(n);
    }
 
    void add_edge(int u, int v, ll cap) {
        edge a = {v, (int)g[v].size(), 0, cap};
        edge b = {u, (int)g[u].size(), 0, 0}; //Poner cap en vez de 0 si la arista es bidireccional
        g[u].push_back(a);
        g[v].push_back(b);
    }
 
    ll max_flow(int source, int dest) {
        sink = dest;
        ll ans = 0;
        while (bfs(source, dest)) {
            work.assign(n, 0);
            while (ll delta = dfs(source, LLONG_MAX))
                ans += delta;
        }
        return ans;
    }
};


int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t --> 0){
		int a, b, c;
		cin >> a >> b >> c;
		int num = 1;
		int nodoInicial = 0;
		int in[a][b];
		int out[a][b];
		int banco[a][b];
		for (int i = 0; i < a; ++i){
			for (int j = 0; j < b; ++j){
				in[i][j] = num++;
				out[i][j] = num++;
				banco[i][j] = 0;
			}
		}
		
		int nodoFinal = num++;
		Dinic din(num);
		for (int i = 0; i < c; ++i){
			int x, y;
			cin >> x >> y;
			x--, y--;
			banco[x][y] = 1;
			din.add_edge(nodoInicial, in[x][y], 1);
		}
		for (int i = 0; i < a; ++i){
			for (int j = 0; j < b; ++j){
				din.add_edge(in[i][j], out[i][j], 1);
			}
		}
		for (int i = 0; i < a; ++i){
			din.add_edge(out[i][0], nodoFinal, 1);
			din.add_edge(out[i][b-1], nodoFinal, 1);
		}
		for (int i = 1; i < b-1; ++i){
			din.add_edge(out[0][i], nodoFinal, 1);
			din.add_edge(out[a-1][i], nodoFinal, 1);
		}
		for (int i = 1; i < a-1; ++i){
			for (int j = 1; j < b-1; ++j){
				din.add_edge(out[i][j], in[i+1][j], !banco[i][j] || !banco[i+1][j]);
				din.add_edge(out[i][j], in[i-1][j], !banco[i][j] || !banco[i-1][j]);
				din.add_edge(out[i][j], in[i][j+1], !banco[i][j] || !banco[i][j+1]);
				din.add_edge(out[i][j], in[i][j-1], !banco[i][j] || !banco[i][j-1]);
			}
		}
		cout << ((din.max_flow(nodoInicial,nodoFinal)==c)?"possible":"not possible") << endl;

	}
	
	
	return 0;
}
