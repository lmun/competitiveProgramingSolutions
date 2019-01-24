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
ll mes[13]={0,0,31,59,90,120,151,181,212,243,273,304,334};
string dias[7]={"Monday","Tuesday", "Wednesday","Thursday","Friday", "Saturday" ,"Sunday"};
int main()
{
	std::ios::sync_with_stdio(false);
	int d,m;
	cin>>d>>m;
	int dia=d+mes[m]+2;
	dia%=7;
	cout << dias[dia] << endl;
	return 0;
}
