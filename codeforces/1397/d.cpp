#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define vpii vector<pii >
#define wgraph vector<vpii >
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
vi stones;
bool aux(int nu){
	for (int i = 0; i < stones.size(); ++i)
	{
		if (stones[i]>0 and i!=nu)
		{
			stones[i]-=1;
			if (!aux(i))
			{
				stones[i]+=1;
				return true;
			}
			stones[i]+=1;
		}
	}
	return false;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	for (int t = 0; t < T; t++)	{
		int n;
		cin >>  n;
		stones.assign(n,0);
		for (int i = 0; i < n; ++i)
		{
			cin >> stones[i];
		}
		cout << (aux(-1)?"T":"HL")<< endl;
	}
	return 0;
}
