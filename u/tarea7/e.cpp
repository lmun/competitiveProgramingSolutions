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
	int n, r;
	int t=1;
	while(cin>>n){
		std::map<string, int> indi;
		std::vector<string> nombres(n);
		for (int i = 0; i < n; ++i){
			cin >> nombres[i];
			indi[nombres[i]] = i;
		}
		vvi G(n,vi(0));
		vi inci(n,0);
		vi printed(n,0);
		cin >> r;
		string a,b;
		for (int i = 0; i < r; ++i){
			cin >> a >> b;
			G[indi[a]].push_back(indi[b]);
			inci[indi[b]]++;
			//cout << a << endl << b << endl;
		}
		cout << "Case #" << t++ << ": Dilbert should drink beverages in this order:";
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				if(inci[j] == 0 && !printed[j]){
					cout << ' ' << nombres[j];
					printed[j]++;
					for (int u : G[j]){
						inci[u]--;
					}
					break;
				}
			}
		}
		cout << ".\n\n";
	}
	
	return 0;
}
