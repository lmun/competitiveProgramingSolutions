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
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define mali 1010

using namespace std;

char G[mali][mali];
int dir[2][4]={{1,0,0,-1},{0,1,-1,0}};
int main()
{
	std::ios::sync_with_stdio(false);
	int r, c, si, sj;
	//cin>>r >> c;
	scanf("%d %d", &r,&c);
	for (int i = 1; i <= r; ++i){
		scanf("%1004s",G[i]+1);
		for (int j = 1; j <= c; ++j){
			if (G[i][j]=='E'){
				si = i;
				sj = j;
			}
		}
	}
	int waa = 0, maxdist = mod;
	queue<pipii> q;
	q.emplace(0,mp(si,sj));
	G[si][sj]='T';
	int tt=4;
	while(tt--){
		q.emplace(1,mp(si+dir[0][tt],sj+dir[1][tt]));
	}
	while(!q.empty()){
		pipii este=q.front();
		int a=este.s.f, b=este.s.s;
		// printf("%c\n",G[a][b] );
		q.pop();
		// printf("%d %d %d %d\n",este.f, a, b, waa);
		if(este.f>maxdist){
			break;
		}
		if(G[a][b]=='S'){
			maxdist = este.f;
			G[a][b]='T';
		}else if(G[a][b]=='T'){
			continue;
		}else if(G[a][b]>='0' && G[a][b]<='9'){
			waa+=(int)(G[a][b]-'0');
			G[a][b]='T';
			int tt=4;
			while(tt--){
				q.emplace(este.f+1,mp(a+dir[0][tt],b+dir[1][tt]));
			}
		}else{
			continue;
		}
	}
	printf("%d\n", waa);
	return 0;
}
