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

int maxSub(std::vector<std::vector<int> > &v, string &a,string &b,unsigned i, unsigned j){

	if(a.size()<=i||b.size()<=j){
		return 0;
	}
	if(v[i][j]>=0){
		return v[i][j];

	}
	if(a[i]==b[j]){
		v[i][j]=max(1+maxSub(v,a,b,i+1,j+1),max(maxSub(v,a,b,i+1,j),maxSub(v,a,b,i,j+1)));
		return v[i][j];
	}else{
		v[i][j]=max(maxSub(v,a,b,i+1,j),maxSub(v,a,b,i,j+1));
		return v[i][j];
	}
}


int main()
{
	string a,b;
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(true){
		if (!getline(cin, a)) break;
		getline(cin, b);
		std::vector< std::vector<int> > v(a.size(),std::vector<int> (b.size(),-1));
		int mx = maxSub(v,a,b,0,0);
		cout << mx << "\n";
	}
	return 0;
}
