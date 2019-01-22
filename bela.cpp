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
int domi[300];
int notdomi[300];
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	char b;
	cin >> b;

	// cin.ignore(); must be there when using getline(cin, s)
	domi['A'] = notdomi['A']= 11;
	domi['K'] = notdomi['K']= 4;
	domi['Q'] = notdomi['Q']= 3;
	domi['J'] = 20;
	notdomi['J']= 2;
	domi['T'] = notdomi['T']= 10;
	domi['9'] = 14;
	t *= 4;
	ll tot = 0;
	while (t--) {
		string st;
		cin >> st;
		if (st[1] == b)
		{
			tot += domi[st[0]];
		} else {
			tot += notdomi[st[0]];
		}
	}
	cout << tot << endl;
	return 0;
}
