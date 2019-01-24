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

using namespace std;

int n, m, a, b, c, d, D[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};

int f(int x, int y,char G[][505]) {
	if(G[x][y] != '.')
		return x == c && y == d;
	G[x][y] = 'X';
	for(int i = 0; i < 4; i++)
		if(f(x + D[0][i], y + D[1][i],G))
			return 1;
	return 0;
}

int main() {
	char G[505][505];
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%s", G[i] + 1);
	scanf("%d%d%d%d", &a, &b, &c, &d);
	G[a][b] = '.';
	puts(f(a, b,G) ? "YES" : "NO");
	for (int i = 0; i < 10; ++i)
	{
		cout << (int)G[i][i] << '\t';
	}
}