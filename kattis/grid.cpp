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
#define f first
#define s second

using namespace std;
int w,h;
int main()
{
	std::ios::sync_with_stdio(false);
	int dirs[2][4]={{1,-1,0,0},{0,0,1,-1}};
	cin >> w >> h;
	std::vector<std::vector<int> > pos(w,std::vector<int> (h,-1));
	pos[0][0]=0;
	std::vector<string> v(w);
	for (int i = 0; i < w; ++i){
		cin >> v[i];
	}
	queue<pair<int,int> > st;
	st.push(mp(0,0));
	while(!st.empty()){
		pii act=st.front();
		//printf("%d %d\n",act.f,act.s );
		st.pop();
		if(act.f < 0 || act.s < 0 || act.f >= w || act.s >=h){
			continue;
		}
		int miv=v[act.f][act.s]-'0';
		for (int i = 0; i < 4; ++i){
			int x=act.f+dirs[0][i]*miv;
			int y=act.s+dirs[1][i]*miv;
			if(x >= 0 && y>=0 && x<w && y < h && pos[x][y]<0){
				pos[x][y]=pos[act.f][act.s]+1;
				st.push(mp(x,y));
			}
		}
	}
	cout << pos[w-1][h-1]<< endl;
	return 0;
}
