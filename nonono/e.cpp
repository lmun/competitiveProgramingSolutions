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
	// cin.ignore(); must be there when using getline(cin, s)
	int n, b, h, w;

	while(cin >> n >> b >> h >> w){
		std::vector<int> cap(w, 0);
		ll mini = inf;
		while(h--){
			ll p, co;
			cin >> p;
			bool sepuede = false;
			for (int i = 0; i < w; ++i){
				cin >> co;
				if (co > n)
				{
					sepuede = true;
				}
			}
			if(sepuede && n*p < b){
				mini = min(mini, n*p);
			}
		}
		// cout << (mini<inf?string(mini):"stay home") << endl;
		if (mini < inf){
			cout << mini << endl;
		}else{
			cout << "stay home\n";
		}
	}
	return 0;
}
