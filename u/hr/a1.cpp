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
long long ways(int n,int m,std::vector<int> &v,std::vector< std::vector<long long> > &r){
	if(m<0){
		return 0;
	}
	if(r[n][m]>=0){
		return r[n][m]; 
	}
	long long res=ways(n,m-1,v,r);
	if(n==v[m]){
		res++;
	}
	if(n>v[m]){
		res+=(ways(n-v[m],m,v,r));
	}
	r[n][m]=res;
	return r[n][m];

}

int main()
{
	
	int n,m;
	cin>>n>>m;
	std::vector<int> v(m);
	std::vector< std::vector<long long > > resp(n+1,std::vector<long long> (m,-1));
	for (int i = 0; i < m; ++i)
	{
		cin >>v[i];
	}
	cout << ways(n,m-1,v,resp) << endl;
	while(cin>>n){
		cout << ways(n,m-1,v,resp) << endl;
	}
	return 0;
}
