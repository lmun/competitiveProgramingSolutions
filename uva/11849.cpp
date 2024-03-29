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
int main()
{
	std::ios::sync_with_stdio(false);
	int n, m;
	
	// cin.ignore(); must be there when using getline(cin, s)
	while(cin >> n >> m){
		if (n == 0 && m == 0){
			break;
		}
		vi nn(n, 0);
		vi mm(m, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> nn[i];
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> mm[i];
		}
		int res = 0;
		int a = 0;
		int b = 0;
		while(a < n && b < m){
			if (nn[a] == mm[b]){
				res += 1;
				a++;
				b++;
			} else if (nn[a] < mm[b]) {
				a++;
			} else {
				b++;
			}
		}
		cout << res << endl;
	}
	return 0;
	
}
