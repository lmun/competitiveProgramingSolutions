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
int t,n;
int p[2][4]={{1,-1,0,0},{0,0,1,-1}};
int esx(std::vector<string> &v,int i, int j){
	//printf("%d\t%d\n",i,j );
	if(i<0||j<0||j>=n||i>=n){
		return 0;
	}else if(v[i][j]=='x'){
		int res=1;
		v[i][j]='.';
		for (int k = 0; k < 4; ++k){
			res+=esx(v,i+p[0][k],j+p[1][k]);
		}
		return res;
	}else if(v[i][j]=='@'){
		v[i][j]='.';
		int res=0;
		for (int k = 0; k < 4; ++k){
			res+=esx(v,i+p[0][k],j+p[1][k]);
		}
		return res;
	}
	return 0;
}
int main(){
	std::ios::sync_with_stdio(false);
	
	cin>>t;
	for (int u = 1; u <=t; ++u){
		
		cin >> n;
		std::vector<string> v(n);
		for (int i = 0; i < n; ++i){
			cin >> v[i];
		}
		int res=0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(esx(v,i,j)>0){
					res++;
				}
			}
		}
		printf("Case %d: %d\n",u,res);
	}
	
	return 0;
}
