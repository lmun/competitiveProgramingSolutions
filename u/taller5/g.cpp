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
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	int l,u,r;
	int mod=10000;
	int contador=1;
	while(cin>>l>>u>>r){
	// cin.ignore(); must be there when using getline(cin, s)
		if(l==0&&r==0&&u==0){
			break;
		}
		if(l==u){
				printf("Case %d: 0\n", contador++);
			continue;
		}
		std::vector<int> v(r);
		for (int i = 0; i < r; ++i)
		{
			cin >> v[i];
		}
		bool listo=false;
		int res=0;
		std::vector<int> vec(10000,0);
		std::vector<int> visi(10000,0);
		queue<int> q;
		visi[l]=1;
		for (int i = 0; i < r; ++i){
			int pos=(l+v[i])%mod;
			vec[pos]=1;
			q.push(pos);

		}
		while(!q.empty() && !listo){
			int y = q.front();
			q.pop();
			if(visi[y]){
				continue;
			}
			//cout << y << endl;
			visi[y]=1;
			if(u==y){
				listo=true;
				res=vec[y];
				break;
			}
			for (int i = 0; i < r; ++i){
				int pos=(y+v[i])%mod;
				//cout << vec[pos] << '\t'<< pos<< endl;
				if(vec[pos]==0){
					vec[pos]=vec[y]+1;
					q.push(pos);
				}
				
			}
		}
		if(listo){
			printf("Case %d: %d\n", contador++,res);
		}else{
			printf("Case %d: Permanently Locked\n", contador++);
		}

	}
	return 0;
}
