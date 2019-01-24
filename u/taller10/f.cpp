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
static int m = 40001;
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int a,b,c;
	while(t--){
		int res=-1;
		cin >> a >> b >> c;
		queue<pii> q;
		q.push(mp(0,0));
		set<int> visi;
		while(!q.empty()){
			pii n=q.front();
			q.pop();
			if(visi.count(n.f)){
				continue;
			}
			visi.insert(n.f);
			//cout << n.f << endl;
			int aa = n.f%m;
			int bb = n.f/m;
			if(aa==c || bb==c){
				res=n.s;
				break;
			}
			q.push(mp(b*m+aa,n.s+1)); //lleno bb
			q.push(mp(bb*m,n.s+1));// vacio aa
			q.push(mp(bb*m+a,n.s+1)); // lleno a
			q.push(mp(aa,n.s+1));// vacio b
			if(aa+bb > a){
				q.push(mp((aa+bb-a)*m+a,n.s+1));
			}else{
				q.push(mp(aa+bb,n.s+1));
			}
			if(aa+bb > b){
				q.push(mp(b*m+(aa+bb-b),n.s+1));
			}else{
				q.push(mp((aa+bb)*m,n.s+1));
			}
		}
		cout << res << endl;
	}
	// cin.ignore(); must be there when using getline(cin, s)
	
	return 0;
}
