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
int minpal(std::vector< std::vector<int> > &v,string &s,unsigned i, unsigned j){
	if(j < 0 || i >= s.size() || j < i){
		return 0;
	}
	if(i == j){
		return 1;
	}
	if(v[i][j]>=0){
		return v[i][j];
	}
	int pos = max(minpal(v, s, i+1, j), minpal(v, s, i, j-1));
	if (s[i] == s[j]) {
		pos = max(pos, 2 + minpal(v, s, i+1, j-1));
	}
	v[i][j] = pos;
	return v[i][j];
 
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin>>T;
	string s;
	while(T--)
	{
		cin >> s;
		std::vector< std::vector<int> > v(s.size(),std::vector<int> (s.size(),-1));
		cout << (s.size() - minpal(v,s,0,s.size() - 1)) << endl;
	}
	return 0;
}
