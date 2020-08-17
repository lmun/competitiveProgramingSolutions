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
#define vvll vector < vll >
#define vvvll vector < vvll >
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

vvvll vec;

vi re;
vi ge;
vi be;

ll auxi(int a, int b, int c) {
	if(vec[a][b][c]>=0){
		return vec[a][b][c];
	}
	ll res = 0;
	// cout << a<< '\''<< b<< '\''<< c<< '\''<< res <<'+' <<endl;
	if (a>0 and b> 0)
	{
		ll te = re[a-1]*ge[b-1] + auxi(a-1,b-1,c);
		if (te>res)
		{
			res = te;
		}
	}
	// cout << a<< '\''<< b<< '\''<< c<< '\''<< res <<'e' <<endl;
	if (a>0 and c> 0)
	{
		// cout << a<< '\''<< b<< '\''<< c<< '\''<< endl;
		// cout << be[c-1]*re[a-1] << '/'<<  auxi(a-1,b,c-1)<< endl;
		ll te = be[c-1]*re[a-1] + auxi(a-1,b,c-1);
		if (te>res)
		{
			res = te;
		}
	}
	// cout << a<< '\''<< b<< '\''<< c<< '\''<< res <<'r' <<endl;
	if (b>0 and c> 0)
	{
		ll te = be[c-1]*ge[b-1] + auxi(a,b-1,c-1);
		if (te>res)
		{
			res = te;
		}
	}
	vec[a][b][c] = res;
	// cout << res <<'-' <<endl;
	return vec[a][b][c];
}

int main() {
	std::ios::sync_with_stdio(false);
	int r, g, b;
	vec.assign(205,vvll(205,vll(205,-1)));
	cin >> r >> g >> b;
	// cin.ignore(); must be there when using getline(cin, s)
	re.assign(r,0);
	ge.assign(g,0);
	be.assign(b,0);
	for (int i = 0; i < r; ++i)
	{
		cin >> re[i];
	}
	for (int i = 0; i < g; ++i)
	{
		cin >> ge[i];
	}
	for (int i = 0; i < b; ++i)
	{
		cin >> be[i];
	}
	sort(re.begin(), re.end());
	sort(ge.begin(), ge.end());
	sort(be.begin(), be.end());
	// for (int i = 0; i < r; ++i)
	// {
	// 	cout << re[i] << '.';
	// }
	// cout << 4 << endl;
	cout << auxi(r,g,b) << endl;
	return 0;
}
