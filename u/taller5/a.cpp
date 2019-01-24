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
int main()
{
	std::ios::sync_with_stdio(false);
	int m,n;
	while(cin>>m>>n){
	cin.ignore();// must be there when using getline(cin, s)
	std::vector<string> v(m,"");

	for (int i = 0; i < m; ++i){
		getline(cin,v[i]);
	}
	int a,b;
	cin >> a >> b;
	char tierra=v[a][b];
	int x,y;

	set<int> nodos;
	std::vector<std::vector<int> > mat(n*m,std::vector<int> ());

	for (int i = 0; i < m*n; ++i){
		x=i/n;
		y=i%n;
		if(tierra==v[x][y]){
			//cout << "h"<< endl;
			nodos.insert(i);
			if(x > 0){
				if(v[x-1][y]==tierra){
					//mat[i][(x-1)*n+y]=1;
					mat[i].push_back((x-1)*n+y);
				}
			}
			if(x < m-1){
				if(v[x+1][y]==tierra){
					mat[i].push_back((x+1)*n+y);
				}
			}
			if(v[x][(y+n-1)%n]==tierra){
				//mat[i][(x*n)+(y+n-1)%n]=1;
				mat[i].push_back((x*n)+(y+n-1)%n);
			}
			if(v[x][(y+n+1)%n]==tierra){
				//mat[i][(x*n)+(y+n+1)%n]=1;
				mat[i].push_back((x*n)+(y+n+1)%n);
			}
		}

	
	}
	std::vector<int> visitados(n*m,0);

	queue<int> q;

	q.push(a*n+b);
	int coun=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		visitados[u]=1;
		nodos.erase(u);
		coun++;
		for(int k : mat[u]){
			if(!visitados[k]){
					q.push(k);
			}
		}
	}


	std::set<int>::iterator it;
	int maximo=0;
	while(!nodos.empty()){
		it=nodos.begin();
		int este=*it;
		nodos.erase(it);
		int coun=0;
		queue<int> q;
		q.push(este);

		while(!q.empty()){
			int u=q.front();
			q.pop();
			if(visitados[u]){
				continue;
			}
			visitados[u]=1;
			nodos.erase(u);
			coun++;
			for(int k : mat[u]){
				if(!visitados[k]){

						q.push(k);
				}
			}
		}
		//cout << este << endl;
		maximo=max(maximo,coun);
	}
	cout <<maximo << endl;
	}
	return 0;
}
