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
	int T;
	cin>>T;
	// cin.ignore(); must be there when using getline(cin, s)
	std::vector<int> v(T);
	int largo=100001;
	std::vector<long long> vals(largo,0);
	for (int i = 0; i < T; ++i)
	{
		cin >> v[i];
		vals[v[i]]+=v[i];
	}
	std::vector<long long> maxs(largo,0);
	maxs[1]=vals[1];
	for (int j = 2; j < largo; ++j)
	{
		maxs[j]=max(vals[j]+maxs[j-2],maxs[j-1]);
	}
	cout << maxs[largo-1] << endl;
	return 0;
}
