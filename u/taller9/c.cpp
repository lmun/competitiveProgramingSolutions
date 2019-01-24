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

void dfs(int a, vi &vis, vvi &mat){
	for (int k : mat[a]){
		if(vis[k] == 0){
			vis[k]++;
			dfs(k, vis, mat);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	int n,a,b, c;
	string s;
	int t =1;
	while(cin>>n){
		//printf("%d n es \n",n );
		if(n==-1){
			break;
		}
		vvi mat(n, vi(0));
		vi ene(n,0);
		vi visi(n,0);
		vll camin(n,-inf);
		camin[0] = 100;
		//camin[n-1] = 0;
		for (int i = 0; i < n;++i){
			cin >> a >> b;
			ene[i] = a;
			for (int j = 0; j < b; ++j){
				cin >> c;
				mat[i].push_back(c-1);
				//printf("%d\t%d\n", i+1, c);
			}
		}
		bool wina = false;
		visi[0]=1;
		dfs(0,visi, mat);
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				if(camin[j] < 0){
					continue;
				}
				for(int k: mat[j]){
					if(camin[j]+ene[k]>0){
						camin[k] = max(camin[k],camin[j]+ene[k]);	
					}
					
					
				}
			}
		}
		for (int j = 0; j < n; ++j){
			for(int k: mat[j]){
				if(camin[j] >=0 && ene[k] >= 0 &&camin[k] < camin[j] + ene[k]){
				//	cout << j << '\t' << k<<  '\t'<< n << endl;
			//		cout << camin[k] << '\t' << camin[j]+ene[k]<< endl;
					wina = visi[n-1];
				}
			}
		}
		
		//cout << camin[n-1]  << '\t'<< wina << endl;
		wina = wina || camin[n-1] > 0;
		// wina=false;
		//cout << (wina?"winnable":"hopeless") << t <<  endl;
		cout << (wina?"winnable":"hopeless") <<  endl;
		t++;
	}
	// cin.ignore(); must be there when using getline(cin, s)
	
	return 0;
}
