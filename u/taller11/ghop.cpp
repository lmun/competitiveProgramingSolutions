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
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;

class Hopcroft {
    vvi g;
    vector<int> U, dist;
    int inf = 1e9;
 
 
    bool bfs() {
        queue<int> q;
        for (int u : U) if (match[u] == nil) {
            dist[u] = 0;
            q.push(u);
        } else dist[u] = inf;
        dist[nil] = inf;
        while (not q.empty()) {
            int u = q.front(); q.pop();
            if (u != nil) for (int v : g[u]) if (dist[match[v]] == inf) {
                dist[match[v]] = dist[u] + 1;
                q.push(match[v]);
            }
        }
        return (dist[nil] != inf);
    }
 
 
    bool dfs(int u) {
        if (u == nil)
            return true;
        for (int v : g[u]) if (dist[match[v]] == dist[u]+1 and dfs(match[v])) {
            match[v] = u;
            match[u] = v;
            return true;
        }
        dist[u] = inf;
        return false;
    }
 
public:
    vector<int> match;
    int nil, isPerfect, matchSize = 0;
 
    // gg is a bidirectional vvi, UU has the nodes in the left partition
    Hopcroft(vvi& gg, vector<int>& UU) {
        g = gg; U = UU; nil = g.size();
        match.assign(g.size()+1, nil);
        dist.assign(g.size()+1, inf);
        while (bfs()) for (int u : U) if (match[u] == nil and dfs(u))
            ++matchSize;
        isPerfect = (matchSize == (int)U.size() and g.size() == U.size()*2);
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    int n, m, p;
    cin >> n >> m >> p;
    vvi adjlist(n+m+2, vi());
    vi cows(n);
    for (int i = 0; i < n; ++i){
        cows[i]=i+1;
    }
    while(p--){
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(b+n);
    }
    Hopcroft h(adjlist, cows);
    cout << h.matchSize << endl;
    
    return 0;
}
