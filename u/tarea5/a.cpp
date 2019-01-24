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
	int n,m,k;
	cin>>n>>m>>k;
	// cin.ignore(); must be there when using getline(cin, s)
	std::vector<string> v(n);
	std::vector<std::vector<int> > graf(n*m,std::vector<int> ());
	for (int i = 0; i < n; ++i){
		cin >> v[i];
	}
	int ult=-1;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if(v[i][j]=='.'){
				ult=i*m+j;
				if(i > 0 && v[i-1][j]=='.'){
					graf[i*m+j].push_back((i-1)*m+j);
					graf[(i-1)*m+j].push_back(i*m+j);
				}if(i+1<n && v[i+1][j]=='.'){
					graf[i*m+j].push_back((i+1)*m+j);
					graf[(i+1)*m+j].push_back(i*m+j);
				}if(j>0 && v[i][j-1]=='.'){
					graf[i*m+j].push_back(i*m+j-1);
					graf[i*m+j-1].push_back(i*m+j);
				}if(j+1<m && v[i][j+1]=='.'){
					graf[i*m+j].push_back(i*m+j+1);
					graf[i*m+j+1].push_back(i*m+j);
				}
			}
		}
	}
	std::vector<int> visitado(n*m,0);
	stack<int> sta;
	queue<int> q;
	q.push(ult);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(visitado[u]>0){
			continue;
		}
		visitado[u]++;
		sta.push(u);
		for(int este : graf[u]){
			if(visitado[este]==0){
				q.push(este);
			}
		}
	}
	for (int i = 0; i < k; ++i){
		int p=sta.top();
		sta.pop();
		v[p/m][p%m]='X';
	}
	for (int i = 0; i < n; ++i){
		cout << v[i] << endl;
	}
	return 0;
}
