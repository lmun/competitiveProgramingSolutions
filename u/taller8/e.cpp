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
int main()
{
	std::ios::sync_with_stdio(false);
	int n,m;
	cin>>n >> m;
	vi visi(30000,0);
	queue<pii> q;
	q.push(mp(n,0));
	visi[n] = 1;
	int tot=9999999;
	while(!q.empty()){
		pii pu = q.front();
		q.pop();
		if(pu.f == m){
			tot = min(tot, pu.s);
		}
		if(pu.f*2 == m || pu.f-1 == m){
			tot = min(tot, pu.s+1);
		}
		if(pu.f < m && visi[pu.f*2] == 0){
			q.push(mp(pu.f*2,pu.s+1));
			visi[pu.f*2] = 1;
		}
		if(pu.f > 0 && visi[pu.f-1] == 0){
			q.push(mp(pu.f-1,pu.s+1));
			visi[pu.f-1] = 1;
		}
		
	}
	cout << tot << endl;
	// cin.ignore(); must be there when using getline(cin, s)
	
	return 0;
}
